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
#include <conio.h>
#include <fstream>
#include "Reader.h"

using namespace std;


int main()
{
	Reader reader = Reader(8);
	//reader.TurnPrintOn();
	while(true)
	{
		system("cls"); //clears the console window
		Reading reading = reader.GetReading();
		reading.PrintReading();
	}
}
