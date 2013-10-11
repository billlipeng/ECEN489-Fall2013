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
				}
				else
					Sleep(10);
			}
		}

		char dataToWrite[1] = {'1'};
		SP->WriteData(dataToWrite, 1);

		Sleep(100);
	}

}




int _tmain(int argc, _TCHAR* argv[])
{
	canPrint = true;
	const int numberOfArduinos = 3;
	int comPorts [numberOfArduinos]= {3,4,5};

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
