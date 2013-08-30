#include "TemperatureData.h"
#include <iostream>

const double celciusKelvinDifference = 273.15;

TemperatureData::TemperatureData()
{
	_scale = Invalid;
	_temperature = 0;
	_year = 0;
}

void TemperatureData::CreateTemperatureDataFromUserInput()
{
	ObtainScale();
	ObtainTemperature();
	ObtainYear();
}

void TemperatureData::PresentAllTemperatureScales()
{
	cout<<"The temperature in Kelvin is: "
		<<GetTemperatureInKelvin()<<" K"<<endl;
	cout<<"The temperature in Celsius is: "
		<<GetTemperatureInCelcius()<<" C"<<endl;
	cout<<"The temperature in Fahrenheit is: "
		<<GetTemperatureInFahrenheit()<<" F"<<endl;
}

void TemperatureData::ObtainScale()
{
	char userInput;

	cout<<"Please enter F, C, or K for Fahrenheit, Celsius, or Kelvin respectively"<<endl;

	try
	{
		cin >> userInput;
	}
	catch(exception e)
	{
		cout<<"Woah! You gave us incorrect input, we just need F, C, or K!"<<endl;
		ObtainScale();
	}

	switch(userInput)
	{
	case 'F':
	case 'f':
		_scale = Fahrenheit;
		break;
	case 'C':
	case 'c':
		_scale = Celsius;
		break;
	case 'K':
	case 'k':
		_scale = Kelvin;
		break;
	default:
		cout<<"Woah! You gave us incorrect input Dude!"<<endl;
		ObtainScale();
		break;
	}
}

void TemperatureData::ObtainTemperature()
{
	cout<<"Please enter the temperature of the reading"<<endl;

	try
	{
		cin>>_temperature;
	}
	catch(exception e)
	{
		cout<<"Woah! You gave us incorrect input! We need a double for your temperature!"<<endl;
		ObtainTemperature();
	}
}

void TemperatureData::ObtainYear()
{
	cout<<"Please enter the year that the reading was obtained"<<endl;

	try
	{
		cin>>_year;
	}
	catch(exception e)
	{
		cout<<"Woah! You gave us incorrect input! We need a double for the year!"<<endl;
		ObtainYear();
	}
}

double TemperatureData::GetTemperatureInKelvin()
{
	switch(_scale)
	{
	case Kelvin:
		return _temperature;
		break;
	case Celsius:
		return _temperature - celciusKelvinDifference;
		break;
	case Fahrenheit:
		return ((_temperature - 32) * 5/9) - celciusKelvinDifference;
		break;
	case Invalid:
	default:
		return -1000;
		break;
	}
}

double TemperatureData::GetTemperatureInCelcius()
{
	switch(_scale)
	{
	case Kelvin:
		return _temperature + celciusKelvinDifference;
		break;
	case Celsius:
		return _temperature;
		break;
	case Fahrenheit:
		return ((_temperature - 32) * 5/9);
		break;
	case Invalid:
	default:
		return -1000;
		break;
	}
}

double TemperatureData::GetTemperatureInFahrenheit()
{
	switch(_scale)
	{
	case Kelvin:
		return ((_temperature * 9/5) + 32) + celciusKelvinDifference;
		break;
	case Celsius:
		return (_temperature * 9/5) + 32;
		break;
	case Fahrenheit:
		return _temperature;
		break;
	case Invalid:
	default:
		return -1000;
		break;
	}
}

string TemperatureData::GetScaleString()
{
	switch(_scale)
	{
	case Kelvin:
		return "K";
		break;
	case Celsius:
		return "C";
		break;
	case Fahrenheit:
		return "F";
		break;
	case Invalid:
	default:
		return "X";
		break;
	}
}

Scale TemperatureData::GetScale()
{
	return _scale;
}

double TemperatureData::GetTemperature()
{
	return _temperature;
}

int TemperatureData::GetYear()
{
	return _year;
}
