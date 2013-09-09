
#ifndef WELFORD_HH
#define WELFORD_HH

#include <iterator>
#include <tuple>

template<class InputIterator>
auto welford_mu_s(
    InputIterator first,
    InputIterator last
)
    -> std::tuple<
        typename std::iterator_traits<InputIterator>::value_type,
        typename std::iterator_traits<InputIterator>::value_type
        >
{
    typedef
        typename std::iterator_traits<InputIterator>::value_type
        value_type;
    
    value_type n = 0;
    value_type mean = 0;
    value_type m2 = 0;

    for(; first != last; ++first)
    {
        n += 1;
        
        value_type delta = (*first) - mean;
        mean = mean + delta / n;
        m2 = m2 + delta * ((*first) - mean);
    }

    double variance = m2 / (n - 1);

    return std::make_tuple(mean, variance);
}

#endif
