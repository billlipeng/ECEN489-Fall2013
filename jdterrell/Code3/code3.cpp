/*
 * code3.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: Jeff
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {


	vector<double> ftemp;
	vector<double> ctemp;
	double inputF = 0;

	cout<<"Please enter a Fahrenheit reading, and then press enter to store the value"<<endl
		<<"When you are finished, type 'end' and press enter"<<endl;

	//bool done = false;

	//string fahrenheitString = "";

	while(cin>>inputF)
	{
		cin >> inputF;
//		if (isalpha(inputF))
		ftemp.push_back(inputF);


	}

	cout << "Number of stored temperatures: " << ftemp.size() << endl;



	for(double i; i<ftemp.size(); i++)
	    {
	        cout << ftemp[i] << " ";
	    }


	return 0;
}
