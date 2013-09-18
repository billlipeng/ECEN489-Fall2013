#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double *A, *B, *tempVal;
	double tempVal1, tempVal2, temp;
	
	// get input
	if (argc == 3) {
		tempVal1 = atof(argv[1]);
		A = &tempVal1;
		tempVal2 = atof(argv[2]);
		B = &tempVal2;
	}
	else if (argc == 2) {
		tempVal1 = atof(argv[1]);
		A = &tempVal1;
		cout << "\nGimme another number!: ";
		cin >> tempVal2;
		B = &tempVal2;
	}
	else if (argc == 1) {
		cout << "\nPlease input the first number: ";
		cin >> tempVal1;
		cout << "\nPlease input the second number: ";
		cin >> tempVal2;
		A = &tempVal1;
		B = &tempVal2;
	} else {
		cout << "Please re-execute the program with no more than two arguments!\n";
		return 0;
	}
	cout <<"\nThis is what you gave me:\n";
	cout << "A = "<< *A << "\nB = " << *B << endl;	
	
	// swap arguments using pointers
	tempVal = &temp;
	*tempVal = *A;
	*A = *B;
	*B = *tempVal;
	cout << "\nHere, I have swapped your numbers for you:\n";
	cout << "A = "<< *A << "\nB = " << *B << endl;
	
	// This line keeps the window open on my stupid computer
	cin >> temp;
	return 0;
}