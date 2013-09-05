//============================================================================
// Name        : Assignment2b.cpp
// Author      : Desmond Uzor
// Version     :
// Copyright   : Your copyright notice
// Description : Compares Two Temperatures
//============================================================================

#include <iostream>
#include <string>
using namespace std;

double temperature_conversion_Celsius(string format, double temp_entered);
int main() {
	string first_scale;
	string second_scale;
	double first_temp;
	double second_temp;
	double first_temp_in_C;
	double second_temp_in_C;

	std::cout << "Enter the first temperature" << endl;
	std::cin >> first_temp ;
	std::cout << "Enter the scale of the first temperature(C:Celsius, F:Fahrenheit, K:Kelvin) " << endl;
	std::cin >> first_scale;
	std::cout << "Enter the second temperature: " << endl;
	std::cin >> second_temp;
	std::cout << "Enter the scale of the second temperature(C:Celsius, F:Fahrenheit, K:Kelvin)" << endl;
	std::cin >> second_scale;
	first_temp_in_C = temperature_conversion_Celsius(first_scale, first_temp);
	second_temp_in_C = temperature_conversion_Celsius(second_scale, second_temp);
	if (first_temp_in_C > second_temp_in_C){
		std::cout<< first_temp << first_scale << " is bigger than " << second_temp << second_scale << std::endl;
		}
	else if (second_temp_in_C> first_temp_in_C){
		std::cout << second_temp_in_C << second_scale << "is bigger than " << first_temp << first_scale <<std::endl;
		}
	else {
		std::cout << "They are equal" << std::endl;
	}
	return 0;
}
double temperature_conversion_Celsius(string format, double temp_entered){
	double temp_in_celsius;
	double temp_in_fahrenheit;
	double  temp_in_kelvin;
	if (format == "C"){
		temp_in_celsius = temp_entered;
	}
	else if (format == "F"){
		temp_in_celsius = (temp_entered - 32) * (5.0 / 9.0);

	}
	else if (format == "K"){
		temp_in_celsius = temp_entered - 273.15;

		}
	else {
		std::cout << "Read the Instructions SLOWLY: "<<std::endl;
	}
	return temp_in_celsius;
}
