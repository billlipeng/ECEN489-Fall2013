
#include "Reading.h"
#include <iostream>

using namespace std;

int main()
{
	string jsonReading = "{ \" tempK \" : 123.56 }"; 
	Reading reading(jsonReading);
	cout<< reading.GetTemperature()<<endl<<reading.GetErrorMessage();


	char c;
	cin >> c;
}