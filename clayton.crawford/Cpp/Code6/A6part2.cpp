#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void swapArgs(double &arg1, double &arg2) {
	double temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

int main(int argc, char *argv[]) {
	double arg1, arg2;
	double *temp;
	// retrieve arguments or get user input
	if (argc == 3) {
		arg1 = atof(argv[1]);
		arg2 = atof(argv[2]);
	}
	else if (argc == 2) {
		arg1 = atof(argv[1]);
		cout << "\nPlease input another number: ";
		cin >> arg2;
	}
	else if (argc == 1) {
		cout << "\nPlease input the first number: ";
		cin >> arg1;
		cout << "\nPlease input the second number: ";
		cin >> arg2;
	} else {
		cout << "Please re-execute the program with no more than two arguments!\n";
		return 0;
	}
	cout <<"\nBefore the swap:\n";
	cout << "num1 = "<< arg1 << " | num2 = " << arg2 << endl;	
	
	// swap arguments using references
	swapArgs(arg1, arg2);
	cout << "\nAfter swap using references:\n";
	cout << "num1 = "<< arg1 << " | num2 = " << arg2<< endl;
	return 0;
}