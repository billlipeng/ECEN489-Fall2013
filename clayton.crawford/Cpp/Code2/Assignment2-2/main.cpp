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

	// vectors to hold the temperature in three scales
	// [0] = Fahrenheit, [1] = Celsius, [2] = Kelvin
	vector<double> tempScales1(3);
	vector<double> tempScales2(3);
	vector<double> highestTempsScales(3);

	TemperatureData *tempData;
	cout << "Welcome to the Temperature Comparison Program!\n";
	for (int i = 0; i < 2; ++i) {
		cout << "\n********** Temperature Data #" << i + 1 << " **********";
		cout << "\nInput Scale (F = Fahrenheit, C = Celsius, K = Kelvin): ";
		cin >> scale;
		cout << "\nInput Temperature: ";
		cin >> temp;
		cout << "\nInput Year: ";
		cin >> year;
		tempData = new TemperatureData(scale, temp, year);
		// if i = 0, then use tempScales1 for the first TemperatureData object
		// if i = 1, then use tempScales2 for the second TemperatureData object
		if (i == 0)
			temperatureConversion(scale, temp, tempScales1);
		else temperatureConversion(scale, temp, tempScales2);
	}

	if (tempScales1[0] > tempScales2[0]) {
		highestTempsScales = tempScales1;
		cout << "\nThe First Temperature Data Was the Highest!\n";
	} else {
		highestTempsScales = tempScales2;
		cout << "\nThe Second Temperature Data Was the Highest!\n";
	}
	cout << "Fahrenheit = " << highestTempsScales[0];
	cout << "\nCelsius = " << highestTempsScales[1];
	cout << "\nKelvin = " << highestTempsScales[2];

	delete tempData; // clean up memory
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
