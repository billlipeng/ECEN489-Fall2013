#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

struct TemperatureData {
	private:
		string scale;
		int year;	
		double temperature;

	public:
		TemperatureData(string, double, int);
		void DisplayData();
};

TemperatureData::TemperatureData(string A, double B, int C) {
	scale = A;
	temperature = B;
	year = C;
}

void TemperatureData::DisplayData()
{
	if (scale == "F") {
		cout << "\nFarenheit: " << temperature;
		cout << "\nCelcius: " << ((temperature - 32) * 5 ) / 9;
		cout << "\nKelvin: " << (((temperature - 32) * 5 ) / 9 ) + 273;
	} else if (scale == "C") {
		cout << "\nFarenheit: " << (1.8 * temperature) + 32;
		cout << "\nCelcius: " << temperature;
		cout << "\nKelvin: " << temperature + 273;
	} else if (scale == "K") {
		cout << "\nFarenheit: " << ((temperature - 273) * 1.8) + 32;
		cout << "\nCelcius: " << temperature - 273;
		cout << "\nKelvin: " << temperature;
	} else {
		cout << "\nERROR, bad scale.";
		exit(1);
	}
}


int main () {
	// user input variables
	string scale = "";
	double temp = 0.0;
	int year = 0;

	cout << "Please give us some temperature data.\n";
	cout << "Input Scale (F = Fahrenheit, C = Celsius, K = Kelvin): ";
	cin >> scale;
	cout << "\nInput Temperature: ";
	cin >> temp;
	cout << "\nInput Year: ";
	cin >> year;
	TemperatureData DataPoint(scale, temp, year);

	cout << "Here is the temperature data you entered, but converted into different scales:\n";
	DataPoint.DisplayData();

	cin >> temp;	// Keep window open.
	return 0;
}
