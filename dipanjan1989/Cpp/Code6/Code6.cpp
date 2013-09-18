//============================================================================
// Name        : Code6.cpp
// Author      : Dipanjan Saha
// Version     :
// Copyright   : Copyright Dipanjan
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

int** swap_pointer (int** p){
	int* temp;
	temp = p[1];
	p[1] = p[0];
	p[0] = temp;
	return p;
}

void swap_reference (int &r1, int &r2){
	int temp;
	temp = r2;
	r2 = r1;
	r1 = temp;
}

int main(int argc, char **argv) {


	if (argc < 3){
		cerr << "Sorry, you have not supplied two integers to run the code!!" << endl;
		cerr << "Please enter two integers as command line arguments!!" << endl;
	}

	cout << "The integers you have entered are: " << argv[1] << " " << argv[2] << endl;

	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);

	//Swapping using pointers
	cout << "Swapping the values by using pointers: ";
	int* a1 = &n1;
	int* a2 = &n2;
	int* a[] = {a1, a2};
	int** b = swap_pointer(a);
	cout << *b[0] << " " << *b[1] << endl;

	//Swapping using references
	cout << "Swapping the values by using references: ";
	int &ref1 = n1;
	int &ref2 = n2;
	swap_reference(ref1, ref2);
	cout << ref1 << " " << ref2 << endl << "Thank you!";
	return 0;
}
