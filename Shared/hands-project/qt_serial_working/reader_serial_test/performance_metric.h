#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<Windows.h>

using namespace std;

const double pi = 3.14159265359;
class AccelerationVector;
class GyroVector;


double scorePercentageVertical(const double tilt_angle, const vector<double>& acceleration, vector<double>& velocity, double ts);
double scorePercentage(const double tilt_angle, AccelerationVector acceleration);


/*
class AccelerationVector
{
public:
	double x;
	double y;
	double z;

	AccelerationVector();
	AccelerationVector(double, double, double);

};

AccelerationVector::AccelerationVector() {}
AccelerationVector::AccelerationVector(double X, double Y, double Z){x=X;y=Y;z=Z;}


class GyroVector
{
public:
	double x;
	double y;
	double z;

	GyroVector();
	GyroVector(double,double,double);

	void PrintGyro();
};

GyroVector::GyroVector(){}
GyroVector::GyroVector(double X, double Y, double Z){x=X*pi/180.0;y=Y*pi/180.0;z=Z*pi/180.0;}

*/
