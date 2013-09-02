/*
 * 1.cpp

 *
 *  Created on: Aug 30, 2013
 *      Author: samcarey
 */

#include <iostream>
#include <string>

using namespace std;

struct TemperatureData{
	TemperatureData(string s, double t, int y)
	{
		scale = s;
		temperature = t;
		year = y;

		if (scale == "Fahrenheit"){
			temperature = (temperature-32)*5/9;
			scale = "Celsius";
		}
		if (scale == "Kelvin"){
					temperature = (temperature-273.15);
					scale = "Celsius";
		}
	}
	string scale;
	double temperature;
	int year;
};

int main()
{
	string scale;
	double temperature;
	int year;

	while (true){
		cout << "scale: " << flush;
		cin >> scale;
		if (!cin || !(scale == "Fahrenheit" || scale == "Celsius" || scale == "Kelvin")){
			cout << "please enter Fahrenheit, Celsius, or Kelvin" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}else break;
	}

	while(1){
		cout << "temperature: " << flush;
		cin >> temperature;
		if (!cin){
			cout << "please enter number" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}else break;
	}

	while(1){
		cout <<  "year: " << flush;
		cin >> year;
		if (!cin){
			cout << "please enter an integer" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}else break;
	}

	TemperatureData temp1(scale, temperature, year);

	cout << "year: " << temp1.year << endl;
	cout << "temperature: " << endl;
	cout << "\tFarhenheit: " << (temp1.temperature*9/5)+32 << endl;
	cout << "\tCelcius:    " << temp1.temperature << endl;
	cout << "\tKelvin:     " << temp1.temperature+273.15 << endl;
	cout << endl << "Thanks and Gig 'em!" << endl;

	return 0;
}
