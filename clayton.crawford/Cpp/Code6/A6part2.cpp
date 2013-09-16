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
	if (argc != 3) {
		cout << "Please re-execute the program with two arguments!\n";
		return 0;
	}
	// retrieve arguments
	arg1 = atof(argv[1]);
	arg2 = atof(argv[2]);
	cout <<"\nBefore the swap:\n";
	cout << "argv[1] = "<< arg1 << " argv[2] = " << arg2 << endl;	
	
	// swap arguments using references
	swapArgs(arg1, arg2);
	cout << "\nAfter swap using references:\n";
	cout << "argv[1] = "<< arg1 << " argv[2] = " << arg2<< endl;
		
	return 0;
}