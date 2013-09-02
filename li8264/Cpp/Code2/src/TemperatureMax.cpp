//============================================================================
// Name        : TemperatureMax.cpp
// Author      : Shuli
// Version     :
// Copyright   : Code2
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;


int temperaturemax1 ();
int temperaturemax2 ();
int main()
{
	struct TemperatureData{
			string scale;
			double temperature;
			int year;
     };

	temperaturemax1 ();
	std::cout<< "The temperature in Fahrenhiet is:" <<std::endl;
	double comp1;
	std::cin >> comp1;
	temperaturemax2 ();
	std::cout<< "The temperature in Fahrenhiet is:" <<std::endl;
	double comp2;
	std::cin >> comp2;
	if (comp1>comp2)
	{
		std::cout<< "the larger one is the first temperature" <<std::endl;
	}

	if (comp1<comp2)
		{
			std::cout<< "the larger one the second temperature" <<std::endl;
		}
	else
		{
		std::cout << "they are equal!" <<std::endl;
		}



}


int temperaturemax1 ()
{
	std::cout << "Please enter the first temperature with the scale: F for Fahrenheit, C for Celsius and K for Kelvin" << std::endl;
	double T1;
	char S1;
	std::cin >> T1>>S1;
	if (S1=='F')
	{
		double TF1=T1;
		double TC1=5/9*(TF1-32);
		double TK1=TC1+273.15;
		std::cout << "The Temperature is:" << "\n"<<TF1<<" in Fahrenheit" <<
						"\n" <<TC1 <<" in Celsuis" << "\n" << TK1<<" in Kelvin" << std::endl;

	}
	if(S1 =='C')
			{
				double TC1=T1;
				double TF1=9/5*(TC1+32);
				double TK1=TC1+273.15;
				std::cout << "The Temperature is:" << "\n"<<TF1<<" in Fahrenheit" <<
						"\n" <<TC1 <<" in Celsuis" << "\n" << TK1 <<" in Kelvin" << std::endl;
			}
		if(S1 =='K')
				{
					double TK1=T1;
					double TF1=9/5*(TK1-273.15)+32;
					double TC1=TK1-273.15;
					std::cout << "The Temperature is:" << "\n"<<TF1<<" in Fahrenheit" <<
							"\n" <<TC1 <<" in Celsuis" << "\n" << TK1 <<" in Kelvin" << std::endl;
				}
		return 0;
};
int temperaturemax2 ()
	{
		std::cout << "Please enter the second temperature with the scale: F for Fahrenheit, C for Celsius and K for Kelvin" << std::endl;
					double T2;
					char S2;
					std::cin >> T2>>S2;
					if (S2=='F')
					{
						double TF2=T2;
						double TC2=5/9*(TF2-32);
						double TK2=TC2+273.15;
						std::cout << "The Temperature is:" << "\n"<<TF2<<" in Fahrenheit" <<
										"\n" <<TC2 <<" in Celsuis" << "\n" << TK2<<" in Kelvin" << std::endl;

					}
					if(S2 =='C')
							{
								double TC2=T2;
								double TF2=9/5*(TC2+32);
								double TK2=TC2+273.15;
								std::cout << "The Temperature is:" << "\n"<<TF2<<" in Fahrenheit" <<
										"\n" <<TC2 <<" in Celsuis" << "\n" << TK2 <<" in Kelvin" << std::endl;
							}
						if(S2 =='K')
								{
									double TK2=T2;
									double TF2=9/5*(TK2-273.15)+32;
									double TC2=TK2-273.15;
									std::cout << "The Temperature is:" << "\n"<<TF2<<" in Fahrenheit" <<
											"\n" <<TC2 <<" in Celsuis" << "\n" << TK2 <<" in Kelvin" << std::endl;
								}
		return 0;
	};








