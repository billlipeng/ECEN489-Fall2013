#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct TemperatureData {
	private:
		string scale;		// temperature scale
		double temperature;	// temperature
		int year;			// year of temperature
	public:
		TemperatureData(string, double, int);	// constructor

		// the following functions return the value of the members of TemperatureData
		string getScale() 	{ return scale; }
		double getTemp() 	{ return temperature; }
		int getYear() 		{ return year; }

};

TemperatureData::TemperatureData(string sc, double temp, int yr) {
	scale = sc;
	temperature = temp;
	year = yr;
}

// temperatureConversion() function declaration
void temperatureConversion(string, double, vector<double> &);

int main () {
	// user input variables
	string scale = "";
	double temp = 0.0;
	int year = 0;

	// vector to hold the temperature in three scales
	// [0] = Fahrenheit, [1] = Celsius, [2] = Kelvin
	vector<double> tempScales(3);
	cout << "Welcome to the Temperature Data Program\n";
	cout << "Input Scale (F = Fahrenheit, C = Celsius, K = Kelvin): ";
	cin >> scale;
	cout << "\nInput Temperature: ";
	cin >> temp;
	cout << "\nInput Year: ";
	cin >> year;
	TemperatureData tempData(scale, temp, year);
	temperatureConversion(scale, temp, tempScales);
	cout << "Here is the temperature in three scales for a day in the year "
		 << tempData.getYear() << ":\n";
	cout << "Fahrenheit = " << tempScales[0];
	cout << "\nCelsius = " << tempScales[1];
	cout << "\nKelvin = " << tempScales[2];

	return 0;
}

// temperatureConversion() converts the user input temperature into the other two scales
void temperatureConversion(string scale, double temp, vector<double> &tempScales) {
	if (scale == "F") {
		tempScales[0] = temp;
		tempScales[1] = ((temp - 32) * 5 ) / 9;
		tempScales[2] = tempScales[1] + 273;
	} else if (scale == "C") {
		tempScales[0] = (1.8 * temp) + 32;
		tempScales[1] = temp;
		tempScales[2] = temp + 273;
	} else if (scale == "K") {
		tempScales[0] = ((temp - 273) * 1.8) + 32;
		tempScales[1] = temp - 273;
		tempScales[2] = temp;
	} else {
		cout << "\nERROR: Wrong scale format!\n";
		exit(1);
	}
}
