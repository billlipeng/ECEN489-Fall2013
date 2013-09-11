//============================================================================
// Name        : assignment5_shuli.cpp
// Author      : shuli
// Version     :
// Copyright   : Code5
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
using namespace std;



int main() {

	cout<< "please enter two integers as a and b:"<<endl;
	double a;
    double b;
	while (cin>>a>>b){
    try{
    	double c=0.0;
    	c=a/b;
    	cout << a << " / " << b << " = " << c << endl;
    	if (b == 0)
    	throw 1;
        }catch(int i){
    		cout << "the denominator cannot be zero." <<"\n"<<endl;
    		cout <<"Would you like to try again? Enter y or n"<<"\n"<<endl;
    		char c;
    		cin>>c;

    		if(cin && c=='n')
    			break;
    		else
        		cout<< "please enter two integers as a and b again:"<<endl;
    			continue;
	                  }
      }
}
