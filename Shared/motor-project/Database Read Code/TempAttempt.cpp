/*
 * TempAttempt.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: ashton
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <iostream>
#include <libpq-fe.h>
#include <sstream>
#include <vector>
using namespace std;

int
main(int argc, char **argv)
{
	// Values needed to make initial connection
	const char *keywords[] = {"host","dbname","user","password"};
	const char *values[] = {"fulla.ece.tamu.edu","motor_team","motor_team_user","motor_team_password"};

	// Initiate database connection with these values
	PGconn *conn = PQconnectdbParams(keywords,values, 0);

	// Parameter values needed in the queries below
	const char* paramValues[1];
	paramValues[0]= "15";
	const char* paramValues1[1];
	paramValues1[0]= "15";

	// Get 10 most current values of the two tables, where arduino ID is from paramValues
	const char *readTempInfo = "SELECT arduino_id, temp_kelvin from temp_readings WHERE arduino_id=$1 ORDER BY reading_time_utc DESC NULLS LAST Limit 10";
	const char *readMotorInfo = "SELECT arduino_id, motor_voltage from motor_readings WHERE arduino_id=$1 ORDER BY reading_time_utc DESC NULLS LAST Limit 10";

	// Submits a command, readTempInfo, to the server and waits for a result
	PGresult *TempInfo = PQexecParams(conn, readTempInfo, 1, NULL, paramValues, NULL, NULL, 0);
	PGresult *MotorInfo = PQexecParams(conn, readMotorInfo, 1, NULL, paramValues1, NULL, NULL, 0);

	// Get number of rows queried
	int TempInfoRow = PQntuples(TempInfo);
	int MotorInfoRow = PQntuples(MotorInfo);

	// For each row, print the temperature and id, then an average of the temps
	int TempSum = 0;
	for (int i=0; i < TempInfoRow; i++) {
	char *PrintTempInfo0 = PQgetvalue(TempInfo, i, 0);
	char *PrintTempInfo1 = PQgetvalue(TempInfo, i, 1);
	stringstream stringStream;
	stringStream<<PrintTempInfo1;
	int currentValue;
	stringStream>>currentValue;
	TempSum += currentValue;
	cout << "ID: "<< PrintTempInfo0 <<endl;
	cout << "Temp: " << PrintTempInfo1 <<endl;
	}
	TempSum = TempSum/TempInfoRow;
	cout<<"Avg: "<<TempSum<<endl;
	cout << endl;

	// For each row, print the motor voltage and id, then an average of the voltages
	int MotorSum = 0;
	for (int j=0; j < MotorInfoRow; j++) {
	char *PrintMotorInfo0 = PQgetvalue(MotorInfo, j, 0);
	char *PrintMotorInfo1 = PQgetvalue(MotorInfo, j, 1);
	stringstream stringStream;
	stringStream<<PrintMotorInfo1;
	int currentValue;
	stringStream>>currentValue;
	MotorSum += currentValue;
	cout << "ID: "<< PrintMotorInfo0 <<endl;
	cout << "Voltage: " <<PrintMotorInfo1 <<endl;
	}
	MotorSum = MotorSum/MotorInfoRow;
	cout<<"Avg: "<<MotorSum<<endl;
    /* close the connection to the database and cleanup */
    PQfinish(conn);

    return 0;
}
