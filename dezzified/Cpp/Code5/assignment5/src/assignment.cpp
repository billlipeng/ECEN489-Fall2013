//============================================================================
// Name        : assignment.cpp
// Author      : Desmond Uzor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
int main() {
	int first_number, second_number;
	cout << "Enter two Integers" << endl; // prints !!!Hello World!!!
	cin >> first_number >> second_number;
	try {

		if (second_number == 0)
			throw "second number can't be zero";
		else
			cout << "The division of the two numbers is "<< first_number/second_number << endl;
	}
	catch(const char* except){
		cerr << except;
	}
	return 0;
}
