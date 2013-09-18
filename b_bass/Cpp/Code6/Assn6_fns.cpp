/*
 * Assn6_fns.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: Brian
 */




#include "Assn6_header.h"

void Variable_Swap_Pointer(char* A, char* B)
{
	int B_int = atoi(B);
	int A_int = atoi(A);

	cout<<"The variables you entered are A:"<<*A<<" and B:"<<*B<<endl;

	char* temp = A;
	A = B;
	B = temp;

	int B_int_swap = atoi(B);
	int A_int_swap = atoi(A);

	cout<<"Now their values have been swapped, and they are A:"<<*A<<" and B:"<<*B<<endl;

}

void Variable_Swap_Reference(int &A, int &B)
{
	int temp = A;
	A = B;
	B = temp;

}
