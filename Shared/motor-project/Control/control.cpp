#include <string>
#include <sstream>
#include <iostream>
#include <postgresql/libpq-fe.h>
#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>
#include <stdlib.h>
#include "Reading.h"

using namespace std;

/* Close connection to database */
void CloseConn(PGconn *conn)
{
  PQfinish(conn);
  getchar();
}

/* Establish connection to database */
PGconn *ConnectDB()
{
  PGconn *conn = NULL;

  // Make a connection to the database

  conn = PQconnectdb("user=motor_team_user password=motor_team_password dbname=motor_team hostaddr=165.91.240.126 port=5432");

  // Check to see that the backend connection was successfully made
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cout << "Connection to database failed.\n";
    CloseConn(conn);
  }

  cout << "Connection to database - OK\n";

  return conn;
}

/* Fetch employee record and display it on screen */
void FetchTempRec(PGconn *conn)
{
  // Will hold the number of field in employee table
  int nFields;

  // Start a transaction block
  PGresult *res  = PQexec(conn, "BEGIN");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "BEGIN command failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Clear result
  PQclear(res);

  // Fetch rows from employee table
  res = PQexec(conn, "DECLARE emprec CURSOR FOR select * from temp_readings");
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "DECLARE CURSOR failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Clear result
  PQclear(res);

  res = PQexec(conn, "FETCH ALL in emprec");

  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    cout << "FETCH ALL failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Get the field name
  nFields = PQnfields(res);

  // Prepare the header with temperature table field name
  cout << "\nFetch temp record:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    // Next, print out the temperature record for each row
    for (int i = 0; i < PQntuples(res); i++)
    {
        for (int j = 0; j < nFields; j++)
            printf("%-30s", PQgetvalue(res, i, j));
        printf("\n");
    }
 
    PQclear(res);

    // Close the emprec
    res = PQexec(conn, "CLOSE emprec");
    PQclear(res);

    // End the transaction
    res = PQexec(conn, "END");

  // Clear result
    PQclear(res);
}

/* Append SQL statement and insert record into voltage table */
void InsertMotorRec(PGconn *conn, const char * arduino_id, const char * motor_voltage)
{
  // Append the SQL statment
  std::string sSQL;
  sSQL.append("INSERT INTO motor_readings (arduino_id, motor_voltage) VALUES ('");
  sSQL.append(arduino_id);
  sSQL.append("', '");
  sSQL.append(motor_voltage);
  sSQL.append("')");

 
  // Execute with sql statement
  PGresult *res = PQexec(conn, sSQL.c_str());

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Insert Motor Readings record failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Insert Motor Readings record - OK\n";

  // Clear result
  PQclear(res);
}

/* example json object: MAKE ARDUINO SEND JUST LIKE THIS
	{"arduino_id":1,"motor_voltage":2.5}
*/

void readFromArduino(int arduino_id, double motor_voltage) {

	cout << "Connecting to arduino..." << endl;

	Serial* SP = new Serial("\\\\.\\COM20");    // adjust as needed

	if (SP->IsConnected())
		cout << "Connection established with Arduino!!" << endl;	// Let us know the serial is connected


	int dataLength = 256;
	int readResult = 0;

	while(SP->IsConnected())
	{
		char incomingData[256] = "";			// don't forget to pre-allocate memory
		readResult = SP->ReadData(incomingData,dataLength);
		//cout << "Bytes read: " << readResult << endl;
		
		string JSONdata(incomingData);
		int fieldCounter = 0;
		for (int i = 0; i < JSONdata.size(); ++i) {
			char temp;
			temp = JSONdata[i];
			
			if (temp == ':') {
				if (fieldCounter == 0) {
					// then we know we are getting arduino_id
					sscanf(JSONdata.c_str(), "%d", &arduino_id);
					++fieldCounter; // increment field counter for next field (motor_voltage)
				} else if(fieldCounter == 1) {
					// then we know we're getting the voltage
					sscanf(JSONdata.c_str(), "%f", &motor_voltage);
					--fieldCounter; // reset field counter for next JSON object
					break; // we break from for loop because we should have parsed both JSON data fields by now
				} else cout <<"\nERROR PARSING JSON DATA\n\n";
			}
		}
		JSONdata = "";

		Sleep(300);
	}

}

void writeToArduino(int arduino_id, double avgTemperature) {
	
	cout << "Connecting to arduino..." << endl;

	Serial* SP = new Serial("\\\\.\\COM20");    // adjust as needed

	if (SP->IsConnected())
		cout << "Connection established with Arduino!!" << endl;	// Let us know the serial is connected


	int dataLength = 256;

	while(SP->IsConnected())
	{
		char sendingData[256] = "";			// don't forget to pre-allocate memory
		
		// create JSON data object to send to arduino
		stringstream JSONdata;
		JSONdata << "{\"arduino_id\":";
		JSONdata << arduino_id;
		JSONdata << ",\"motor_voltage\":";
		JSONdata << avgTemperature;
		JSONdata << "}";
		
		if (WriteData(JSONdata.c_str(), dataLength)) 
			cout << "\n Serial JSON Data Write Complete!\n";
		else cout <<"\nERROR Writing JSON Data Serially!\n";
		Sleep(300);
	}
	

}

int main(int argc, char *argv[]) // May need to change this to int _tmain(int argc, _TCHAR* argv[])
{
	int motor_arduino_id = 0;		// arduino id from getting motor reading through serial
	double motor_voltage = 0.0; 	// motor voltage reading from serial
	double avgTemperature = 0.0; 	// average temperature to send to arduino serially
	int temp_arduino_id = 0;		// arduino id of temperature sensor to send to arduino serially

  PGconn *conn = NULL;
 
  conn = ConnectDB();
 
  if (conn != NULL)
  {
	// Get AVG temperature reading from DB
	// assign returned arduino id to temp_arduino_id and returned temperature to avgTemperature
    FetchTempRec(conn);
	
	// Write Avg Temperature to the Arduino Serially
	writeToArduino(&temp_arduino_id, &avgTemperature); // EDIT APPROPRIATELY
	
	// Read the voltage reading from the Arduino Serially
	readFromArduino(&motor_arduino_id, &motor_voltage);
	
	// Insert voltage reading into DB
	InsertMotorRec(conn, motor_arduino_id,motor_voltage);
	
	/*	test DB insertions
    InsertMotorRec(conn, "1","2.4");
    InsertMotorRec(conn, "2","2.2");
    InsertMotorRec(conn, "2","3.0");
    CloseConn(conn); */
	
  }
  return 0;
}


