#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	double total, mean, median, mode, var, sum;
	vector<double> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1};
	vector<double> vtemp;
	int size = vec.size();
	total = 0;
	mean = 0;
	median = 0;
	mode = 0;
	var = 0;
	sum = 0;
	int count = 0;
	
	cout << "The first fifty digits of pi are: " << endl;
	
		for (int i : vec)				//output vector
	{
    	cout << i << " ";
	}
	
		for (int j : vec)				//sum up entries
	{
    	total += j;
	}
	
	mean = total / vec.size();
	
	for (int k : vec)					//open outter loop
	{
		int local = 0;
    	for (int q : vec)				//open inner loop
		{
    		if (k == q)
    		++local;					//increment local count
		}
		if (local > count)
		{
		count = local;
		mode = k;						//set highest repeated entry to mode
		}
	}
	
	for (int n = 0; n < 10; n++)		//sort elements from lowest to highest
	{
		for (int m : vec)
		{
			if (m == n)
			vtemp.push_back(m);
		}
	}

	if (size % 2)						//if even number of elements average two middle
		median = vtemp[size/2];
	else
		median = (vtemp[(size/2)-1] + vtemp[size/2]) / 2;

	//for (int i : vtemp)				//output sorted vector
	//{
    //	cout << i << " ";
	//}
	
	for (int c : vec)					//sum of deviation squared
	{
    	sum += (c - mean)*(c - mean);
	}
	
	var = sum / (size - 1);
	
	cout << "\n\nThe mean is: " << mean << endl;
	cout << "\nThe mode is: " << mode << endl;
	cout << "\nThe median is: " << median << endl;
	cout << "\nThe sample varience is: " << var << endl;

		return 0;
}
