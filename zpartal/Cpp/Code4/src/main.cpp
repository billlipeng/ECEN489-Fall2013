/*
 * main.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: Zachary Partal
 */


#include <iostream>
#include <vector>
#include "stdlib.h"
#include <sstream>
#include <algorithm>

using namespace std;

// Returns the mean of a vector of doubles
double mean(vector<double> v) {
	double mean = 0;
	for (int i = 0; i < v.size(); i++) {
		mean += v[i];
	}
	return mean/v.size();
}

// Returns the median of a vector of doubles
double median(vector<double> v) {
	vector<double> sorted = v;
	sort(sorted.begin(), sorted.end());

	if (sorted.size() % 2 == 0) {	// even case
		int mid = sorted.size()/2;
		double med = (sorted[mid] + sorted[mid-1])/2;
		return med;
	}
	else {	// odd case
		return sorted[sorted.size()/2];
	}
}

// Returns the mode of a vector of doubles
double mode(vector<double> v) {
	vector<int> frequency(10);
	for (int i = 0; i < v.size(); i++) {
		frequency[v[i]] += 1; // increments corresponding "slot" by one
	}

	int mode_num = 0;
	int mode_val = 0;

	for (int i = 0; i < frequency.size(); i++) {
		if (frequency[i] > mode_val) {
			mode_val = frequency[i];
			mode_num = i;
		}
	}

	return mode_num;
}

// Returns the sample variance of a vector of doubles
double sampvar(vector<double> v) {
	double input_mean = mean(v);
	vector<double> working_vec = v;
	double sample_var = 0;
	for (int i = 0; i < working_vec.size(); i++) {
		sample_var += (working_vec[i]-input_mean)*(working_vec[i]-input_mean);
	}
	return sample_var/(working_vec.size()-1);
}

int main() {

	vector<double> vec;

	// Generate input
	string pi = "3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5 0 2 8 8 4 1 9 7 1 6 9 3 9 9 3 7 5 1";
	stringstream ss(pi);
	double num;
	while (ss >> num) vec.push_back(num);

	// Print contents of vector
	cout << "VALUES IN VEC: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << endl;

	// Print mean, median, mode, and sample variance
	cout << "MEAN: " << mean(vec) << " MEDIAN: " << median(vec) << " MODE: " << mode(vec) << " SAMPLE VARIANCE: " << sampvar(vec) << endl;

	return 0;
}

