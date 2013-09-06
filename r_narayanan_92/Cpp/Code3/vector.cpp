/*
 * vector.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: Narayanan Rengaswamy
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
    	temperature.push_back(t);
    }

    cout << "Size of vector is " << temperature.size() << endl;

    auto i = temperature.begin();

    cout << "Temperatures are (in Fahrenheit): " << endl;

    while (i!=temperature.end())
    	cout << temperature[i] << " ";

    cout << endl;

    for (double &v : temperature)
    	v = (5*(v-32))/9 ;

    cout << "Size of vector is " << temperature.size() << endl;

    cout << "Temperatures are (in Celsius): " << endl;

    while (i!=temperature.end())
        	cout << temperature[i] << " ";

        cout << endl;
}



