/*
 * Temp_Vector_App1.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: ashton
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TemperatureData {
	string scale;
	string temperature;
	string year;
};

int main()
  {
  vector<string> TempInfo;
  TemperatureData TempData;

cout << "Enter a temperature, scale, and year. Separate values with spaces." << endl;
cin >> TempData.temperature >> TempData.scale >> TempData.year;


  // Add some strings.
  TempInfo.push_back( TempData.temperature );
  TempInfo.push_back( TempData.scale );
  TempInfo.push_back( TempData.year );

  // Display the strings to the user.
  cout << "The following has been stored in a vector of size " << TempInfo.size() << ": " << endl;
  for (size_t n = 0; n < TempInfo.size(); n++)
	  cout << TempInfo[n] << " ";
  cout << endl;

  return 0;
  }

