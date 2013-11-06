/*
 * Reader.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: Michael
 */

#include <fstream>
#include "Reader.h"
#include <QtDebug>

Reader::Reader() {}

Reader::Reader(int comPortNumber) {

	_comPortNumber = comPortNumber;
	_print = false;
	_fileName = "log.txt";

	string comPortNumberString = "";
	stringstream stringStream;
	stringStream << comPortNumber;
	stringStream>>comPortNumberString;
	string comPortString = "\\\\.\\COM" + comPortNumberString;

	char* comPortPointer = new char[comPortString.size() + 1];
	strcpy(comPortPointer, comPortString.c_str());

	//create serial port connection
	_serial = new Serial(comPortPointer);
	if (_serial->IsConnected())
            qDebug()  << "Connection established with device on Com Port "<<comPortNumber;

	//delete previous file content
	ofstream file;
    file.open(_fileName, ios_base::out);
	file<<"";
	file.close();

	_thread = pthread_t();
	SpinThread();
}

void* RunThread(void* threadArgument)
{
	Reader* reader = (Reader*)threadArgument;

	int dataLength = 256;
	int readResult = 0;
	ofstream file;
    file.open(reader->GetFileName(), ios_base::app);

	while(reader->GetSerial()->IsConnected())
	{
		char incomingData[dataLength];

		readResult = reader->GetSerial()->ReadData(incomingData,dataLength);
		string s = incomingData;

		if (readResult > 0)
		{
			reader->SetReading(Reading(incomingData));

			if(reader->GetReading().GetErrorMessage() == "")
			{
				file<<"XAccel = "<<reader->GetReading().GetAccelerationXAxis()<<'\t'<<"YAccel = "<<reader->GetReading().GetAccelerationYAxis()<<'\t'<<"ZAccel = "<<reader->GetReading().GetAccelerationZAxis()<<'\t'<<"XGyro = "<<reader->GetReading().GetGyroXAxis()<<'\t'<<"YGyro = "<<reader->GetReading().GetGyroYAxis()<<'\t'<<"ZGyro = "<<reader->GetReading().GetGyroZAxis()<<endl;
				reader->PrintReading();
			}

		}


		char dataToWrite[1] = {'1'};
		reader->GetSerial()->WriteData(dataToWrite, 1);

		Sleep(35);
	}
}

void Reader::SpinThread()
{
	int successful = pthread_create(&_thread, NULL, RunThread, (void*)this);

	if(!successful)
        qDebug() <<"Error Creating Thread For Com Port "<<_comPortNumber;
	else
        qDebug() <<"Successfully Created Thread For Com Port "<<_comPortNumber;
}

Serial* Reader::GetSerial()
{
	return _serial;
}

void Reader::SetReading(Reading reading)
{
	_reading = reading;
}

Reading Reader::GetReading()
{
	return _reading;
}

void Reader::PrintReading()
{
	if(_print)
		_reading.PrintReading();
}

void Reader::TurnPrintOn()
{
	_print = true;
}
void Reader::TurnPrintOff()
{
	_print = false;
}

string Reader::GetFileName()
{
	return _fileName;
}

void Reader::SetFileName(string name)
{
	_fileName = name;

    std::ofstream file;
    file.open(_fileName, std::ios_base::out);
	file<<"";
	file.close();
}
