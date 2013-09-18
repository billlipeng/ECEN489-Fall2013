//============================================================================
// Name        : Code6-b.cpp
// Author      : Jeffery D. Terrell
//============================================================================

#include <iostream>
using namespace std;

void swap(int &num1, int &num2);

int main(int argc, char *argv[])
{
     int a=26;
     int b=13;

	 cout << "Original: " << endl << "a = " << a << endl;
	 cout << "b = " << b << endl;

	 swap(a, b);    //pass the addresses
	 cout << "Swapped: " << endl << "a = " << a << endl;
	 cout << "b = " << b << endl;
}


void swap(int &num1, int &num2)    // receiving addresses not values
{
     int temp;     // temporary holding variable

     temp = num1;
     num1 = num2;
     num2 = temp;

     return;     // main( )'s variables, not copies of them, have been changed
}
