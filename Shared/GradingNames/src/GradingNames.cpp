//============================================================================
// Name        : GradingNames.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
	unsigned int AssignmentNumber = 0;
	cout << "Please Enter Assignment Number:" << endl;
	cin >> AssignmentNumber;

	std::srand (AssignmentNumber);

	std::vector<string> ecen489names;
	ecen489names.push_back("Taahir Ahmed");
	ecen489names.push_back("Brian Bass");
	ecen489names.push_back("Michael Bass");
	ecen489names.push_back("John Boyd");
	ecen489names.push_back("Samuel Carey");
	ecen489names.push_back("Clayton Crawford");
	ecen489names.push_back("Ashton Jackson");
	ecen489names.push_back("Shuli Li");
	ecen489names.push_back("Yayun Liu");
	ecen489names.push_back("Douglas Maunder");
	ecen489names.push_back("Zachary Partal");
	ecen489names.push_back("Narayanan Rengaswamy");
	ecen489names.push_back("Dipanjan Saha");
	ecen489names.push_back("Jeff Terrell");
	ecen489names.push_back("Desmond Uzor");
	ecen489names.push_back("Tengyan Wang");

	std::vector<string> ecen489graders;
	ecen489graders = ecen489names;

	unsigned int number1 = ecen489names.size();
	unsigned int number2;
	string name;

	while (number1 > 1)
	{
		number2 = std::rand() % number1; // 0 <= number2 <= number1
		number1 = number1 - 1;
		name = ecen489names[number1];
		ecen489names[number1] = ecen489names[number2];
		ecen489names[number2] = name;
	}

	std::cout << endl << "Grading Assignment:" << endl << endl;
	for (unsigned int index=0; index < ecen489names.size(); ++index)
	{
		std::cout << "Grader: " << ecen489graders[index];
		std::cout << " --> Student: " << ecen489names[index] << endl;
	}
	std::cout << endl;

}
