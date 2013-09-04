#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

double StringToDouble(string s)
{
	double result = 0;

	int i = 0;
	for(i = 0; i < s.size(); i++)
	{
		if(s[i] == '.')
		{
			i = i + 1;
			string decimal = "";
			double decimalValue = 0;
			for(; i < s.size(); i++)
			{
				decimal.push_back(s[i]);
			}
			decimalValue = StringToDouble(decimal);
			for(int j = 0; j < decimal.size(); j++)
			{
				decimalValue = decimalValue / 10;
			}
			result = result + decimalValue;
			return result;
		}
		else
			result = result*10 + (s[i] - '0');
	}
	return result;
}

int main()
{
	vector<double> fahrenheitValues;
	vector<double> celsiusValues;

	cout<<"Please enter a Fahrenheit reading, and then press enter to store the value"<<endl
		<<"When you are finished enter anything but a number"<<endl;

	bool notFinished = true;
	double fahrenheitValue = 0;
	string fahrenheitString = "";

	while(notFinished)
	{
		cin >> fahrenheitString;
		if(fahrenheitString == ";")
			notFinished = false;
		else
		{
			fahrenheitValue = StringToDouble(fahrenheitString);
			fahrenheitValues.push_back(fahrenheitValue);
		}
	}
	cout<<"In Celsius:"<<endl;
	for(double d : fahrenheitValues)
	{
		celsiusValues.push_back((d - 32)*5/9);
		cout<<d<<" F = "<<celsiusValues[celsiusValues.size() - 1]<<" C"<<endl;
	}

}
