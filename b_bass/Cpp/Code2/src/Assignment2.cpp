//============================================================================
// Name        : Assignment2.cpp
// Author      : Brian Bass
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int TempConversion();

int main()
{
	struct TemperatureData{
		string scale;
		double temperature;
		int year;
	};

	TempConversion();


}

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
		Tkel = Tcel -273.15;
		cout<<"You entered "<<Tin<<" degrees Fahrenheit"<<"\n"<<endl;
		cout<<"This is equal to "<<Tcel<<" degrees celsius and "<<Tkel<<" degrees Kelvin"<<endl;
	}

		else if (tscale=='c'||tscale=='C'){
		double Tfar,Tkel;
		Tfar = (Tin*(9.0/5.0)+32);
		Tkel = Tin -273.15;
		cout<<"You entered "<<Tin<<" degrees Celsius"<<"\n"<<endl;
		cout<<"This is equal to "<<Tfar<<" degrees Fahrenheit and "<<Tkel<<" degrees Kelvin"<<endl;
		}

		else if (tscale=='k'||tscale=='K'){
		double Tcel,Tfar;
		Tcel = (Tin + 273.15);
		Tfar = (Tcel-32)*(5.0/9.0);
		cout<<"You entered "<<Tin<<" degrees Kelvin"<<"\n"<<endl;
		cout<<"This is equal to "<<Tcel<<" degrees celsius and "<<Tfar<<" degrees Fahrenheit"<<endl;
		}
		else cerr<<"Sorry, don't recognize that scale"<<endl;

	return 0;
}




