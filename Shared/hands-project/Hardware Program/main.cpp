#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <stdlib.h>
#include "Reading.h"
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <conio.h>
#include <fstream>
#include "Reader.h"
//#include "Matrix.h"
//#include "MatrixIO.h"
#include "Project_Analysis.h"
//#include <Windows.h>
#include <Windows.h>

using namespace Numeric_lib;


int main()
{
	Reader reader = Reader(9, Ping);
	while(true)
	{
		Reading reading = reader.GetReading();
		cout<<reading.GetPingDistance()<<endl;
	}
	/*
	timeBeginPeriod(1);

	Reader reader = Reader(11);
	//reader.TurnPrintOn();
	Matrix<double,2> C(3,3);

	init_DCM_Matrix(C);

	double ts;

	DWORD last_time = timeGetTime();

	while(true)
	{
		system("cls"); //clears the console window
		Reading reading = reader.GetReading();

		DWORD start_time = timeGetTime();
		ts = (start_time-last_time)/1000.0;

		AccelerationVector acc_raw = AccelerationVector(reading);
		GyroVector gyro_raw = GyroVector(reading);

		updateDCM(C, gyro_raw,ts);
		AccelerationVector acc_earth = convertAccToEarthFrame(C,acc_raw);


		std::cout<<"Sampling Time: "<<ts<<endl;
		reading.PrintReading();
		acc_earth.printAcceleration();

		last_time = start_time;

	}

	timeEndPeriod(1);
	*/
}
