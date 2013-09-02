#include "TemperatureData.h"
#include <iostream>
#include <string>

using namespace std;

void Exit()
{
	cout<<"I hope you enjoyed!!!"<<endl<<endl<<endl<<endl;
	cout<<"Enter any character to Exit"<<endl;

	char a;
	cin>>a;
}


int main()
{
	TemperatureData temperatureData = TemperatureData();
	temperatureData.CreateTemperatureDataFromUserInput();
	temperatureData.PresentAllTemperatureScales();
	Exit();
}
