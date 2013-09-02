/*
 * Assn2header.h
 *
 *  Created on: Sep 1, 2013
 *      Author: Brian
 */

#ifndef ASSN2HEADER_H_
#define ASSN2HEADER_H_

#include <iostream>
using namespace std;

struct TemperatureData{
		string scale;
		double temperature;
		int year;
	};

int TempConversion();
TemperatureData TempCompare(TemperatureData,TemperatureData);




#endif /* ASSN2HEADER_H_ */
