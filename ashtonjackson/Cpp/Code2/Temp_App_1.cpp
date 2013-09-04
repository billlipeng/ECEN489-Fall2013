/*
 * Temp_App_2.cpp
 *
 *  Created on: Sep 1, 2013
 *      Author: ashton
 */
#include <iostream>
#include <string>
using namespace std;

struct TemperatureData {
	string scale;
	double temperature;
	int year;
};

int main() {
	TemperatureData TempData;
	double CtoF, CtoK, FtoC, FtoK, KtoC, KtoF;

	cout << "Enter a temperature, scale (C,F,K), and year. Separate values with spaces." << endl;
	cin >> TempData.temperature >> TempData.scale >> TempData.year;

	if (TempData.scale == "C" || TempData.scale == "c")
	{
		CtoF = (TempData.temperature * 1.8) + 32; //good
		CtoK = TempData.temperature + 273.15;	//good
		cout << "You've recorded a temperature of " << CtoF << " F, or " << CtoK << " K, for year " << TempData.year << "." << endl;
	}

	if (TempData.scale == "F" || TempData.scale == "f")
	{
		FtoC = (TempData.temperature - 32) / 1.8; //good
		FtoK = ((TempData.temperature - 32) / 1.8) + 273.15; //good
		cout << "You've recorded a temperature of " << FtoC << " C, or " << FtoK << " K, for year " << TempData.year << "." << endl;
	}

	if (TempData.scale == "K" || TempData.scale == "k")
	{
		KtoC = TempData.temperature - 273.15; //good
		KtoF = ((TempData.temperature - 273.15) * 1.8) + 32; //good
		cout << "You've recorded a temperature of " << KtoC << " C, or " << KtoF << " F, for year " << TempData.year << "." << endl;
	}

	return 0;

};

