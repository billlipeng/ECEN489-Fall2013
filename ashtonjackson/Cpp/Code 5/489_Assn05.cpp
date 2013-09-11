/*
 * 489_Assn05.cpp
 *
 *  Created on: Sep 10, 2013
 *      Author: ashton
 */

#include <iostream>
using namespace std;


double Divide_by_Zero(int Num1, int Num2) {
	if(Num2 == 0) {
		throw "Dividing by zero is not allowed.";
	}
	return Num1/Num2;
}

int main () {
	int Num1, Num2;
	cout << "Input two integers: ";
	cin >> Num1 >> Num2;

	while(1) {
		try {
			cout << "Result = " << (Divide_by_Zero(Num1, Num2)) << endl;
			break;
		}

		catch (const char* Warning) {
			cout << "Exception detected: "<< Warning << endl;
			cout << "Please input two valid integers: "<< endl;
			cin >> Num1 >> Num2;
			cout << endl;
		}
	}
	return 0;
}


