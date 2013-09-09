
/// \file summary-stats.cc
///
/// Read an EOF-delimited input stream and output the sample mean, mode, median,
/// and unbiased variance.
///
/// The mean and variance can be done by Welford's method, which is an online
/// algorithm with constant storage requirements, which allow working with a
/// potentially infinite stream.
///
/// The best that can be done for median calculation is O(n log n) time and O(n)
/// space, by maintaining a max heap and a min heap to the left and right of the
/// running median, respectively.  This really precludes use on "infinite"
/// sequences, but them's the breaks.  However, we are lucky, and the C++ STL
/// has an nth_element algorithm that works by partition, with a linear time
/// guarantee.
///
/// Mode calculation is a doozy, especially if you need the true mode for
/// floating point numbers.  You need a frequency table, which in the
/// pathological case can be O(n) in size.  Use of a hash table can maintain
/// O(n) time, though (I believe).
///
/// With these considerations in mind, there is no reason to try to be
/// extra-elegant and do this in one pass on the input.  Rather, we just have to
/// read all input into a vector, then process it.

#include <iostream>
#include <vector> 

#include "welford.hh"
#include "mode.hh"

int main(int argc, char **argv)
{
    std::vector<double> elements;

    while(std::cin)
    {
        int cur_element = std::numeric_limits<double>::signaling_NaN();
        std::cin >> cur_element;

        // If the stream has had an error, we need to break reading.  Outside
        // the read loop, we will check if it is an EOF or a parse error.
        if(! std::cin)
        {
            break;
        }

        elements.push_back(cur_element);
    }

    // Check if we had a non-EOF stop on the stream.
    if(! std::cin.eof())
    {
        std::cerr << "Error at input element " << elements.size()
                  << "." << std::endl;
        return 1;
    }

    // Check that we received at least one input element.
    if(elements.size() == 0)
    {
        std::cerr << "Cannot take statistics of empty stream." << std::endl;
    }

    // Otherwise, compute the requested statistics.

    // Welford's method for mean and sample variance.
    double mean = std::numeric_limits<double>::signaling_NaN();
    double unbiased_variance = std::numeric_limits<double>::signaling_NaN();
    std::tie(mean, unbiased_variance)
        = welford_mu_s(begin(elements), end(elements));

    std::cout << "Sample Mean:\t" << mean
              << std::endl;
    std::cout << "Unbiased Sample Variance:\t" << unbiased_variance
              << std::endl;
    
    // std::nth_element for median.  However, this will destroy ordering of the
    // data, so it's not a great idea when you need to do further inference on
    // the data.
    if(elements.size() % 2 == 0)
    {
        // If we have an even number of elements, we need to get the two middle
        // elements, then average them.
        std::size_t right_offset = elements.size() / 2;
        std::size_t left_offset = right_offset - 1;
        std::nth_element(
            begin(elements),
            begin(elements) + left_offset,
            end(elements)
        );
        double left_element = *(begin(elements) + left_offset);
        std::nth_element(
            begin(elements),
            begin(elements) + right_offset,
            end(elements)
        );
        double right_element = *(begin(elements) + right_offset);
        
        std::cout << "Sample Median: " << ((left_element + right_element) / 2)
                  << std::endl;
    }
    else
    {
        std::size_t median_offset = elements.size() / 2;
        std::nth_element(
            begin(elements),
            begin(elements) + median_offset,
            end(elements)
        );

        std::cout << "Sample Median: " << *(begin(elements) + median_offset)
                  << std::endl;
    }

    // For mode, write a function that uses an unordered map to compile a
    // frequence table.
    double mode = mode_frequency_map(begin(elements), end(elements));
    std::cout << "Sample Mode: " << mode << std::endl;
}
