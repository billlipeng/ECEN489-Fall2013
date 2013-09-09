//============================================================================
// Name        : assignment4.cpp
// Author      : Jeffery D. Terrell
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;


//not my own template, reference: http://www.cplusplus.com/forum/beginner/92307/
//used to set up mode calculation
template <class Iter>
typename std::iterator_traits<Iter>::value_type
	Mode(Iter first, Iter last)
{
	typedef typename std::iterator_traits<Iter>::value_type type_t;

	std::vector<type_t> arr (first, last);

	std::sort(arr.begin(), arr.end() );

	type_t output = type_t();
	int final_frequency = 0;
	int local_frequency = 0;

	for (typename std::vector<type_t>::iterator it = arr.begin(); it != arr.end()-1; ++it)
	{
		if (*it == *(it+1)) local_frequency++;
		else                local_frequency = 0;

		if (local_frequency > final_frequency)
		{
			final_frequency = local_frequency;
			output = *it;
		}
	}

	return output;
}


int main() {

	double sum_of_elements = 0;
	double sum = 0;
	double mean = 0;
	double median = 0;
	double mode = 0;
	double variance = 0;
	double input = 0;

	// Import File & Check if read
	ifstream myfile("pi.txt",ios::in);

	if (!myfile)
	{
		cerr << "File not Read"<< endl;
		return -1;
	}


	vector<double> vec;

	//import .txt into vector

	while (myfile >> input)	{
		vec.push_back(input);
	}

	cout << "i " << "vec[i]" << endl;
	cout << "---------" << endl;

	for (unsigned int i = 0; i < vec.size(); i++)	{
		cout << i << "  " << vec[i] << endl;
	}

	cout << endl;

	//Arithmetic Mean

	for (double& n : vec)	{
			sum_of_elements += n;
		};

		mean = sum_of_elements/vec.size();

	//Median
	sort(vec.begin(), vec.end());

	  if (vec.size()  % 2 == 0) {
	      median = (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2;
	  }
	  else	{
	      median = vec[vec.size() / 2];
	  }

	//Mode
		 mode = Mode(vec.begin(), vec.end());


	//Unbiased Sample Variance
	  for(unsigned int k=1; k < vec.size(); k++)	{
		  sum = vec[k]-mean;
		  sum = sum * sum;
	  }

	  variance = sum/(vec.size()-1);
	  variance = sqrt(variance);


	  //display results
	  cout << "Mean:" << mean << endl;
	  cout << "Median: " << median << endl;
	  cout << "Mode: " << mode << endl;
	  cout << "Unbiased Sample Variance: " << variance << endl;

	//end
	return 0;
}

