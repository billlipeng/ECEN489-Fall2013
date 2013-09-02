/*
 * temperatureClass.cpp
 *
 *  Created on: 2013Äê9ÔÂ2ÈÕ
 *      Author: Tengyan Wang
 */
#include<iostream>
using namespace std;

struct TemperatureData {
	string scale;
	double temperature;
	int year;
};

int main(){
	//display two temperatures
	TemperatureData td1, td2;
	cout << "Input first temperature data: scale(F,C,K), temperature and year."<<endl;
	cin >> td1.scale >> td1.temperature >>td1.year;
	cout << "First temperature data: " << td1.temperature <<" "
			<<td1.scale <<", "<< td1.year<<endl;
	cout << "Input second temperature data: scale(F,C,K), temperature and year."<<endl;
	cin >> td2.scale >> td2.temperature >>td2.year;
	cout << "Second temperature data: " << td2.temperature <<" "
				<<td2.scale <<", "<< td2.year<<endl;
	//compare
	if(td1.scale == td2.scale)
		if(td1.temperature >= td2.temperature)
			cout << "First temperature is larger: "<< td1.temperature <<" "
			<<td1.scale <<", "<< td1.year<<endl;
		else
			cout << "Second temperature is larger: "<< td2.temperature <<" "
						<<td2.scale <<", "<< td2.year<<endl;
	else
		cout << "Please use the same scale.";
	return 0;
}



