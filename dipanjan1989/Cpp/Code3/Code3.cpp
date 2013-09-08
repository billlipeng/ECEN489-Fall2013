//============================================================================
// Name        : Code3.cpp
// Author      : Dipanjan Saha
// Version     :
// Copyright   : Copyright Dipanjan
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	// defining a temperature vector
	double temp;
	vector<double> tempVec;

	// taking fahrenheit readings
	cout << "Enter temperature values in Fahrenheit. Put either a space or a newline in between two values.";
	cout << "\nPut some non-number to indicate that you are done. Go ahead!!::" << endl;
	while (cin >> temp){
		tempVec.push_back(temp);
	}

	// displaying the size of the vector
	cout << "The number of Fahrenheit readings you have entered is: " << tempVec.size();

	// displaying the elements of the vector and changing to Celsius
	cout << "\nThe readings you have entered are:\n";

	for (auto &j : tempVec){
		cout << j << " ";
		j = (5 * (j-32)) / 9;
	}


	// displaying the size the Celsius points
	cout << "\nThe readings have been converted to Celsius!";
	cout << "\nThe number of Celsius readings generated is: " << tempVec.size();
	cout << "\nThe corresponding Celsius readings are:\n";


	for (double &j : tempVec)
		cout << j << " ";

	return 0;
}

