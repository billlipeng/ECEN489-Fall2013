//============================================================================
// Name        : Code5.cpp
// Author      : Dipanjan Saha
// Version     :
// Copyright   : Copyright Dipanjan
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {

	int a = 0, b = 0;
	//taking two integers as input

	cout << "Howdy!! This program takes two integers 'a' and 'b' and computes 'a/b'!" << endl;
	cout << "Please enter the dividend and the divisor separated by a white space: ";

	while (cin >> a >> b) {

		try {
			if (b != 0){
				cout << "\nGood entries; the quotient is: " << a/b << endl;
				cout << "\nWant to enter another set? Enter 'y' for yes; 'n' for no! Mind it - only 'y' or 'n', not a number!!:  ";
				char c;
				cin >> c;
				if (c == 'y')
					cout << "\nPlease enter the dividend and the divisor separated by a white space: ";
				else{
					cout << "\nO-o! Thanks and Gig'em!!";
					break;
				}
			}
			else
				throw runtime_error("\nThe divisor must be non-zero!!");

		}

		catch (runtime_error& err){
			cout << err.what() << "\nTry again? Enter y for yes; n for no! Mind it - 'y' or 'n', not any number!!: ";
			char c;
			cin >> c;
			if (c == 'y')
				cout << "\nPlease enter the dividend and the divisor separated by a white space: ";
			else{
				cout << "\nNO?? O-o! Thanks and Gig'em!!";
				break;
			}

		}
	}

	return 0;
}
