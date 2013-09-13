#include<iostream>
#include<stdexcept>

using namespace std;

int main ()
{
	int num1, num2, num3;
	cout << "--Division Tool--" << endl;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "\nEnter second number: ";
	while (cin >> num2)
	{
		try
		{
			if (num2 == 0)
			throw runtime_error("\nError, second number cannot equal 0.");
			else break;
		}
		catch (runtime_error err)
		{
			cout << err.what();
			cout << "\nEnter a new number: ";
		
		}
	}
	num3 = num1/num2;
	cout << "\n" << num1 << " divided by " << num2 << " is " << num3;
	return 0;
}
