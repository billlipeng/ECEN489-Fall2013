//============================================================================
// Name        : Assignment6.cpp
// Author      : Desmond Uzor
// Version     :
// Copyright   : Do What You Must
// Description : Swap Numbers Program
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *firstNum, int *secondNum);
int main(int argc, char **argv) {
	 int firstNumber = atoi(argv[0]); // Numbers are converted from char to Integer
	 int secondNumber = atoi(argv[1]);
	swap(&firstNumber, &secondNumber); // Swap function is used
	 return 0;
}

void swap(int *firstNum, int *secondNum){
		int a= *firstNum; // firstNum is temporarily stored
		*firstNum = *secondNum; // then it is replaced and switched
		*secondNum = a;
		cout << "Numbers in reverse are "<< firstNum <<" and " << secondNum << endl;


}
