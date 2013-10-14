#include "Reading.h"


Reading::Reading(string jsonInput)
{
	ValidateJson(jsonInput);
	if(_validReading)
	{
		_time = time(NULL);
		_arduinoId = 1;
	}
	else 
	{
		_time = NULL;
		_arduinoId = -1;
		_temperature = -1;
	}
}

void Reading::ValidateJson(string jsonInput)
{
	_validReading = false;

	stringstream stringStream(jsonInput);
	string validationString = "";

	stringStream >> validationString;
	if (validationString != "{")
	{
		_errorMessage = "Improper JSON format";
		return;
	}

	stringStream >> validationString;
	if (validationString != "\"")
	{
		_errorMessage = "Improper JSON format";
		return;
	}

	stringStream >> validationString;
	if (validationString != "motorVoltage")
	{
		_errorMessage = "Not a temperature reading";
		return;
	}

	stringStream >> validationString;
	if (validationString != "\"")
	{
		_errorMessage = "Improper JSON format";
		return;
	}

	stringStream >> validationString;
	if (validationString != ":")
	{
		_errorMessage = "Improper JSON format";
		return;
	}

	double tempTemperature = 0;
	stringStream >> tempTemperature;

	stringStream >> validationString;
	if (validationString != "}")
	{
		_errorMessage = "Improper JSON format";
		return;
	}

	_temperature = tempTemperature;
	_validReading = true;
	_errorMessage = "";
	return;
}


Reading::~Reading(void)
{
}

bool Reading::IsValidReading()
{
	return _validReading;
}

double Reading::GetMotorVoltage()
{
	return _temperature;
}

int Reading::GetArduinoId()
{
	return _arduinoId;
}

time_t Reading::GetTime()
{
	return _time;
}

string Reading::GetErrorMessage()
{
	return _errorMessage;
}
