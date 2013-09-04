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
	double temperature1;
	double temperature2;
};

int main() {
	TemperatureData TempData;
	double CtoF, CtoK, FtoC, FtoK, KtoC, KtoF;

	cout << "Enter scale (C,F, or K):" << endl;
	cin >> TempData.scale;
	cout << "Enter value of temperature 1:" << endl;
	cin >> TempData.temperature1;
	cout << "Enter value of temperature 2:" << endl;
	cin >> TempData.temperature2;

	if ((TempData.scale == "C" || TempData.scale == "c") && (TempData.temperature1 > TempData.temperature2))
	{
		CtoF = (TempData.temperature1 * 1.8) + 32; //good
		CtoK = TempData.temperature1 + 273.15;	//good
		cout << "The high temperature is " << TempData.temperature1 << "C ("<< CtoF << " F, " << CtoK << " K)." << endl;
	}

	if ((TempData.scale == "C" || TempData.scale == "c") && (TempData.temperature2 > TempData.temperature1))
	{
		CtoF = (TempData.temperature2 * 1.8) + 32; //good
		CtoK = TempData.temperature2 + 273.15;	//good
		cout << "The high temperature is " << TempData.temperature2 << "C ("<< CtoF << " F, " << CtoK << " K)." << endl;
	}

	if ((TempData.scale == "F" || TempData.scale == "f") && (TempData.temperature1 > TempData.temperature2))
	{
		FtoC = (TempData.temperature1 - 32) / 1.8; //good
		FtoK = ((TempData.temperature1 - 32) / 1.8) + 273.15; //good
		cout << "The high temperature is " << TempData.temperature1 << "F ("<< FtoC << " C, " << FtoK << " K)." << endl;
	}

	if ((TempData.scale == "F" || TempData.scale == "f") && (TempData.temperature2 > TempData.temperature1))
	{
		FtoC = (TempData.temperature2 - 32) / 1.8; //good
		FtoK = ((TempData.temperature2 - 32) / 1.8) + 273.15; //good
		cout << "The high temperature is " << TempData.temperature2 << "F ("<< FtoC << " C, " << FtoK << " K)." << endl;
	}

	if ((TempData.scale == "K" || TempData.scale == "k") && (TempData.temperature1 > TempData.temperature2))
	{
		KtoC = TempData.temperature1 - 273.15; //good
		KtoF = ((TempData.temperature1 - 273.15) * 1.8) + 32; //good
		cout << "The high temperature is " << TempData.temperature1 << "K ("<< KtoC << " C, " << KtoF << " F)." << endl;
	}

	if ((TempData.scale == "K" || TempData.scale == "k") && (TempData.temperature2 > TempData.temperature1))
	{
		KtoC = TempData.temperature2 - 273.15; //good
		KtoF = ((TempData.temperature2 - 273.15) * 1.8) + 32; //good
		cout << "The high temperature is " << TempData.temperature2 << "K ("<< KtoC << " C, " << KtoF << " F)." << endl;
	}

	return 0;

};

