#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

//return the double value of a string
double StringToDouble(string s)
{
	stringstream ss(s);
	double d = 0;
	ss >> d;
	return d;
}

int main()
{
	//store user input
	vector<double> fahrenheitValues;
	//store final values
	vector<double> celsiusValues;

	cout<<"Please enter a Fahrenheit reading, and then press enter to store the value"<<endl
		<<"When you are finished enter anything but a number"<<endl;

	//becomes false when ";" is entered
	bool notFinished = true;
	double fahrenheitValue = 0;
	string fahrenheitString = "";

	while(notFinished)
	{
		//get user input
		cin >> fahrenheitString;
		//check for termination
		if(fahrenheitString == ";")
			notFinished = false;
		else
		{
			//convert to double
			fahrenheitValue = StringToDouble(fahrenheitString);
			//store double
			fahrenheitValues.push_back(fahrenheitValue);
		}
	}
	//if nothing was entered, just end the program
	if(fahrenheitValues.size() > 0)
		cout<<"In Celsius:"<<endl;
	//ranged for loop
	/*
	for(double d : fahrenheitValues)
	{
		celsiusValues.push_back((d - 32)*5/9);
		cout<<d<<" F = "<<celsiusValues[celsiusValues.size() - 1]<<" C"<<endl;
	}
	*/
	for(int i = 0; i < fahrenheitValues.size(); i++)
	{
		//store the celsius value
		celsiusValues.push_back((fahrenheitValues[i] - 32)*5/9);
		//output the celsius value
		cout<<fahrenheitValues[i]<<" F = "<<celsiusValues[celsiusValues.size() - 1]<<" C"<<endl;
	}


}
