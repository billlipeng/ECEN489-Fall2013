//============================================================================
// Name        : Assignment2.cpp
// Author      : Desmond Uzor
// Version     :
// Copyright   : Thou shall not steal, on second thought. Have at it hoss.
// Description : Temperature Conversion Program. Now you know how hot Texas is!!
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct TemperatureData{
	string scale;
	double temperature;
	int year;
};
void temperature_conversion(string format, double temp_entered);
int main() {
	TemperatureData temp;
	string scale;
	std::cout << "You there, Enter a temperature" << '\n';
	std::cin >> temp.temperature ;
	std::cout << "Enter C for Celsius, F for Fahrenheit or K"
			 << " for  the one and only kelvin scale" << '\n' << '\n';
	std::cin >> scale;
	temperature_conversion(scale, temp.temperature);
	return 0;
}

void temperature_conversion(string format, double temp_entered){
	double temp_in_celsius;
	double temp_in_fahrenheit;
	double  temp_in_kelvin;
	if (format == "C"){
		temp_in_celsius = temp_entered;
		temp_in_fahrenheit = (temp_entered * (9.0 / 5.0)) + 32;
		temp_in_kelvin = temp_entered + 273.15;
	}
	else if (format == "F"){
		temp_in_celsius = (temp_entered - 32) * (5.0 / 9.0);
		temp_in_fahrenheit = temp_entered;
		temp_in_kelvin = temp_in_celsius + 273.15;
	}
	else if (format == "K"){
		temp_in_celsius = temp_entered - 273.15;
		temp_in_fahrenheit = (temp_entered * (9.0 / 5.0)) + 32;
		temp_in_kelvin = temp_entered;
		}
	else {
		std::cout << "Read the Instructions SLOWLY: "<<std::endl;
	}
	std::cout << "The Temperature is values are "<< temp_in_celsius << " degrees celsius, " <<
		 temp_in_fahrenheit << " degrees fahrenheit, " <<
		 temp_in_kelvin << " degrees kelvin" << '\n';;
}
