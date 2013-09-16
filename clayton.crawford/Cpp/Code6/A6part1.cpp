#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	double *arg1ptr, *arg2ptr, *argTemp;
	double temparg1, temparg2, temp;
	
	if (argc != 3) {
		cout << "Please re-execute the program with two arguments!\n";
		return 0;
	}
	// retrieve arguments
	temparg1 = atof(argv[1]);
	arg1ptr = &temparg1;
	temparg2 = atof(argv[2]);
	arg2ptr = &temparg2;	
	cout <<"\nBefore the swap:\n";
	cout << "argv[1] = "<< *arg1ptr << " argv[2] = " << *arg2ptr << endl;	
	
	// swap arguments using pointers
	argTemp = &temp;
	*argTemp = *arg1ptr;
	*arg1ptr = *arg2ptr;
	*arg2ptr = *argTemp;
	cout << "\nAfter swap using pointers:\n";
	cout << "argv[1] = "<< *arg1ptr << " argv[2] = " << *arg2ptr << endl;
		
	return 0;
}