/*
 * try_catch.cpp
 *
 *  Created on: 2013Äê9ÔÂ10ÈÕ
 *      Author: Tengyan Wang
 */

#include<iostream>

using namespace std;

int main(){
	cout<<"Input first number:"<<endl;
	int val1, val2;
	cin>>val1;
	cout<<"Input second number:"<<endl;
	cin>>val2;
	try{
		if(val2 == 0)
			throw val2;
		cout<<"Result for first number/second number: "<<val1/val2<<endl;
	} catch (int val2){
		cout<<"Second number can't be '0'. Need a new second number:"<<endl;
		cin>>val2;
		if(val2 == 0){
			cout<<"Second number can't be '0'. Need a new second number:"<<endl;
			cin>>val2;
		}
		cout<<"New result for first number/second number: "<<val1/val2<<endl;
	}
	return 0;
}



