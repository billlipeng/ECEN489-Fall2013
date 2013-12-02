/*
 * Reader.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: Michael
 */

#include "Reader.h"
#include "mainwindow.h"

Reader::Reader()
{
    _trialNumber = 0;
    _isLeftHand = true;
}

void Reader::SetTrialNumber(int trialNumber)
{
    _trialNumber = trialNumber;
}

int Reader::GetTrialNumber()
{
    return _trialNumber;
}

Reader::Reader(int comPortNumber, SensorType sensorType) {

    _sensorType = sensorType;
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
        cout << "Connection established with device on Com Port "<<comPortNumber<<endl;

    //delete previous file content
    ofstream file;
    file.open(_fileName);
    file<<"";
    file.close();

    _thread = pthread_t();
    SpinThread();
}

void Reader::SetRightHand()
{
    _isLeftHand = false;
}

void Reader::SetLeftHand()
{
    _isLeftHand = true;
}

bool Reader::IsLeftHand()
{
    return _isLeftHand == true;
}

bool Reader::IsRightHand()
{
    return _isLeftHand == false;
}

void* RunThread(void* threadArgument)
{

    Reader* reader = (Reader*)threadArgument;

    int dataLength = 256;
    int readResult = 0;
    ofstream file;
    file.open(reader->GetFileName(), ios::app);

    while(reader->GetSerial()->IsConnected())
    {
        //system("cls");
        char incomingData[dataLength];

        readResult = reader->GetSerial()->ReadData(incomingData,dataLength);
        string s = incomingData;

        if (readResult > 0)
        {
            reader->SetReading(Reading(incomingData, reader->GetSensorType()));

            if(reader->GetReading().GetErrorMessage() == "")
            {
                file<<"XAccel = "<<reader->GetReading().GetAccelerationXAxis()<<'\t'<<"YAccel = "<<reader->GetReading().GetAccelerationYAxis()<<'\t'<<"ZAccel = "<<reader->GetReading().GetAccelerationZAxis()<<'\t'<<"XGyro = "<<reader->GetReading().GetGyroXAxis()<<'\t'<<"YGyro = "<<reader->GetReading().GetGyroYAxis()<<'\t'<<"ZGyro = "<<reader->GetReading().GetGyroZAxis()<<endl;
                reader->PrintReading();
            }

        }

        char up_down[1] = {'1'};  // '0' is front_back, '1' is up_down
        char front_back[1] = {'0'};

        if (reader->GetTrialNumber() == 1) {  //RVLH
            if (reader->IsLeftHand())
                reader->GetSerial()->WriteData(front_back, 1);
            else
                reader->GetSerial()->WriteData(up_down, 1);
        }
        else if (reader->GetTrialNumber() == 2) {    //LVRH
            if (reader->IsLeftHand())
                reader->GetSerial()->WriteData(up_down, 1);
            else
                reader->GetSerial()->WriteData(front_back, 1);
        }

        Sleep(35);
    }
}

void Reader::SpinThread()
{
    //cout<<"WWWZZZZ"<<endl;
    int successful = pthread_create(&_thread, NULL, RunThread, (void*)this);

    if(successful)
        cout<<"Error Creating Thread For Com Port "<<_comPortNumber<<endl;
    else
        cout<<"Successfully Created Thread For Com Port "<<_comPortNumber<<endl;
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

SensorType Reader::GetSensorType()
{
    return _sensorType;
}

void Reader::SetFileName(string name)
{
    _fileName = name;

    ofstream file;
    file.open(_fileName);
    file<<"";
    file.close();
}
