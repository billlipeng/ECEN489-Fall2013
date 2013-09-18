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

	stringstream stream((string)argv[1]);

	int firstNumber = 0;
	int secondNumber = 0;

	stream>>firstNumber;
	stringstream stream2((string)argv[2]);
	stream2>>secondNumber;
	int* firstNumberPointer = &firstNumber;
	int* secondNumberPointer = &secondNumber;
	int* tempPointer = firstNumberPointer;

	firstNumberPointer = secondNumberPointer;
	secondNumberPointer = tempPointer;

	cout<<*firstNumberPointer<<endl<<*secondNumberPointer<<endl;

}
