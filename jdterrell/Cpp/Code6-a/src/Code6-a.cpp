//============================================================================
// Name        : Code6-a.cpp
// Author      : Jeffery D. Terrell
//============================================================================

#include <iostream>
using namespace std;

void p_swap(int *num1, int *num2);

int main(int argc, char *argv[]) {

	int a = 26;
	int b = 13;


	 cout << "Original: " << endl << "a = " << a << endl;
	 cout << "b = " << b << endl;
	 p_swap(&a, &b);    //pass the addresses
	 cout << "Swapped: " << endl << "a = " << a << endl;
	 cout << "b = " << b << endl;



	return 0;
}

void p_swap(int *num1, int *num2)    // receiving addresses not values
{
     int temp;    // temporary holding variable

     temp = *num1;    // swap the values stored at the addresses
     *num1 = *num2;
     *num2 = temp;

     return;     // main( )'s variables, not copies of them, have been changed
}
