/*
 * Assn4.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Brian
 */



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstddef>


using namespace std;
void vector_print_stats(vector<double>);

int main()
{
	double pi_digits_array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1};
	//double pi_digits_array[] = {0,1,2,3,4,5,5,6,7,8,9};

	vector<double> pi_digits;
	for (double *ptr = pi_digits_array; ptr != pi_digits_array+50; ++ptr)
		pi_digits.push_back(*ptr);


	vector_print_stats(pi_digits);

	return 0;
}


void vector_print_stats(vector<double> pi_digits)
{
	int length = pi_digits.size();

	cout<<"The vector length is "<<length<<endl;

	double sum = 0.0;

	cout<<"Printing vector components "<<endl;
	for(int i = 0;i < length; ++i)
	{
		cout<<pi_digits[i]<<endl;
		sum+=pi_digits[i];
	}

	double mean = sum/length;
	sort(pi_digits.begin(),pi_digits.end());
	double median;

	if (length%2==0)
	{
		int midpt1 = (length)/2;
		int midpt2 = midpt1+1;
		median = (pi_digits[midpt1]+pi_digits[midpt2])/2.0;
	}

	else
	{
		int midpt = (length)/2;
		median = pi_digits[midpt];
	}

	double mode;
	int tmp_cnt = 1,mode_cnt = 1;

	mode = *pi_digits.begin();

	for(int i = 0;i < length; ++i)
	{
		if (pi_digits[i] == pi_digits[i-1]){
			tmp_cnt+=1;
			if (tmp_cnt>mode_cnt){
				mode_cnt = tmp_cnt;
				mode = pi_digits[i];
			}
		}
		else if (pi_digits[i] != pi_digits[i-1]){
			tmp_cnt = 1;
			if (tmp_cnt>mode_cnt){
				mode_cnt = tmp_cnt;
				mode = pi_digits[i];
			}
		}
	}

	double sum_squared = 0.0,variance;

	for(int i = 0;i < length; ++i)
	{
		sum_squared += (pi_digits[i]-mean)*(pi_digits[i]-mean);
	}

	variance = sqrt(1.0/length*sum_squared);

	cout<<"The mean of the vector components is "<<mean<<endl;
	cout<<"The median of the vector components is "<<median<<endl;
	cout<<"The mode of the vector components is "<<mode<<endl;
	cout<<"The variance of the sample population is "<<variance<<endl;

}
