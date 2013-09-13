#include <iostream>

using namespace std;

int main()
{
	double number1;
	double number2;

	//get first number
	cout<<"Please enter your first number"<<endl;
	cin >> number1;

	//get second number
	cout<<"Please enter your second number"<<endl;
	cin >> number2;
	
	// try catch block does not work, dividing by 0 does not throw an exception
	try
	{
		double result = number1/number2;
	}
	catch(exception e)
	{
		cout<<"Ouch you tried to divide by 0!!!!"<<endl; // this did not seem to work
	}

	// self check for errors
	if(number2 != 0)
		cout<<number1<<"/"<<number2<<" = "<<number1/number2<<endl;
	else 
		cout<<"Ouch you tried to divide by 0!!!!"<<endl;
}



