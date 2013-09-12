/*
 * exceptions.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: Narayanan Rengaswamy
 */


#include <iostream>

using std::cin;  using std::cout;  using std::cerr;  using std::endl;

int main() {

	int proper_input = 0, a = 0, b = 0;

	while (proper_input == 0) {

		cout << "Give the first integer (numerator): ";
		cin >> a;
		cout << "Give the second integer (denominator): ";
		cin >> b;

		try {
			if (b != 0) {
				proper_input = 1;
				cout << "The result of dividing " << a << " by " << b << " is " << (a/b) << endl;
			} else
				throw "Divide by zero!!";

		} catch (const char* msg) {
			proper_input = 0;
			cerr << msg << endl;
			cout << "Give the new input values." << endl;

		}

	}

}


