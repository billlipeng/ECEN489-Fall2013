#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double *arg1ptr, *arg2ptr, *argTemp;
	double temparg1, temparg2, temp;
	
	// retrieve arguments or get user input
	if (argc == 3) {
		temparg1 = atof(argv[1]);
		arg1ptr = &temparg1;
		temparg2 = atof(argv[2]);
		arg2ptr = &temparg2;
	}
	else if (argc == 2) {
		temparg1 = atof(argv[1]);
		arg1ptr = &temparg1;
		cout << "\nPlease input another number: ";
		cin >> temparg2;
		arg2ptr = &temparg2;
	}
	else if (argc == 1) {
		cout << "\nPlease input the first number: ";
		cin >> temparg1;
		cout << "\nPlease input the second number: ";
		cin >> temparg2;
		arg1ptr = &temparg1;
		arg2ptr = &temparg2;
	} else {
		cout << "Please re-execute the program with no more than two arguments!\n";
		return 0;
	}
	cout <<"\nBefore the swap:\n";
	cout << "num1 = "<< *arg1ptr << " | num2 = " << *arg2ptr << endl;	
	
	// swap arguments using pointers
	argTemp = &temp;
	*argTemp = *arg1ptr;
	*arg1ptr = *arg2ptr;
	*arg2ptr = *argTemp;
	cout << "\nAfter swap using pointers:\n";
	cout << "num1 = "<< *arg1ptr << " | num2 = " << *arg2ptr << endl;
		
	return 0;
}