/*
 * TemperatureData.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: Zachary
 */

#include "TemperatureData.h"

ConvertedTemps temp_conv(string s, double t) {
	ConvertedTemps temps;
	if (s == "F" || s == "f") {
		temps.f = t;
		temps.c = (t - 32.0)*(5.0/9.0);
		temps.k = temps.c + 273.15;
	}
	else if (s == "C" || s == "c") {
		temps.c = t;
		temps.k = temps.c + 273.15;
		temps.f = (temps.c*(9.0/5.0))+32.0;
	}
	else if (s == "K" || s == "k") {
		temps.k = t;
		temps.c = temps.k - 273.15;
		temps.f = (temps.k * (9.0/5.0)) - 459.67;
	}
	else {
		cout << "Temperature is an invalid scale";
	}
	return temps;
}





