/*
 * vector.cpp
 *
 *  Created on: 2013Äê9ÔÂ4ÈÕ
 *      Author: Tengyan Wang
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TemperatureData {
	string scale;
	double temperature;
	int year;
};


int main(){
	TemperatureData temp;
	vector<TemperatureData> temp_data;
	int ct1=0, ct2=0;
	cout << "Input Fahrenheit temperature ('F'+temperature+year):" << endl;

	while(cin >> temp.scale >> temp.temperature >> temp.year){
		temp_data.push_back(temp);		//store temperature data into vector
	}
	//print size and content
	for(unsigned int i=0; i<temp_data.size(); ++i){
		if(temp_data[i].scale != "F"){
			cout << "!!!Wrong.Input Fahrenheit temperature first.!!!" << endl;
			++ct1;
		}
		else
		cout << "Fahrenheit temperature: " << temp_data[i].temperature << ", year: " << temp_data[i].year << endl;
	}
	cout << "The size of the data are: " << temp_data.size() << ",  Wrong data are: " << ct1 << endl <<endl ;
	//change scale and print
	for(TemperatureData &temp : temp_data){
		if(temp.scale != "F"){
			cout << "!!!Wrong.Input Fahrenheit temperature first.!!!" << endl;
			++ct2;
		}
		else
		cout << "Celsius temperature: " << (temp.temperature-32)*5/9 << ", year " << temp.year << endl;
	}
	cout << "The size of the data are: " << temp_data.size() << ",  Wrong data are: " << ct2 << endl <<endl ;
	return 0;
}



