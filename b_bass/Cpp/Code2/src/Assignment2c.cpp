//============================================================================
// Name        : Assignment2c.cpp
// Author      : Brian Bass
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
struct TemperatureData{
		double temperature;
		string scale;
		int year;
	};
TemperatureData TempCompare(TemperatureData T1, TemperatureData T2);

int main()
{
	cout<<"Please enter two temperatures along with their scale"<<endl;
	cout<<"ie Enter 32 f for 32 degrees fahrenheit, 32 c for 32 degrees celsius, and 32 k for 32 degrees kelvin"<<endl;

	TemperatureData T1,T2;

	cin>> T1.temperature >> T1.scale>> T2.temperature>>T2.scale;
	TemperatureData largest_temp = TempCompare(T1,T2);
	cout<<"The larger temperature you entered is "<<largest_temp.temperature<<" "<<largest_temp.scale<<endl;

	return 0;
}

TemperatureData TempCompare(TemperatureData T1,TemperatureData T2)
{
	double temp1 = T1.temperature,temp2 = T2.temperature;  //The default is the fahrenheit option
	TemperatureData large;

	if (T1.scale == T2.scale){
		if (T1.temperature>T2.temperature)
		 large = T1;
		else  large = T2;
	}

	else
		{if (T1.scale == "c" || T1.scale =="C")
		    temp1 = T1.temperature*1.8+32;  //Convert temps to fahrenheit

		if (T1.scale == "k" || T1.scale =="K")
			temp1 = (T1.temperature+273.15)*1.8+32; //Convert all temps to fahrenheit

		if (T2.scale == "c" || T2.scale =="C")
			temp2 = T2.temperature*1.8+32;  //Convert temps to fahrenheit

		if (T2.scale == "k" || T2.scale =="K")
			temp2 = (T2.temperature+273.15)*1.8+32; //Convert all temps to fahrenheit

		if (temp1>temp2)
			large = T1;
		else if (temp2>temp1)
			large = T2;
		}




	return large;
}


