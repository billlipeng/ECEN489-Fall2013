#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	vector<double> temperatures;
	string input = "";
	double tempIn = 0.0;
	double variable = 0.0;
	
	while (input != "quit") {
		cout << "\nGimme a temperature in Fahrenheit (type 'done' to end input): ";
		cin >> input;
		if (input != "done") {
			tempIn = atof(input.c_str());
			temperatures.push_back(tempIn);
		}
	}
	
	cout << "\nThe total number of temperatures that were input is " << temperatures.size();
	cout << "\n\nThe temperatures you input are:";
	for (int i = 0; i < temperatures.size(); ++i) {
		cout << "\nTemperature " << i+1 << " is " << temperatures[i] << " degrees F";
	}
	
	// convert temps from Fahrenheit to Celsius
	for (double &i : temperatures) {
		variable = i; 
		i = ((variable - 32) * 5 ) / 9;
	}
	cout << "\n\nThe temperatures you input converted to Celsius:";
	for (int i = 0; i < temperatures.size(); ++i) {
		cout << "\nTemperature " << i+1 << " is " << temperatures[i] << " degrees C";
	}
	

	return 0;
}