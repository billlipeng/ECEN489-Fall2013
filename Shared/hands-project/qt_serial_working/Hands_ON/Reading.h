#pragma once
#include <time.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

enum SensorType
{
    IMU,
    Ping
};
class Reading
{
public:
    Reading();
    Reading(string jsonInput, SensorType sensorType);
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
    double GetAngle();
    double GetPingDistance(double previousDistance);
    double GetPreviousDistance(){return _previousDistance;}
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
    double _angle;
    double _pingDistance1;
    double _pingDistance2;
    double _previousDistance;
    int _arduinoId;
    string _errorMessage;
    SensorType _sensorType;
};

