/*
 * operators.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Narayanan Rengaswamy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout; using std::endl;
using std::vector;
using std::max_element;
using std::sort;

int main() {

	double t = 0, mean = 0, var = 0, median = 0, mode = 0;

	vector<double> val, val2, temp{3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1};


	/*cout << "Enter values: " << endl;        //Remove comment of these lines when giving your own input
	while (cin >> t) {
		val.push_back(t);  //Add elements to the vector
	}*/


	val = temp;  //Comment this line when giving your own input i.e. when you remove the above lines of comment

	cout << "We have " << val.size() << " values!!" << endl;
	cout << endl << "The values are:" << endl;

	auto i = val.begin();

	while (i != val.end())
		cout << *i++ << " ";    //Print every data value

	cout << endl;

	sort(val.begin(),val.end());    //Data in ascending order

	val2.push_back(*(val.begin()));

	for (auto index = val.begin() + 1; index != val.end(); index++) {   //Unique data values

		if (*index != *(index - 1))
			val2.push_back(*index);
	}

	vector<int> cnt(val2.size(),0);  //Vector containing the freq. of each data value


	i = val.begin() + 1;

	cout << endl << "The sorted values are:" << endl;

	mean = *(i-1);
	cout << *(i-1) << " ";

	int iter = 0;
	++cnt[iter];

	while (i != val.end()) {
		mean += *i;             //Sum all data values
		if (*i == *(i-1))
			++cnt[iter];     //Find freq. of each data value
		else
			++cnt[++iter];

		cout << *i++ << " ";    //Print data values in ascending order
	}

	cout << endl;

	mean /= val.size();  //Arithmetic Mean


	i = val.begin();

	while (i != val.end())
		var += pow((*i++ - mean),2);

	var = sqrt(var/(val.size()-1));  //Unbiased Variance


	int mode_freq = *(cnt.begin());
	mode = val2[0];

	for (unsigned int ind = 0; ind != cnt.size(); ind++) {
		//cout << "Freq. of " << val2[ind] << " is " << cnt[ind] << endl;
		if (cnt[ind] > mode_freq) {
			mode_freq = cnt[ind];
			mode = val2[ind];              //Update mode every iteration if reqd.
		}
	}

	if ((val.size() % 2) != 0)         //Check if there are odd number of data values
		median = val[((val.size() + 1)/2) - 1];
	else
		median = (val[(val.size()/2) - 1] + val[((val.size()/2) + 1) - 1])/2;


	cout << endl << "The arithmetic mean is: " << mean << endl;
	cout << endl << "The median is: " << median << endl;
	cout << endl << "The mode is: " << mode << endl;
	cout << endl << "The unbiased variance is: " << var << endl;

}


