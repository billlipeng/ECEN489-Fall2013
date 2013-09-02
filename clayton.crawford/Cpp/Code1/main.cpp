#include <iostream>
using namespace std;

int main () {
	// num1 and num2 are the numbers to be added
	double num1, num2 = 0.0;

	cout << "Welcome to this addition program!";
	cout << "\nPlease enter the first addend: ";
	cin >> num1;
	cout << "\nPlease enter the second addend: ";
	cin >> num2;
	cout << endl << num1 << " + " << num2 << " = " << num1 + num2;
	return 0;
}
