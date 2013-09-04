/*
 * Temp_Vector.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: ashton
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Temp>
void write_far(const vector<Temp>& FarReadings)
{
  cout << "These Fahrenheit temperatures have been stored in a vector of size " << FarReadings.size() << ":";
  cout << endl;
  for(int i=0; i < FarReadings.size(); i++)
	  cout << FarReadings[i] << " ";
  	  cout << endl;

  cout << "These Celsius temperatures have been stored in a vector of size " << FarReadings.size() << ":";
  cout << endl;
  for(int i=0; i < FarReadings.size(); i++)
      cout << (FarReadings[i] - 32) / 1.8 << " ";
      cout << endl;
}

int main()
{
  double UserInput;
  double UserInputCel;
  vector<double> FarReadings;

  cout << "Enter the Fahrenheit temperatures you wish to store, then type \"end\": " << endl;
  while ((cin >> UserInput) && UserInput != 'end')
      FarReadings.push_back(UserInput);
      write_far(FarReadings);
    //  write_cel(FarReadings);
  return 0;
}
