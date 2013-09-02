//============================================================================
// Name        : Code2.cpp
// Author      : Dipanjan Saha
// Version     :
// Copyright   : Copyright Dipanjan
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct TemperatureData{
		string scale = "Fahrenheit";
		double temperature;
		int year;
	};

int main() {

	TemperatureData record, record1, record2;
	cout << "Please enter the following fields:";
	cout << "\nPlease enter the temperature value in Fahrenheit:";
	cin >> record.temperature;
	cout << "Please enter the year:";
	cin >> record.year;


	cout << "The temperature in Fahrenheit is: " << record.temperature << endl;
	cout << "The temperature in Celsius is: " << 5* (record.temperature - 32) / 9 << endl;
	cout << "The temperature in Kelvin is: " << 5* (record.temperature - 32) / 9 - 273 << endl;


	cout << "\n Enter two values of temperature:";
	cout << "\n Enter the first value in Fahrenheit:";
	cin >> record1.temperature;
	cout <<"Enter the second value in Fahrenheit:";
	cin >> record2.temperature;

	if (record1.temperature >= record2.temperature)
		cout << "The larger value is: " << record1.temperature;
	else
		cout << "The larger value is: " << record2.temperature;

	return 0;
}

