//============================================================================
// Name        : Assignment3.cpp
// Author      : Desmond Uzor
// Version     :
// Copyright   : Do What You Must!!
// Description : Behold, The One and Only Program to ... convert user given Fahrenheit values to Celsius
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


/*Prototype Declaration for conversion function*/
double temperature_conversion_Celsius(double temp_entered);
int main() {
	double temperature;
	vector<double> values;
	/* Temperatures are asked for and entered
	now you can compare this insanely hot Texas weather temperatures */
	cout << "Enter Fahrenheit temperatures: "<< endl;
	while (cin >> temperature){
		values.push_back(temperature);
	}
/*The values are entered ,and stored in a vectro then printed out */
	cout << "The size of this vector is " << values.size() << endl;
	cout << "This vector includes " << endl;
	for (auto i: values){
		cout << "  " << i <<" degrees fahrenheit " << endl;
	}
	/*Repeats the procedure above, but now in Celsius,
	 * Amazing, I know! */
	cout << "Now when changed to Celsius" << endl;
	for (auto &i:values){
			i = temperature_conversion_Celsius(i);
		}
	cout << "The size of this vector is " << values.size() << endl;
	cout << "This vector includes " << endl;
	for (auto i: values){
			cout << "  " << i <<" degrees celsius " << endl;
		}
	return 0;
}
/*Function that converts temperature to Celsius
 * Beautiful Three Lines of Hardcore Programming*/
double temperature_conversion_Celsius(double temp_entered){
	double temp_in_celsius;
	temp_in_celsius = (temp_entered - 32) * (5.0 / 9.0);
    return temp_in_celsius;
}
