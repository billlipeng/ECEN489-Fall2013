/*
 * main.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: Zachary Partal
 */

#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;

// Pass in a double in farenheit, get out a double in celcius
double f2c (double f) {
	return (f - 32.0)*(5.0/9.0);
}

int main() {

	vector<double> tempvec; // stores the temperatures
	string in_temp = "";

	// Menu loop, exit with 4
	while(true) {

		// Instructional prompt
		cout << "Select an option: \n 1: enter temperatures \n 2: print size and contents of vector \n 3: convert and print temperatures in C \n 4: quit \n >> ";
		int option = 0;
		cin >> option;

		// menu cases
		switch(option) {
		case 1:
			cout << "Enter individual temperatures (F) followed by enter. Enter q to finish\n >>";
			while (cin >> in_temp) { // continually read input
				cout << ">>";
				if (in_temp == "q") break;
				double temp = atof(in_temp.c_str()); // convert string to cstring then convert to float
				tempvec.push_back(temp);
			}
			break;
		case 2:
			cout << "SIZE: " << tempvec.size() << endl << "VALUES: ";
			for (double i : tempvec) { // prints vector using for range feature of c++11
				cout << i << " ";
			}
			cout << endl;
			break;
		case 3:
			cout << "SIZE: " << tempvec.size() << endl << "VALUES IN C: ";
			for (double i : tempvec) { // prints out vector but runs each element through conversion function
				cout << f2c(i) << " ";
			}
			cout << endl;
			break;
		case 4:
			return 0;
		}
		cout << endl;
	}
	return 0;
}




