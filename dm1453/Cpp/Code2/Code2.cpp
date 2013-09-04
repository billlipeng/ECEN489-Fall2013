#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define n_temps 2

struct TemperatureData
{
	string scale;
	double temperature;
	int year;
} temps [n_temps];

void printdata (TemperatureData temp);

int main ()
{	
	string num1;
	string num2;
	int n, m;
	int t = -1000;
		
	cout << "--Temperature Data Entry System--" << endl;
	
	for (n=0; n<n_temps; n++)
	{
		cout << "Enter year: ";
		getline (cin,num1);
    	stringstream(num1) >> temps[n].year;
    	cout << "Enter temperature: ";
    	getline (cin,num2);
    	stringstream(num2) >> temps[n].temperature;
    	cout << "Enter scale: ";
    	getline (cin,temps[n].scale);
	}
	
	cout << "\nData Entered:\n";
	for (n=0; n<n_temps; n++)
		printdata (temps[n]);
		

	for (n=0; n<n_temps; n++) 
	{
		if(temps[n].temperature>t)
		{
		t=temps[n].temperature;
		m = n;
		}
	}
	
	cout << "\nThe Largest entry is:\n";
	cout << temps[m].year << " ";
	cout << temps[m].temperature;
	cout << " (" << temps[m].scale << ")" << endl;
	return 0;
}
	
void printdata (TemperatureData temp)
{
	cout << temp.year;
	cout << " " << temp.temperature;
	cout << " (" << temp.scale << ")" << endl;

}
