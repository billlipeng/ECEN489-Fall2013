/*
Zachary Partal
ECEN 489 HW 5
9/13/2013
*/

#include <iostream>

using namespace std;

// Custom Exception Class
class divzeroexception: public exception
{
  virtual const char* what() const throw()
  {
    return "ERROR: Division by zero";
  }
} zero_exc;


int main() {
	cout << "Enter two integers seperated by a space then press enter." << endl << ">> ";
	int a = 0;
	int b = 1;

	cin >> a >> b;

	// Try block tests for 0 in b
	try {
		if (b==0) {
			throw (zero_exc);
		}
		cout << a << '/' << b << '=' << a/b << endl;
	}
	// Will catch thrown exception and print exception message
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

