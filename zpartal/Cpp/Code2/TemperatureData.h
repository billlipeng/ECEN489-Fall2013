/*
 * TemperatureData.h
 *
 *  Created on: Aug 31, 2013
 *      Author: Zachary
 */

#ifndef TEMPERATUREDATA_H_
#define TEMPERATUREDATA_H_

#include <iostream>
#include <string>

using namespace std;

struct TemperatureData {
	string scale;
	double temperature;
	int year;
};

// Used as return type from conversion function
struct ConvertedTemps {
	double f;
	double c;
	double k;
};

// Pass scale as single letter and temp as a double
ConvertedTemps temp_conv(string s, double t);


#endif /* TEMPERATUREDATA_H_ */
