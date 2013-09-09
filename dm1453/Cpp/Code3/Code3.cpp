#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n, t, num, size;
	vector<int> tempvec;
	
	cout << "Begin data entry, enter 1337 to stop";
	cout << "\nEnter temperatures in Fahrenheit:" << endl;
	cin >> t;
	while (t != 1337)
	{
		tempvec.push_back(t);
		cin >> t;		
	}
	size = tempvec.size();
	cout << "\nYou have " << size << " Fahrenheit entries: " << endl;
		
	for (int i : tempvec)
	{
    	cout << i << "\t";
	}
		
	for (int& i : tempvec)
	{
    	i = i - 32;
    	i = i * 5 / 9;
	}
	
	size = tempvec.size();
	cout << "\n\n" << size << " entries converted to Celsius: " << endl;
		
	for (int i : tempvec)
	{
    	cout << i << "\t";
	}
	
	return 0;
}
