/*
 * Assn5_BB.cpp
 *
 *  Created on: Sep 10, 2013
 *      Author: Brian
 */

#include "Assn5_header.h"

using namespace std;
int Divide_numbers(int,int);

int main()
{
	cout<<"Please enter two integers "<<endl;
	int a,b;
	cin>> a >> b;

	Divide_numbers(a,b);

	cout<<"Thank you for your time"<<endl;

	return 0;
}

int Divide_numbers(int a,int b)
{
	try
	{
		if (b==0)
			throw domain_error("Cannot divide by zero, result undefined");
		double quotient = a/b;
		cout<<"The quotient of your two integers is "<<quotient<<endl;

	}	catch(domain_error &err)
		{
			cout<<err.what()
				<<"\n Try Again? Enter y or n"<<endl;
			char c;
			cin>>c;

			if (c=='y')
			{
				cout<<"Enter another divisor"<<endl;
				int d;
				cin>>d;
				Divide_numbers(a,d);
			}
			else
				cout<<"User has terminated program"<<endl;

		}
	return 0;
}










