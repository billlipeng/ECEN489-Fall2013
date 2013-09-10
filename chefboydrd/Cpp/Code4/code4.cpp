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
	double mean = 0.0;
	double median = 0.0;
	double mode = 0.0;
	double temp = 0.0;
	double variance = 0.0;

	vector<int> modeVec(10);
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < vec.size(); ++i) {
		mean += vec[i]; 
		modeVec[(int)vec[i]] = modeVec[(int)vec[i]] + 1; 
	}
	
	// calculate mean
	mean /= vec.size();
	
	// calculate mode
	for (int i = 0; i < vec.size(); i++) 
	{
		modeVec[vec[i]]++;
	}
	for (int i = 0; i < 10; i++) 
	{
		int temp = 0;
		if (modeVec[i] > temp)
		{
			mode = i;
		}
	}

	// calculate variance
	for (int i = 0; i < vec.size(); ++i) 
	{
		temp = temp + (pow(vec[i] - mean, 2.0));
	}
	variance = temp / vec.size();
	
	// calculate median
	if (vec.size() % 2 == 0)	//even sized vector
	{
		median = ((vec[(vec.size()/2)+1] - vec[(vec.size()/2)]) + vec[(vec.size()/2)]);
	}
	else	//odd sized vector
	{
		median = vec[((vec.size()-1)/2)+1];
	}
	
	cout << "Value \t| Number of hits";
	cout << "\n======================\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t|\t" << modeVec[i] << endl;
	}

	cout << "\n\nMean:\t\t" << mean;
	cout << "\nMedian:\t\t" << median;
	cout << "\nMode:\t\t" << mode;
	cout << "\nVariance:\t" << variance;
	
	return 0;
}