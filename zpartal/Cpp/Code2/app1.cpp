/*
 * app1.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: Zachary Partal
 */

#include <iostream>
#include <string>
#include "TemperatureData.h"

using namespace std;

int main() {

	TemperatureData tdat;

	cout << "Enter a scale (F,C,K), temperature and year separated by spaces";
	cout << endl << ">> ";

	cin >> tdat.scale >> tdat.temperature >> tdat.year;

	cout << "The temperature in " << tdat.year << " in F,C and K was: " << endl;
	ConvertedTemps temps = temp_conv(tdat.scale, tdat.temperature);
	cout << "F: " << temps.f << endl;
	cout << "C: " << temps.c << endl;
	cout << "K: " << temps.k << endl;

	return 0;
}
