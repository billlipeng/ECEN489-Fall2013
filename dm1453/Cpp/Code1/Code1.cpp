#include <iostream>
using namespace std;

int main ()
{
    int num1;  		// Stores an integer value of first number
    int num2;		// Stores an integer value of second number
    int sum;      // calculated value (sum of the integer values)
	
	cout << "Let's add two numbers!" << endl;
	cout << endl << "Enter first number: ";
	cin >> num1;
	cout << endl << "Enter second number: ";
	cin >> num2;
    sum = num1 + num2;            
    cout << endl << sum << " is the sum!"; 

    return 0;
}
