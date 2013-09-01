/*
 * app2.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: Zachary Partal
 */

#include <iostream>
#include <string>
#include "TemperatureData.h"

using namespace std;

int main() {

	TemperatureData tdat1, tdat2;
	cout << "Temp1: Enter a scale (F,C,K), temperature and year separated by spaces";
	cout << endl << ">> ";

	cin >> tdat1.scale >> tdat1.temperature >> tdat1.year;

	cout << "Temp2: Enter a scale (F,C,K), temperature and year separated by spaces";
	cout << endl << ">> ";

	cin >> tdat2.scale >> tdat2.temperature >> tdat2.year;


	ConvertedTemps temps1 = temp_conv(tdat1.scale, tdat1.temperature);
	ConvertedTemps temps2 = temp_conv(tdat2.scale, tdat2.temperature);

	if (temps1.f > temps2.f) {
		cout << "temp1 is larger: " << endl;
		cout << "F: " << temps1.f << endl;
		cout << "C: " << temps1.c << endl;
		cout << "K: " << temps1.k << endl;
	}
	else if (temps1.f < temps2.f) {
		cout << "temp2 is larger: " << endl;
		cout << "F: " << temps2.f << endl;
		cout << "C: " << temps2.c << endl;
		cout << "K: " << temps2.k << endl;
	}
	else if (temps1.f == temps2.f) {
		cout << "the temperatures are equal";
	}
	else {
		cout << "ERROR";
	}

	return 0;
}


