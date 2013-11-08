/*
 * AccelerationVector.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Brian
 */


#include "Project_Analysis.h"

AccelerationVector::AccelerationVector() {}
AccelerationVector::AccelerationVector(double X, double Y, double Z){x=X;y=Y;z=Z;}
AccelerationVector::AccelerationVector(Reading reading){
	x = reading.GetAccelerationXAxis();
	y = reading.GetAccelerationYAxis();
	z = reading.GetAccelerationZAxis();

}

GyroVector::GyroVector(){}
GyroVector::GyroVector(double X, double Y, double Z){x=X*pi/180.0;y=Y*pi/180.0;z=Z*pi/180.0;}
GyroVector::GyroVector(Reading reading) {
	x = reading.GetAccelerationXAxis()*pi/180.0;
	y = reading.GetAccelerationYAxis()*pi/180.0;
	z = reading.GetAccelerationZAxis()*pi/180.0;
}

void GyroVector::printGyro()
{
	std::cout<<"Gyro x: "<<x<<endl;
	std::cout<<"Gyro y: "<<y<<endl;
	std::cout<<"Gyro z: "<<z<<endl;
}

void AccelerationVector::printAcceleration()
{
	std::cout<<"Acc x: "<<x<<endl;
	std::cout<<"Acc y: "<<y<<endl;
	std::cout<<"Acc z: "<<z<<endl;
}

