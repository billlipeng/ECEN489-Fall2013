//============================================================================
// Name        : Code4.cpp
// Author      : Dipanjan Saha
// Version     :
// Copyright   : Copyright Dipanjan
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	//creating the vector
	vector<double> pi = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1};
	cout << "The size of vector pi is: " << pi.size() << endl;
	cout << "The elements in this vector are:" << endl;

	//printing the elements using increment operator
	for (unsigned index = 0; index < pi.size(); index++)
		cout << pi[index] << " ";

	cout << endl;

	//finding the arithmetic mean
	double sum = 0, mean = 0;
	for (unsigned index = 0; index < pi.size(); index++)
		sum = sum + pi[index];
	mean = sum / double(pi.size());
	cout << "The sample mean is: " << mean << endl;

	//finding the unbiased variance
	double var = 0;
	for (unsigned index = 0; index < pi.size(); index++)
			var = var + (pi[index] - mean) * (pi[index] - mean);
	var = var / double(pi.size());

	cout << "The unbiased sample variance is: " << var << endl;

	//finding the sample median
	double k = 0;
	for (unsigned index = 0; index < pi.size()-1 ; index++){
		for (unsigned curr = 0; curr < pi.size()-1-index; curr++){
			if (pi[curr] > pi[curr+1]){
				k = pi[curr+1];
				pi[curr+1] = pi[curr];
				pi[curr] = k;
			}
		}
	}

	cout << endl;
	cout << "The sorted vector is:" << endl;
	for (unsigned index = 0; index < pi.size(); index++)
			cout << pi[index] << " ";

	cout << "\nThe sample median is: " << (pi[pi.size()/2] + pi[pi.size()/2 - 1])/2 << endl;

	//finding the mode
	int max_old = 1;
	int max_new = 1;
	double mode = 0;

	for (unsigned i = 0; i < pi.size()-1; i++){

		if (pi[i+1] == pi[i])
			max_new = max_new + 1;
		else{
			if (max_new > max_old){
				max_old = max_new;
				mode = pi[i];
			}
		}
	}

	cout << "The sample mode is: " << mode << endl;

	return 0;
}
