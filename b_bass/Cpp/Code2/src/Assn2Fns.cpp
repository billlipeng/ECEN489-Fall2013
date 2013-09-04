/*
 * Assn2Fns.cpp
 *
 *  Created on: Sep 1, 2013
 *      Author: Brian
 */

#include "Assn2header.h"

int TempConversion()
{
	cout<<"Please enter a temperature"<<endl;

	double Tin;
	cin>>Tin;

	cout<<"Is this temperature in celsius, kelvin, or fahrenheit?"<<"\n"<<"Please enter f for fahrenheit, c for celsius, and k for kelvin"<<endl;

	char tscale;
	cin>>tscale;

	if (tscale=='f'||tscale=='F'){
		double Tcel,Tkel;
		Tcel = (Tin-32)*(5.0/9.0);
		Tkel = Tcel + 273.15;
		cout<<"You entered "<<Tin<<" degrees Fahrenheit"<<"\n"<<endl;
		cout<<"This is equal to "<<Tcel<<" degrees celsius and "<<Tkel<<" degrees Kelvin"<<endl;
	}

		else if (tscale=='c'||tscale=='C'){
		double Tfar,Tkel;
		Tfar = (Tin*(9.0/5.0)+32);
		Tkel = Tin + 273.15;
		cout<<"You entered "<<Tin<<" degrees Celsius"<<"\n"<<endl;
		cout<<"This is equal to "<<Tfar<<" degrees Fahrenheit and "<<Tkel<<" degrees Kelvin"<<endl;
		}

		else if (tscale=='k'||tscale=='K'){
		double Tcel,Tfar;
		Tcel = (Tin - 273.15);
		Tfar = (Tcel-32)*(5.0/9.0);
		cout<<"You entered "<<Tin<<" degrees Kelvin"<<"\n"<<endl;
		cout<<"This is equal to "<<Tcel<<" degrees celsius and "<<Tfar<<" degrees Fahrenheit"<<endl;
		}
		else cerr<<"Sorry, don't recognize that scale"<<endl;

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

