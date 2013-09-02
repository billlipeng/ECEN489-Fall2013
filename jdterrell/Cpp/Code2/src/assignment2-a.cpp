//============================================================================
// Name        : assignment2-a.cpp
// Author      : Jeffery D. Terrell


#include <iostream>
using namespace std;

struct TemperatureData {
	string scale;
	double temperature;
	int year;
};

void PrintInfo (TemperatureData sTemperatureData) {

	cout << endl;
	cout << "Scale: " << sTemperatureData.scale << endl;
	cout << "Temperature: " << sTemperatureData.temperature << endl;
	cout << "Year: " << sTemperatureData.year << endl << endl;
}

int main() {

	TemperatureData sdata1, sdata2, sdata3;
	sdata1.scale=""; sdata2.scale=""; sdata3.scale="";
	sdata1.temperature=0; sdata2.temperature=0; sdata3.temperature=0;
	sdata1.year=0; sdata2.year=0; sdata3.year=0;
	int scaleoption = 1;

	cout << "Enter scale: ";
	cin >> sdata1.scale;

	cout << "Enter temperature: ";
	cin >> sdata1.temperature;

	cout << "Enter year: ";
	cin >> sdata1.year;


	if (sdata1.scale == "Kelvin" || sdata1.scale == "kelvin" || sdata1.scale == "K" || sdata1.scale == "k")
	{
		scaleoption = 1;
	}
	else if (sdata1.scale == "Fahrenheit" || sdata1.scale == "fahrenheit" || sdata1.scale == "F" || sdata1.scale == "f")
	{
		scaleoption = 2;
	}
	else if (sdata1.scale == "Celsius" || sdata1.scale == "celsius" || sdata1.scale == "C" || sdata1.scale == "c")
	{
		scaleoption = 3;
	}
	else
	{
		cout << "Invalid scale" << endl;
		return 0;
	}

	switch(scaleoption)
	{
		case 1:				// user input Kelvin
		sdata2.scale = "Celsius";
		sdata2.temperature = sdata1.temperature - 273.15;
		sdata2.year = sdata1.year;
		sdata3.scale = "Fahrenheit";
		sdata3.temperature = (sdata2.temperature * 1.8)+32;
		sdata3.year = sdata1.year;
		break;

		case 2:				// user input Fahrenheit
		sdata2.scale = "Celsius";
		sdata2.temperature = (sdata1.temperature - 32)/1.8;
		sdata2.year = sdata1.year;
		sdata3.scale = "Kelvin";
		sdata3.temperature = sdata2.temperature + 273.15;
		sdata3.year = sdata1.year;
		break;

		case 3:				// user input Celsius
		sdata2.scale = "Fahrenheit";
		sdata2.temperature = (sdata1.temperature * 1.8)+32;
		sdata2.year = sdata1.year;
		sdata3.scale = "Kelvin";
		sdata3.temperature = sdata1.temperature + 273.15;
		sdata3.year = sdata1.year;
		break;

	}

	PrintInfo(sdata1);
	PrintInfo(sdata2);
	PrintInfo(sdata3);


	return 0;
}
