#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct TemperatureData {
	private:
		string scale;
		int year;	
		double temperature;

	public:
		TemperatureData(string, double, int);
		void DisplayData();
		string GetScale()		{ return scale;}
		int GetYear()			{ return year;}
		double GetTemperature()	{ return temperature;}
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

int findMaxDataPoint(vector<TemperatureData>&);

int main () {
	// user input variables
	string scale = "";
	double temp = 0.0;
	int year = 0;

	vector<TemperatureData> DataPoint;

	cout << "Please give us your first temperature data.\n";
	cout << "Input Scale (F = Fahrenheit, C = Celsius, K = Kelvin): ";
	cin >> scale;
	cout << "\nInput Temperature: ";
	cin >> temp;
	cout << "\nInput Year: ";
	cin >> year;

	DataPoint.push_back(TemperatureData(scale, temp, year));

	cout << "Please give us your second temperature data.\n";
	cout << "Input Scale (F = Fahrenheit, C = Celsius, K = Kelvin): ";
	cin >> scale;
	cout << "\nInput Temperature: ";
	cin >> temp;
	cout << "\nInput Year: ";
	cin >> year;
	
	DataPoint.push_back(TemperatureData(scale, temp, year));

	int MaxDataIndex = findMaxDataPoint(DataPoint);

	cout << "Here is the higher data point:\n";
	DataPoint[MaxDataIndex].DisplayData();

	cin >> temp;	// Keep window open.
	return 0;
}

int findMaxDataPoint(vector<TemperatureData> & Data)
{
	int MaxIndex = 0;
	double temp, kelvin, MaxKelvin = 0.0;
	string scale = "";

	for (int i = 0; i < sizeof(Data); i++)
	{
		temp = Data[i].GetTemperature();
		scale = Data[i].GetScale();

		if (scale == "K")
		{
			kelvin = temp;
		}
		else if (scale == "F")
		{
			kelvin = ((temp - 273) * 1.8) + 32;
		}
		else
		{
			kelvin = temp - 273;
		}

		if (i == 0)
		{
			MaxKelvin = kelvin;
			MaxIndex = i;
		}
		else
		{
			if (kelvin >= MaxKelvin)
			{
				MaxKelvin = kelvin;
				MaxIndex = i;
			}
		}
	}

	return MaxIndex;
}