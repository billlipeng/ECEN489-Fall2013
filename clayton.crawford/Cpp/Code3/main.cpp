#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	vector<double> temperatures;
	string input = "";
	double inputTemp = 0.0;
	double conversionVar = 0.0;
	
	while (input != "quit") {
		cout << "\nPlease enter a temperature in Fahrenheit (type 'quit' to end input): ";
		cin >> input;
		if (input != "quit") {
			// change input string to double
			inputTemp = atof(input.c_str());
			// add temperature to vector
			temperatures.push_back(inputTemp);
		}
	}
	
	cout << "\nThe total number of temperatures that were input is " << temperatures.size();
	cout << "\n\nThe temperatures you input are:";
	for (int i = 0; i < temperatures.size(); ++i) {
		cout << "\nTemperature " << i+1 << " is " << temperatures[i] << " degrees F";
	}
	
	// convert temps from Fahrenheit to Celsius
	for (double &i : temperatures) {
		conversionVar = i; 
		i = ((conversionVar - 32) * 5 ) / 9;
	}
	cout << "\n\nThe temperatures you input converted to Celsius:";
	for (int i = 0; i < temperatures.size(); ++i) {
		cout << "\nTemperature " << i+1 << " is " << temperatures[i] << " degrees C";
	}
	

	return 0;
}