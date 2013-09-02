#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	double number1;
	double number2;

	cout<<"Howdy, Welcome to MB's Number Extravaganza!!!"<<endl
		<<"Please enter your first number"<<endl;

	cin >> number1;

	cout<<"Fantastic! Now enter your second number!"<<endl;

	cin >> number2;

	cout<<"Abra Kadabra!"<<endl
		<<"(Adding Numbers)";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);

	cout<<"POOF!"<<endl
		<<number1<<" + "<<number2<<" = "<< number1 + number2<<endl<<endl;

}
