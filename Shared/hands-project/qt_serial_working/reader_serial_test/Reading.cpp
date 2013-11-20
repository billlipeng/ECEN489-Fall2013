#include "Reading.h"
#include <QtDebug>

Reading::Reading(){}

Reading::Reading(string jsonInput)
{
	ValidateJson(jsonInput);
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

	if (testString != stringFromS & _errorMessage == "")
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
		if(_errorMessage == "")
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
/*
	TestString("#YPR=",input);
		_ya = GetNextDouble(input);
		TestString(",",input);
		_pitch = GetNextDouble(input);
		TestString(",",input);
		_roll = GetNextDouble(input);
*/
//    qDebug() << "Data" << QString::fromStdString(input);

//	TestString("#A-C=",input);
		_accelerationXAxis = GetNextDouble(input);
		TestString(",",input);
		_accelerationYAxis = GetNextDouble(input);
		TestString(",",input);
		_accelerationZAxis = GetNextDouble(input);

        TestString("\r\n",input);
        _angle = GetNextDouble(input);

//    TestString("\r\n#G-C=",input);
//		_gyroXAxis = GetNextDouble(input);
//		TestString(",",input);
//		_gyroYAxis = GetNextDouble(input);
//		TestString(",",input);
//		_gyroZAxis = GetNextDouble(input);

	_validReading = _errorMessage == "";
}

void Reading::PrintReading()
{
    qDebug() <<"XAccel = "<<GetAccelerationXAxis();
    qDebug() <<"YAccel = "<<GetAccelerationYAxis();
    qDebug() <<"ZAccel = "<<GetAccelerationZAxis();
    qDebug() <<"XGyro = "<<GetGyroXAxis();
    qDebug() <<"YGyro = "<<GetGyroYAxis();
    qDebug() <<"ZGyro = "<<GetGyroZAxis();
    qDebug() << QString::fromStdString(GetErrorMessage());
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

double Reading::GetGyroXAxis()
{
	return _gyroXAxis;
}

double Reading::GetGyroYAxis()
{
	return _gyroYAxis;
}

double Reading::GetGyroZAxis()
{
	return _gyroZAxis;
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

double Reading::GetAngle()
{
    return _angle;
}

