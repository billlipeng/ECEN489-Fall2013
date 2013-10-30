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
		//_temperature = -1;
	}
}

void Reading::TestString(string testString, string& s)
{
	string stringFromS = "";

	for(int i = 0; i < testString.size(); i++)
		stringFromS += s[i];

	string resultingString = "";
	for(int i = testString.size(); i < s.size(); i++)
		resultingString += s[i];

	s = resultingString;

	if (testString != stringFromS)
		_errorMessage = "Test: [" + testString + "] did not pass! :(";
}

double Reading::GetNextDouble(string& s)
{
	string doubleString = "";
	bool cont = true;
	int i = 0;

	while(cont)
		if((s[i] >= '0' & s[i] <= '9') | s[i] == '.' | s[i] == '-')
		{
			doubleString += s[i];
			i++;
		}
		else
			cont = false;

	if(doubleString == "")
	{
		_errorMessage = "Incapable of storing double";
		return -1000000;
	}

	string resultingString = "";
	for(;i < s.size(); i++)
		resultingString += s[i];

	s = resultingString;

	stringstream stringStream;
	stringStream<<doubleString;

	double result = 0;
	stringStream >> result;

	return result;
}

void Reading::ValidateJson(string input)
{
	_validReading = false;
	_errorMessage = "";

	TestString("#A-C=",input);
		_accelerationXAxis = GetNextDouble(input);
		TestString(",",input);
		_accelerationYAxis = GetNextDouble(input);
		TestString(",",input);
		_accelerationZAxis = GetNextDouble(input);
	TestString("#M-C=",input);
		_ya = GetNextDouble(input);
		TestString(",",input);
		_pitch = GetNextDouble(input);
		TestString(",",input);
		_roll = GetNextDouble(input);

	_validReading = _errorMessage == "";
}


Reading::~Reading(void)
{
}

bool Reading::IsValidReading()
{
	return _validReading;
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

double Reading::GetAccelerationXAxis()
{
	return _accelerationXAxis;
}

double Reading::GetAccelerationYAxis()
{
	return _accelerationYAxis;
}

double Reading::GetAccelerationZAxis()
{
	return _accelerationZAxis;
}

double Reading::GetYa()
{
	return _ya;
}

double Reading::GetPitch()
{
	return _pitch;
}

double Reading::GetRoll()
{
	return _roll;
}
