#pragma once
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

//This comment is uneeded
//This is the reading class to create readings frm the Serial In
class Reading
{
public:
	Reading(string jsonInput);
	~Reading(void);

	bool IsValidReading();
	double GetAccelerationXAxis();
	double GetAccelerationYAxis();
	double GetAccelerationZAxis();
	double GetYa();
	double GetPitch();
	double GetRoll();
	int GetArduinoId();
	time_t GetTime();
	string GetErrorMessage();

private:
	void ValidateJson(string jsonInput);
	void TestString(string testString, string& s);
	double GetNextDouble(string& s);

	//members
	bool _validReading;
	double _accelerationXAxis;
	double _accelerationYAxis;
	double _accelerationZAxis;
	double _ya;
	double _pitch;
	double _roll;
	time_t _time; 
	int _arduinoId;
	string _errorMessage;
};

