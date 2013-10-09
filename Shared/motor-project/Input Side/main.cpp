
#include "Reading.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "Windows.h"

using namespace std;

int main()
{
	while(true)
	{
		int random = rand()%300;
		bool negative = rand()%2;
		if(negative)
			random *= -1;
		double tempK = 300 + random/100.0;

		string jsonReading = "{ \" tempK \" : ";
		stringstream converter;
		converter<<tempK;
		string doubleString = "";
		converter>>doubleString;

		jsonReading += doubleString;
		jsonReading += " , \" arduinoId \" : ";

		stringstream idConverter;
		random = rand()%4 + 1;
		idConverter<<random;
		string idString = "";
		idConverter>>idString;
		jsonReading += idString;
		jsonReading += " }";

		Reading reading(jsonReading);
		cout<< "Arduino ID = "<<reading.GetArduinoId()<<endl
			<<"Temperatur = "<<reading.GetTemperature()<<endl
			<<reading.GetErrorMessage();

		Sleep(1000);
		cout<<endl;
	}

	char c;
	cin >> c;
}
