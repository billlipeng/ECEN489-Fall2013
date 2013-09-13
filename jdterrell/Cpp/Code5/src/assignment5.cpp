//============================================================================
// Name        : assignment5.cpp
// Author      : Jeffery D. Terrell
//============================================================================

#include <iostream>
#include <conio.h>
using namespace std;



int main() {

	int a = 0;
	int b = 0;
	int c = 0;
	char select;

	while (true) { //This repeats the program. You close console window manually by clicking "x".

		cin.clear(); //this will clear any values remain in cin from prior run

		cout << "Enter an integer: ";
		cin >> a;
		cout << "Enter another integer: ";
		cin >> b;

		try
		{
			if(b != 0)
			{
				c = a / b;
				cout << a << " / " << b << " = " << c << endl;
				break;
			}
			else
			{
//				cout << endl;
				throw (b);
			}
		}
		catch(...)
		{
			cerr << "ERROR: Cannot divide by zero! \n";
			cerr << "Try again? [Y/N]: ";
			cin >> select;

			if (select == 'N')	{
				break;
			}

		}

	} // this ends while loop

	return 0;
}
