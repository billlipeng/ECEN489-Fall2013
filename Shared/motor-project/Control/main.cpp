#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Reading.h"

using namespace std;

// application reads from the specified serial port and reports the collected data


int _tmain(int argc, _TCHAR* argv[])
{
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

		string test(incomingData);

		if (readResult > 0) {
			Reading reading = Reading(test);
			cout<<"Temperature = "<<reading.GetTemperature()<<endl<<reading.GetErrorMessage()<<endl;
			//cout << test << endl;
		}
		test = "";

		Sleep(300);
	}
	cin >> argc;
	return 0;
}
