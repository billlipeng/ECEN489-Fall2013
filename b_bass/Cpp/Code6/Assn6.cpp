/*
 * Assn6.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: Brian
 */




#include "Assn6_header.h"



int main(int argc, char* argv[])
{
	if (argc < 2)
		cout<<"No function arguments were given"<<endl;

	else if (argc != 3)
			cout<<"There are not two integers to swap!"<<endl;
	else {
		//Uncomment this first line to use the function that uses pointers
		//Variable_Swap_Pointer(argv[1],argv[2]);
		int A = atoi(argv[1]);
		int B = atoi(argv[2]);

		int &A_ref = A;
		int &B_ref = B;

		cout<<"You entered the variables A:"<<A<<" and B:"<<B<<endl;

		Variable_Swap_Reference(A,B);

		cout<<"Now they have been swapped, and A:"<<A<<" and B:"<<B<<endl;
	}

	return 0;
}

