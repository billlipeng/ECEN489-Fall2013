#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	static const double pi[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3,
								5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 
								6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 
								9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 
								1, 6, 9, 3, 9, 9, 3, 7, 5, 1};
	vector<double> vec (pi, pi + sizeof(pi) / sizeof(pi[0]));				  
	double mean, median, mode, variance = 0.0;
	double modeArray[10] = {0.0};
	sort(vec.begin(), vec.end());
	
	// for loop to help calculate mean and mode
	for (int i = 0; i < vec.size(); ++i) {
		// total up all elements for mean
		mean = mean + vec[i]; 
		// increment mode array at that number's spot
		modeArray[(int)vec[i]] = modeArray[(int)vec[i]] + 1; 
	}
	
	// calculate mean
	mean = mean / vec.size();
	
	// calculate mode
	for (int i = 0; i < 10; ++i) {
		if (modeArray[(int)mode] < modeArray[i])
				mode = i;
	}
	
	// calculate variance
	double temp = 0.0; // temp variable
	for (int i = 0; i < vec.size(); ++i) {
		temp = temp + (pow(vec[i] - mean, 2.0));
	}
	variance = temp / vec.size();
	
	// calculate median
	if (vec.size() % 2)
		median = vec[(vec.size() + 1) / 2];
	else {
		median = (vec[vec.size() / 2] + vec[(vec.size() + 1) / 2]) / 2;  
	}
	
	// output info to console
	cout << "Welcome to the Statistics Program for the First 50\n"
		 <<	"Numbers in the Decimal Expansion of Pi!\n"
		 << "\nHere are those numbers:\n"; 
	for (int i = 0; i < 50; ++i) {
		if (!(i % 10))
			cout << endl;
		cout << pi[i] << " ";
	}
	cout << "\n\nHere are those numbers sorted:\n";
	for (int i = 0; i < vec.size(); ++i) {
		if (!(i % 10))
			cout << endl;
		cout << vec[i] << " ";
	}
	cout << "\n\nMean:\t\t" << mean;
	cout << "\nMedian:\t\t" << median;
	cout << "\nMode:\t\t" << mode;
	cout << "\nVariance:\t" << variance;
	
	return 0;
}