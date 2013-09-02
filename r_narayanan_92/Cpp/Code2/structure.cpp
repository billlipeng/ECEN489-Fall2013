/*
 * structure.cpp
 *
 *  Created on: Sep 2, 2013
 *      Author: Narayanan Rengaswamy
 */

// Structure named TemperatureData that operates on Celsius, Fahrenheit and Kelvin
// F = [(9*C)/5] + 32; K = 273.15 + C

/*
 *  The main() function is at the end - after all required functions
 *  When run, the application offers two options:
 *  1. Use Structure  2. Compare Temperatures
 *
 *  The Temperatures are compared only in Celsius
 */
#include <iostream>
#include <string>

using namespace std;

struct TemperatureData {

	std::string scale;
	double temperature = 0.0;
	int year = 0;

};

//function to get just temperature with its scale as input
double temp_input(int temp_index) {

	string s;
	double t = 0.0, temp_celsius = 0.0;

	while (1) {
		std::cout << "Give the scale for temperature " << temp_index << " ('F' => Fahrenheit/ 'C' => Celsius/ 'K' => Kelvin): ";
		std::cin >> s;

	if (s == "F" || s == "C" || s == "K")
		break;
	else
		std::cout << "Please give a valid scale (check your spelling twice)!!" << std::endl;

	}

	std::cout << "Give the temperature: ";
	std::cin >> t;

	if (s == "F")
		temp_celsius = ((t - 32) * 5)/9;
	else if (s == "C")
		temp_celsius = t;
	else
		temp_celsius = t - 273.15;

	return temp_celsius;

}

//function to compare two temperatures and give the larger one
void main2() {

double t1,t2;

t1 = temp_input(1);
t2 = temp_input(2);

if (t1 > t2)
	std::cout << "The first temperature (" << t1 << "°C) is greater than " << t2 << "°C" << std::endl;
else if (t2 > t1)
	std::cout << "The second temperature (" << t2 << "°C) is greater than " << t1 << "°C" << std::endl;
else
	std::cout << "The temperatures are equal!!" << std::endl;

return;
}

//The code that runs first
int main() {

int opt = 0;

std::cout << "Choose an application from the following two: " << std::endl;
std::cout << "1. Use Structure \n2. Compare Temperatures" << std::endl;
std::cout << "Give your option (1 or 2): ";
std::cin >> opt;

if (opt != 1 && opt != 2) {
	std::cout << "Invalid Option! Re-run the project" << std::endl;
	return -1;
}

if (opt == 2) {
	main2();     //Compare two input temperatures
	return 1;
}

TemperatureData t1;
string s;
double t_fahrenheit, t_celsius, t_kelvin;

while (1) {
std::cout << "Give the scale for input temperature ('F' => Fahrenheit/ 'C' => Celsius/ 'K' => Kelvin): ";
std::cin >> s;

if (s == "F" || s == "C" || s == "K") {
	t1.scale = s;
	break;
}
else
	std::cout << "Please give a valid scale!!" << std::endl;

}

std::cout << "Give the temperature: ";
std::cin >> t1.temperature;

while(1) {
std::cout << "Give the year: ";
std::cin >> t1.year;

if (t1.year >= 2013)
	std::cout << "Give a year earlier than the current year!!" << std::endl;
else
	break;
}

if (s == "F") {
	t1.scale = "Fahrenheit";
	t_fahrenheit = t1.temperature;
	t_celsius = ((t_fahrenheit-32) * 5)/9;
	t_kelvin = t_celsius + 273.15;
}
else if (s == "C") {
	t1.scale = "Celsius";
	t_celsius = t1.temperature;
	t_fahrenheit = (9 * t_celsius)/5 + 32;
	t_kelvin = t_celsius + 273.15;
}
else {
	t1.scale = "Kelvin";
	t_kelvin = t1.temperature;
	t_celsius = t_kelvin - 273.15;
	t_fahrenheit = (9 * t_celsius)/5 + 32;
}

std::cout << "The temperature in the year " << t1.year << " was: "
		  << t_fahrenheit << "°F / " << t_celsius << "°C / " << t_kelvin << "K" << std::endl;

}

