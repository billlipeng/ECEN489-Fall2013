#pragma once
#include <time.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//This comment is uneeded
//This is the reading class to create readings frm the Serial In
class Reading
{
public:
	Reading();
	Reading(string jsonInput);
	~Reading(void);

	bool IsValidReading();
	double GetAccelerationXAxis();
	double GetAccelerationYAxis();
	double GetAccelerationZAxis();
	double GetGyroXAxis();
	double GetGyroYAxis();
	double GetGyroZAxis();
	double GetYa();
	double GetPitch();
	double GetRoll();
	int GetArduinoId();
	string GetErrorMessage();
	void PrintReading();

private:
	void ValidateJson(string jsonInput);
	void TestString(string testString, string& s);
	double GetNextDouble(string& s);

	//members
	bool _validReading;
	double _accelerationXAxis;
	double _accelerationYAxis;
	double _accelerationZAxis;
	double _gyroXAxis;
	double _gyroYAxis;
	double _gyroZAxis;
	double _ya;
	double _pitch;
	double _roll;
	int _arduinoId;
	string _errorMessage;
};

