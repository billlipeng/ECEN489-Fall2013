#include <iostream>
using namespace std;

int main () {

	double temp1 = 0;
	double temp2 = 0;

	cout << "Enter first temperature: ";
	cin >> temp1;

	cout << "Enter second temperature: ";
	cin >> temp2;

	if (temp1 > temp2)
	{
		cout << temp1;
	}
	else
	{
		cout << "--------------------------" << endl;
		cout << "The larger temperature is " << temp2 << ".";
	}

	return 0;
}
