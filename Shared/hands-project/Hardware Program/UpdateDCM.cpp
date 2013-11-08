/*
 * UpdateDCM.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Brian
 */


#include"Project_Analysis.h"

void init_DCM_Matrix(Matrix<double,2>& DCM)
{
	if ((DCM.dim1() != 3)||(DCM.dim2()!=3)) {
		cerr<<"Error, DCM matrix should be 3x3"<<endl;
		return;
	}

	DCM(0,0) = 1.0;
	DCM(1,1) = 1.0;
	DCM(2,2) = 1.0;

	return;
}

void updateDCM(Matrix<double,2>& DCM, double omega_x, double omega_y, double omega_z, double ts)
{

	if ((DCM.dim1() != 3)||(DCM.dim2()!=3)) {
		cerr<<"Error, DCM matrix should be 3x3"<<endl;
		return;
	}

	Matrix<double,2> DCM_1 = DCM;

	DCM_1(0,0) = DCM(0,0) + ts * (omega_z * DCM(1,0) - omega_y * DCM(2,0));
	DCM_1(0,1) = DCM(0,1) + ts * (omega_z * DCM(1,1) - omega_y * DCM(2,1));
	DCM_1(0,2) = DCM(0,2) + ts * (omega_z * DCM(1,2) - omega_y * DCM(2,2));

	DCM_1(1,0) = DCM(1,0) + ts * (-omega_z * DCM(0,0) + omega_x * DCM(2,0));
	DCM_1(1,1) = DCM(1,1) + ts * (-omega_z * DCM(0,1) + omega_x * DCM(2,1));
	DCM_1(1,2) = DCM(1,2) + ts * (-omega_z * DCM(0,2) + omega_x * DCM(2,2));

	DCM_1(1,0) = DCM(2,0) + ts * (omega_y * DCM(0,0) - omega_x * DCM(1,0));
	DCM_1(1,1) = DCM(2,1) + ts * (omega_y * DCM(0,1) - omega_x * DCM(1,1));
	DCM_1(1,2) = DCM(2,2) + ts * (omega_y * DCM(0,2) - omega_x * DCM(1,2));

	DCM = DCM_1;

	return;
}

AccelerationVector convertAccToEarthFrame(Matrix<double,2>& DCM, AccelerationVector raw)
{
	if((DCM.dim1()!=3)||(DCM.dim2()!=3)) {
		cerr<<"Error, DCM MAtrix must be 3x3"<<endl;
		return raw;
	}

	AccelerationVector earth_frame = AccelerationVector(raw.x, raw.y, raw.z);
	earth_frame.x = DCM(0,0)*raw.x + DCM(1,0)*raw.y + DCM(2,0)*raw.z;
	earth_frame.y = DCM(0,1)*raw.x + DCM(1,1)*raw.y + DCM(2,1)*raw.z;
	earth_frame.z = DCM(0,2)*raw.x + DCM(1,2)*raw.y + DCM(2,2)*raw.z;

	return earth_frame;

}

void updateDCM(Matrix<double,2>& DCM, GyroVector gyro, double ts)
{

	if ((DCM.dim1() != 3)||(DCM.dim2()!=3)) {
		cerr<<"Error, DCM matrix should be 3x3"<<endl;
		return;
	}

	Matrix<double,2> DCM_1 = DCM;

	DCM_1(0,0) = DCM(0,0) + ts * (gyro.z * DCM(1,0) - gyro.y * DCM(2,0));
	DCM_1(0,1) = DCM(0,1) + ts * (gyro.z * DCM(1,1) - gyro.y * DCM(2,1));
	DCM_1(0,2) = DCM(0,2) + ts * (gyro.z * DCM(1,2) - gyro.y * DCM(2,2));

	DCM_1(1,0) = DCM(1,0) + ts * (-gyro.z * DCM(0,0) + gyro.x * DCM(2,0));
	DCM_1(1,1) = DCM(1,1) + ts * (-gyro.z * DCM(0,1) + gyro.x * DCM(2,1));
	DCM_1(1,2) = DCM(1,2) + ts * (-gyro.z * DCM(0,2) + gyro.x * DCM(2,2));

	DCM_1(1,0) = DCM(2,0) + ts * (gyro.y * DCM(0,0) - gyro.x * DCM(1,0));
	DCM_1(1,1) = DCM(2,1) + ts * (gyro.y * DCM(0,1) - gyro.x * DCM(1,1));
	DCM_1(1,2) = DCM(2,2) + ts * (gyro.y * DCM(0,2) - gyro.x * DCM(1,2));

	DCM = DCM_1;

	return;
}

void convertAccToEarthFrame(Matrix<double,2>& DCM, const vector<double>& raw, vector<double>& earth_frame)
{
	if((DCM.dim1()!=3)||(DCM.dim2()!=3)||(raw.size()!=3)||(earth_frame.size()!=3)) {
		cerr<<"Vectors or Matrix Dimensions not compatible"<<endl;
		return;
	}

	earth_frame[0] = DCM(0,0)*raw[0] + DCM(1,0)*raw[1] + DCM(2,0)*raw[2];
	earth_frame[1] = DCM(0,1)*raw[0] + DCM(1,1)*raw[1]+ DCM(2,1)*raw[2];
	earth_frame[2] = DCM(0,2)*raw[0] + DCM(1,2)*raw[1] + DCM(2,2)*raw[2];

	return;
}
