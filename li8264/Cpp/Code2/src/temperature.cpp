//============================================================================
// Name        : temperature.cpp
// Author      : Shuli
// Version     :
// Copyright   : Code2
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int temperature ();

int main()
{
	struct TemperatureData{
			string scale;
			double temperature;
			int year;
     };
	temperature ();
}



int temperature ()
{
	std::cout << "Please enter the temperature:" << std::endl;
	double T1;
	std::cin >>T1;
	std::cout << "The Scale of this Temperature: F for Fahrenheit, C for Celsius and K for Kelvin" << std::endl;
	char Scale;
	std::cin >>Scale;

	if(Scale =='F')
	{
		double TF=T1;
		double TC=5/9*(TF-32);
		double TK=TC+273.15;
		std::cout << "The Temperature is:" << "\n"<<TF<<" in Fahrenheit" <<
				"\n" <<TC <<" in Celsuis" << "\n" << TK <<" in Kelvin" << std::endl;
	}
	if(Scale =='C')
		{
			double TC=T1;
			double TF=9/5*(TC+32);
			double TK=TC+273.15;
			std::cout << "The Temperature is:" << "\n"<<TF<<" in Fahrenheit" <<
					"\n" <<TC <<" in Celsuis" << "\n" << TK <<" in Kelvin" << std::endl;
		}
	if(Scale =='K')
			{
				double TK=T1;
				double TF=9/5*(TK-273.15)+32;
				double TC=TK-273.15;
				std::cout << "The Temperature is:" << "\n"<<TF<<" in Fahrenheit" <<
						"\n" <<TC <<" in Celsuis" << "\n" << TK <<" in Kelvin" << std::endl;
			}
	return 0;

	};

