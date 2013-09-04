#include <iostream>

using namespace std;

int main () {
	double A, B = 0;

	cout << "Gimme the first number to add: ";
	cin >> A;
	cout << "\nGimme the second number: ";
	cin >> B;
	cout << endl << A << " + " << B << " = " << A + B << endl;
	cout << "Enter any key to exit.\n";
	cin >> A;
	return 0;
}
