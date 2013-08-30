#include "TemperatureData.h"
#include <iostream>

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
	TemperatureData temperatureData1 = TemperatureData();
	TemperatureData temperatureData2 = TemperatureData();

	cout<<"Create your first temperature reading"<<endl;
	temperatureData1.CreateTemperatureDataFromUserInput();

	cout<<endl;
	cout<<"Create your second temperature reading"<<endl;
	temperatureData2.CreateTemperatureDataFromUserInput();

	if(temperatureData1.GetTemperatureInFahrenheit() > temperatureData2.GetTemperatureInFahrenheit())
		cout<<"Your first reading, with a temperature of "
		<<temperatureData1.GetTemperature()
		<<" "
		<<temperatureData1.GetScaleString()
		<<" is greater"<<endl;
	else if(temperatureData1.GetTemperatureInFahrenheit() < temperatureData2.GetTemperatureInFahrenheit())
		cout<<"Your second reading, with a temperature of "
		<<temperatureData2.GetTemperature()
		<<" "
		<<temperatureData2.GetScaleString()
		<<" is greater"<<endl;
	else
		cout<<"Both readings are equal with a temperature of "
		<<temperatureData1.GetTemperature()
		<<" "
		<<temperatureData1.GetScaleString();

	Exit();
}
