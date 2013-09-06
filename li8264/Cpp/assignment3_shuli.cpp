//============================================================================
// Name        : assignment3_shuli.cpp
// Author      : Shuli
// Version     :
// Copyright   : Code3
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;



int main() {
	double temp;
	double ic;
	vector <double> v_temp; //empty vector
	cout << "Please enter a sequence of temperature in Fahrenheit: please type in 'end' when finished" << endl;

	while (cin >> temp){
		v_temp.push_back(temp); // append temp to v_temp
	}

	cout<<"the temperatures entered in Fahrenheit are:" <<endl;
    for (double ix: v_temp)
   	cout<<ix<<"\n";
    cout<<endl;
    cout<<"the total number of temperatures is: "<<v_temp.size()<<endl;


    cout<<"the temperatures entered in Celsius are:" <<endl;
     for (double ix: v_temp){
    	ic = (ix-32)*5/9;
        cout<<ic<<endl;}
        cout<<"the total number of temperatures after processing is: "<<v_temp.size()<<endl;

	return 0;
}
