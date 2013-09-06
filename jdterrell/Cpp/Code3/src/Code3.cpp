//============================================================================
// Name        : assignment3.cpp
// Author      : Jeffery D. Terrell
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main ()
{

	vector<double> Ftemp;
	vector<double> Ctemp;

	double input = 0;

	cout << "Please enter a temperature value (Fahrenheit) and press enter. Repeat until you have entered all temperatures. "
			"Enter any non-numeric character when you are finished." << endl;

	while (1)		//infinite loop for user input (exit conditions defined in loop)
	{
		cin >> input;

		if(!cin)		//handle situation where input does not match type declared (double) -- input expects a numeric value
		{
			break;
		}
		else
		{
			Ftemp.push_back(input);
			Ctemp.push_back(input);
		}
	};


	for (double& i: Ctemp)		//perform conversion to celsius
		i = (i-32)/1.8;

	cout << "Number of Fahrenheit values: " << Ftemp.size() << endl;	//display size of vector 1

	for (double& i: Ftemp)												//display contents of vector 2
	{
		cout << i << endl;
	}

	cout << endl;
	cout << "Number of Celsius values: " << Ctemp.size() << endl;		//display size of vector 2

	for (double& i: Ctemp)												//display contents of vector 2
	{
		cout << i << endl;
	}

	return 0;
}
