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
#include <conio.h>

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

	cout<<"YO YO YO"<<endl;
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

	//char dataToWrite[5] = {'#','o','s','c','t'};
	//SP->WriteData(dataToWrite, 5);

	const int dataLength = 256;
	int readResult = 0;

	//char dataToWrite[1] = {'2'};
	//SP->WriteData(dataToWrite, 1);

	PGconn *conn = PQconnectdb("host=fulla.ece.tamu.edu dbname=hand user=hand_user password=hand_password");
	if(PQstatus(conn) != CONNECTION_OK)
	{
		cerr << "Could not connect to database." << endl;
		PQfinish(conn);
		return nullptr;
	}

	while(SP->IsConnected())
	{
		system("cls");
		char incomingData[dataLength] = "";

		readResult = SP->ReadData(incomingData,dataLength);
		string s = incomingData;
		cout<<s<<endl;


		if (readResult > 0)
		{
			bool working = true;
			while(working)
			{
				if(canPrint)
				{
					canPrint = false;
					Reading reading = Reading(incomingData);
					cout<<"XAxis = "<<reading.GetAccelerationXAxis()<<"       "<<reading.GetErrorMessage()<<endl;
					cout<<"YAxis = "<<reading.GetAccelerationYAxis()<<"       "<<reading.GetErrorMessage()<<endl;
					cout<<"ZAxis = "<<reading.GetAccelerationZAxis()<<"       "<<reading.GetErrorMessage()<<endl;
					cout<<"Ya = "<<reading.GetYa()<<"       "<<reading.GetErrorMessage()<<endl;
					cout<<"Pitch = "<<reading.GetPitch()<<"       "<<reading.GetErrorMessage()<<endl;
					cout<<"Roll = "<<reading.GetRoll()<<"       "<<reading.GetErrorMessage()<<endl;
					cout <<"ComPort = "<<comPortNumber<<endl<<endl;
					canPrint = true;
					working = false;

					if(reading.GetErrorMessage() == "")
					{
						// Write the data into the database.

						stringstream stringStream;
						stringStream << reading.GetAccelerationXAxis()<< " " <<reading.GetAccelerationYAxis()<<" " <<reading.GetAccelerationZAxis()<<" " <<reading.GetYa()<<" "<<reading.GetPitch()<<" "<<reading.GetRoll();
						string accelerationXAxisString = "";
						stringStream >> accelerationXAxisString;
						string accelerationYAxisString = "";
						stringStream >> accelerationYAxisString;
						string accelerationZAxisString = "";
						stringStream >> accelerationZAxisString;
						string yaString = "";
						stringStream >> yaString;
						string pitchString = "";
						stringStream >> pitchString;
						string rollString = "";
						stringStream >> rollString;

						string sqlCommand = "INSERT INTO imu_moving_up_then_down_on_hand";
												sqlCommand += "(acceleration_x, acceleration_y, acceleration_z, ya, pitch, roll, time_stamp)";
												sqlCommand += " VALUES (";
												sqlCommand += accelerationXAxisString;
												sqlCommand += ",";
												sqlCommand += accelerationYAxisString;
												sqlCommand += ",";
												sqlCommand += accelerationZAxisString;
												sqlCommand += ",";
												sqlCommand += yaString;
												sqlCommand += ",";
												sqlCommand += pitchString;
												sqlCommand += ",";
												sqlCommand += rollString;
												sqlCommand += ",";
												sqlCommand += "'NOW'";
												sqlCommand += ")";

						cout << "sqlCommand = " << sqlCommand << endl;
						PGresult *op_result = PQexec(conn,sqlCommand.c_str());

						if(PQresultStatus(op_result) != PGRES_COMMAND_OK)
						{
							cerr << " Error writing values to db." << endl;
							PQclear(op_result);
							PQfinish(conn);
							return NULL;
						}

						PQclear(op_result);

					}
				}
				else
					Sleep(10);
			}
		}


		char dataToWrite[1] = {'1'};
		SP->WriteData(dataToWrite, 1);

		Sleep(35);
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
