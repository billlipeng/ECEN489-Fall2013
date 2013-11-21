/*
 * project_analysis_statistics.h
 *
 *  Created on: Nov 21, 2013
 *      Author: Brian
 */

#ifndef PROJECT_ANALYSIS_STATISTICS_H_
#define PROJECT_ANALYSIS_STATISTICS_H_

#include<sstream>
#include<iostream>
#include<fstream>
#include<libpq-fe.h>
#include<string>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<Windows.h>

using namespace std;



void fetchDataRecordScore(PGconn *conn, vector<double>&, string = "ANY", char = 'A', int = 0);
void fetchDataRecordRightScore(PGconn *conn, vector<double>&, string = "ANY", char = 'A', int = 0);
void fetchDataRecordLeftScore(PGconn *conn, vector<double>&, string = "ANY", char = 'A', int = 0);
void insertDataPoint(PGconn *conn, string, char, int, double, double, double);
double findMean(vector<double>&);
double findStandardDeviation(vector<double>&);
double findMedian(vector<double>&);
double findCorrelationCoefficient(vector<double>& operand1, vector<double>& operand2);
void findHistogram(const vector<double>& data, vector<int>& histogram, const int num_bins);

//void horizontalHandRotateCoordinates(double* new_coord[3], const double* old_coord[3]);
//void verticalHandRotateCoordinates(double* new_coord[3], const double* old_coord[3]);

PGconn* connectToDatabase();

double dot(const vector<double>& A, const vector<double>& B);
const double pi = 3.14159265359;

//struct AccelerationVector;
//struct GyroVector;

double scorePercentage(const double tilt_angle, const vector<double>& acceleration);
//double scorePercentage(const double tilt_angle, AccelerationVector acceleration);

/*void init_DCM_Matrix(Matrix<double,2>& DCM);
void updateDCM(Matrix<double,2>& DCM, GyroVector gyro, double ts);
void updateDCM(Matrix<double,2>& DCM, double omega_x, double omega_y, double omega_z, double ts);
//AccelerationVector ConvertAccToEarthFrame(Matrix<double,2>& DCM, AccelerationVector raw);
void ConvertAccToEarthFrame(Matrix<double,2>& DCM, const vector<double>& raw, vector<double>& earth_frame);
*/


/*

struct AccelerationVector
{
	double x;
	double y;
	double z;

	AccelerationVector();
	AccelerationVector(double, double, double);
	AccelerationVector(Reading);

};

AccelerationVector::AccelerationVector() {}
AccelerationVector::AccelerationVector(double X, double Y, double Z){x=X;y=Y;z=Z;}
AccelerationVector::AccelerationVector(Reading reading){
	x = reading.GetAccelerationXAxis();
	y = reading.GetAccelerationYAxis();
	z = reading.GetAccelerationZAxis();

	void PrintAcceleration();
}


struct GyroVector
{
	double x;
	double y;
	double z;

	GyroVector();
	GyroVector(double,double,double);
	GyroVector(Reading);

	void PrintGyro();
};

GyroVector::GyroVector(){}
GyroVector::GyroVector(double X, double Y, double Z){x=X*pi/180.0;y=Y*pi/180.0;z=Z*pi/180.0;}
GyroVector::GyroVector(Reading reading) {
	x = reading.GetAccelerationXAxis();
	y = reading.GetAccelerationYAxis();
	z = reading.GetAccelerationZAxis();
}


*/



#endif /* PROJECT_ANALYSIS_STATISTICS_H_ */
