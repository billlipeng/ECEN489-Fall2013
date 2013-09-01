//============================================================================
// Name        : HelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

struct TemperatureData{
 std::string scale;
 double temperature;
 //int year
};



int main() {
	TemperatureData data;//data1, data2;
	std::string Temperature_scale;//Temperature_scale1, Temperature_scale2;
	//double Temperature_data;// Temperature_data1, Temperature_data2;
	//double Lagest_Temperature_data;

	//cout << " The scale of temperature is: F(Fahrenheit), C(Celsius) or K(Kelvin)?\n" << std::endl; // prints !!!Hello World!!!
    //cin  >> data.scale>>Temperature_scale;
    // getline(cin,Temperature_scale);
	 //Temperature_scale = getchar();
	cout << " The temperature is?" << endl;
    //cin  >> data.temperature >> Temperature_data;

    //cout << " The scale is" <<" "<< Temperature_scale<<endl;
   // cout << " The temperature is" << " "<< Temperature_data<< "\n"<<endl;

	return 0;
}
