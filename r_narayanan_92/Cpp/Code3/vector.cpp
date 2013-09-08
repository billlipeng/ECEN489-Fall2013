/*
 * vector.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: Narayanan Rengaswamy
 *
 *      To take Fahrenheit temperatures as input and store it in a vector.
 *      Then display the size and contents of the vector
 *      Convert all temperatures into Celsius using range-for loop
 *      Then display the size and contents of the modified vector
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout; using std::endl;
using std::vector;

int main() {

	double t = 0;
	vector<double> temperature;


	cout << "Enter temperatures in Fahrenheit: " << endl;

	while (cin >> t) {
		temperature.push_back(t);  //Add elements to the vector
	}

	cout << "Size of vector is " << temperature.size() << endl;

	cout << "Temperatures are (in Fahrenheit): " << endl;

	decltype(temperature.size()) i = 0;  //Creating 'i' with the same type as temperature.size()

	while (i != temperature.size()) {
		cout << temperature[i] << " ";
		++i;
	}


	cout << endl;

	for (double &v : temperature)
		v = (5*(v-32))/9;

	cout << "\nSize of vector is " << temperature.size() << endl;

	cout << "Temperatures are (in Celsius): " << endl;

	i = 0;
	while (i != temperature.size()) {
		cout << temperature[i] << " ";
		++i;
	}
}



