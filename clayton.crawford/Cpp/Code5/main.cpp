#include <iostream>
using namespace std;

int main() {
	double dividend, divisor, quotient = 0.0;
	cout << "Welcome to this division program!\n";
	cout << "Please enter the dividend: ";
	cin >> dividend;
	try {
		cout << "\nPlease enter the divisor: ";
		cin >> divisor;
		if (divisor == 0)
			throw 0.0;
	} catch (double zero) {
		while (divisor == 0.0) {
			cout << "Divide by zero error!\n";
			cout << "Please enter a non-zero number for the divisor: ";
			cin >> divisor;
		}
	}
	quotient = dividend / divisor;
	cout << endl << dividend << " / " << divisor << " = " << quotient;
	return 0;
}