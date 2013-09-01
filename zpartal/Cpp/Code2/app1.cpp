/*
 * main.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: Zachary
 */

#include <iostream>
#include <string>

using namespace std;

struct TemperatureData {
	string scale;
	double temperature;
	int year;
} ;

int main() {

	TemperatureData tdat;

	cout << "Enter a scale (F,C,K), temperature and year separated by spaces";
	cout << endl << ">> ";

	cin >> tdat.scale >> tdat.temperature >> tdat.year;



	return 0;
}
