/*
 * Assignment2_final.cpp
 *
 *  Created on: Sep 1, 2013
 *      Author: Brian
 */

#include "Assn2header.h"
//#include "Assn2Fns.cpp"

int main()
{

	cout<<"Please enter a 1 for application 1 and 2 for application 2"<<endl;
	int app_num;
	cin>>app_num;

	if (app_num==1)
			TempConversion();
	else if (app_num==2)
	{
		cout<<"Please enter two temperatures along with their scale"<<endl;
		cout<<"ie Enter 32 f for 32 degrees fahrenheit, 32 c for 32 degrees celsius, and 32 k for 32 degrees kelvin"<<endl;

		TemperatureData T1,T2;

		cin>> T1.temperature >> T1.scale>> T2.temperature>>T2.scale;
		TemperatureData largest_temp = TempCompare(T1,T2);
		cout<<"The larger temperature you entered is "<<largest_temp.temperature<<" "<<largest_temp.scale<<endl;
	}



	else cerr<<"Error, enter a 1 or 2"<<endl;


	return 0;

}


