#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cerr<<"Too few arguments entered";
		return 1;
	}
	if(argc > 3)
	{
		cerr<<"Too many arguments entered";
		return 2;
	}

	int firstNumber = 0;
	int secondNumber = 0;

	//get the first number from the input
	stringstream stream((string)argv[1]);
	stream>>firstNumber;

	stringstream stream2((string)argv[2]);
	stream2>>secondNumber;

	//assign the pointers
	int* firstNumberPointer = &firstNumber;
	int* secondNumberPointer = &secondNumber;
	int* tempPointer = firstNumberPointer;

	//perform the pointer switch
	firstNumberPointer = secondNumberPointer;
	secondNumberPointer = tempPointer;

	//print out the reversed numbers
	cout<<*firstNumberPointer<<endl<<*secondNumberPointer<<endl;

}
