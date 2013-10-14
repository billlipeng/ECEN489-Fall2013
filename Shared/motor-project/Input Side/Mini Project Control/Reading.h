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
	double GetMotorVoltage();
	int GetArduinoId();
	time_t GetTime();
	string GetErrorMessage();

private:
	void ValidateJson(string jsonInput);

	//members
	bool _validReading;
	double _temperature;
	time_t _time; 
	int _arduinoId;
	string _errorMessage;
};

