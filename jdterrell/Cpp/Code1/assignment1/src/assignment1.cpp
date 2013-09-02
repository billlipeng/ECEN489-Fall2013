//============================================================================
// Name        : assignment1.cpp
// Author      : Jeffery D. Terrell
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a=0; int b=0; int c=0;
	cout << "Enter first number (integer): " << endl;
	cin >> a;
	cout << "Enter first number (integer): " << endl;
	cin >> b;

	c=a+b;

	cout << a << " + " << b << " = " << c << endl;

	std::cin.get();

	return 0;
}
