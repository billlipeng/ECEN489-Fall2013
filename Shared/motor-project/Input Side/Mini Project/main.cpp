#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Reading.h"
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <libpq-fe.h>

using namespace std;

// application reads from the specified serial port and reports the collected data
//how to enable pthread
//right cklick on the project in the project explorer -> properties -> c/c++ build -> Settings -> linker -> libraries -> add -> pthread -> ok -> rebuild
struct thread_data{
	int thread_id;
	char* message;
};

bool canPrint;

void *ArduinoConnection(void *threadArgument)
{


	cout << "Connecting to arduino..." << endl;

	int comPortNumber = *((int *)threadArgument);
	string comPortNumberString = "";
	stringstream stringStream;
	stringStream << comPortNumber;
	stringStream>>comPortNumberString;
	string comPortString = "\\\\.\\COM" + comPortNumberString;
	cout<<"Com Port String = "<<comPortString<<endl;

	char* comPortPointer = new char[comPortString.size() + 1];
	strcpy(comPortPointer, comPortString.c_str());

	Serial* SP = new Serial(comPortPointer);    // adjust as needed

	if (SP->IsConnected())
		cout << "Connection established with Arduino on Com Port "<<comPortNumber<<endl;

	const int dataLength = 256;
	int readResult = 0;

	// Connect to the Db
	const char* connect_args [] = {
			"host",
			"dbname",
			"user",
			"password"
	};
	const char* connect_values [] = {
			"fulla.ece.tamu.edu",
			"motor_team",
			"motor_team_user",
			"motor_team_password"
	};

	PGconn *conn = PQconnectdb("host=fulla.ece.tamu.edu dbname=motor_team user=motor_team_user password=motor_team_password");
	if(PQstatus(conn) != CONNECTION_OK)
	{
		cerr << "Could not connect to database." << endl;
		PQfinish(conn);
		return nullptr;
	}

	while(SP->IsConnected())
	{
		char incomingData[dataLength] = "";

		readResult = SP->ReadData(incomingData,dataLength);

		if (readResult > 0)
		{
			bool working = true;
			while(working)
			{
				if(canPrint)
				{
					canPrint = false;
					Reading reading = Reading(incomingData);
					cout<<"Temperature = "<<reading.GetTemperature()<<"       "<<reading.GetErrorMessage()<<endl;
					cout <<"ComPort = "<<comPortNumber<<endl<<endl;
					canPrint = true;
					working = false;

					if(reading.GetTemperature() != -1)
					{
						char *data_values[2];
						data_values[0] = new char [256];
						data_values[1] = new char [256];

						// Print the data values into the arrays
						stringstream valstream;
						valstream << comPortNumber << " "
								<< reading.GetTemperature();
						string arduino_id_string;
						string temperature_string;

						valstream >> arduino_id_string;
						valstream >> temperature_string;

						strncpy(data_values[0], arduino_id_string.c_str(), 256);
						strncpy(data_values[1], temperature_string.c_str(), 256);
						//int length[2] = {strlen(data_values[0]), strlen(data_values[1]);

						cout << "ID = " << data_values[0] << endl;
						cout << "Temp = " << data_values[1] << endl;

						// Write the data into the database.

						char *cmd = "INSERT INTO temp_readings(arduino_id, reading_time_utc, temp_kelvin) VALUES (";


						string sqlCommand = cmd;
						sqlCommand = sqlCommand + data_values[0] + ", 'NOW', " + data_values[1] + ")";

						cout << "sqlCommand = " << sqlCommand << endl;

						const char *command = sqlCommand.c_str();

						cout << command << endl;

						PGresult *op_result = PQexec(conn,command);

						if(PQresultStatus(op_result) != PGRES_COMMAND_OK)
						{
							cerr << " Error writing values to db." << endl;
							PQclear(op_result);
							PQfinish(conn);
							return NULL;
						}

						// Clean up the command result
						PQclear(op_result);

						// Clean up the data values
						delete [] data_values[0];
						delete [] data_values[1];
					}
				}
				else
					Sleep(10);
			}
		}

		char dataToWrite[1] = {'1'};
		SP->WriteData(dataToWrite, 1);

		Sleep(100);
	}

	 PQfinish(conn);

	return NULL;
}




int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Howdy!"<<endl;
	canPrint = true;

	cout<<"Please enter the number of arduinos: ";
	int numberOfArduinos;
	cin >> numberOfArduinos;

	vector<int> comPorts;
	for(int i = 0; i < numberOfArduinos; i++)
	{
		cout<<"Please enter the Com Port for arduino "<<i+1<<":";
		int comPort;
		cin>>comPort;
		comPorts.push_back(comPort);
	}

	vector<pthread_t> threads;
	struct thread_data threadData;
	for(int i = 0; i < numberOfArduinos; i++)
	{
		threads.push_back(pthread_t());
		int notSuccessful = pthread_create(&threads[i], NULL, ArduinoConnection, (void*)&comPorts[i]);

		if(notSuccessful)
			cout<<"Error Creating Thread For Com Port "<<comPorts[i]<<endl;
		else
			cout<<"Successfully Created Thread For Com Port "<<comPorts[i]<<endl;

	}

	while(true)
	{
	}

}
