/*
 * Project_Analysis.h
 *
 *  Created on: Nov 7, 2013
 *      Author: Brian
 */

#ifndef PROJECT_ANALYSIS_H_
#define PROJECT_ANALYSIS_H_

//#include"Matrix.h"
#include"MatrixIO.h"
#include<vector>
#include"Reading.h"
#include"Reader.h"
//#include<iostream>
#include<string>
#include<cmath>

//using namespace std;
using namespace Numeric_lib;

double dot(const vector<double>& A, const vector<double>& B);
const double pi = 3.14159265359;

class AccelerationVector;
class GyroVector;

double scorePercentage(const double tilt_angle, const vector<double>& acceleration);
double scorePercentage(const double tilt_angle, AccelerationVector acceleration);

void init_DCM_Matrix(Matrix<double,2>& DCM);
void updateDCM(Matrix<double,2>& DCM, GyroVector gyro, double ts);
void updateDCM(Matrix<double,2>& DCM, double omega_x, double omega_y, double omega_z, double ts);
AccelerationVector convertAccToEarthFrame(Matrix<double,2>& DCM, AccelerationVector raw);
void convertAccToEarthFrame(Matrix<double,2>& DCM, const vector<double>& raw, vector<double>& earth_frame);





class AccelerationVector
{
public:
	double x;
	double y;
	double z;

	AccelerationVector();
	AccelerationVector(double, double, double);
	AccelerationVector(Reading);

	void printAcceleration();

};


class GyroVector
{
public:
	double x;
	double y;
	double z;

	GyroVector();
	GyroVector(double,double,double);
	GyroVector(Reading);

	void printGyro();
};









#endif /* PROJECT_ANALYSIS_H_ */
