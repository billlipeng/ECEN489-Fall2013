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

	const char *keywords[] = {"host","dbname","user","password"};
	const char *values[] = {"fulla.ece.tamu.edu","motor_team","motor_team_user","motor_team_password"};

	//
	const char *readTemp = "SELECT * FROM temp_readings";
	const char *readMotor = "SELECT * FROM motor_readings";


	PGconn *conn = PQconnectdbParams(keywords,values, 0);

	// Get temp_readings column data
	PGresult *TempResult = PQexec(conn, readTemp);
	int TempRow = PQntuples(TempResult); //stores number of rows in temp_readings
	//

	//
	vector<const char*> args;
	args.push_back("15");
	const char *readTempInfo = "SELECT arduino_id, temp_kelvin FROM temp_readings WHERE arduino_id=$1 ORDER BY reading_time_utc DESC NULLS LAST Limit 10";
	PGresult *TempInfo = PQexecParams(conn, readTempInfo, 1, NULL, &(args[0]), NULL, NULL, 0);

	int TempInfoRow = PQntuples(TempInfo); //stores number of rows in temp_readings

	for (int i=0; i < TempInfoRow; i++) {

	char *PrintTempInfo0 = PQgetvalue(TempInfo, i, 0);
	char *PrintTempInfo1 = PQgetvalue(TempInfo, i, 1);

	cout << "ID: "<< PrintTempInfo0 <<endl;
	cout << "Temp: " <<PrintTempInfo1 <<endl;
	}



    /* close the connection to the database and cleanup */
    PQfinish(conn);

    return 0;
}
