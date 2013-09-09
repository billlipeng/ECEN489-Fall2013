#include "PiVector.h"
#include <vector>
#include <iostream>
#include<cmath>

using namespace std;

vector<double> BubbleSort(vector<double> d)
{
	for(int i = 0; i < d.size(); i++)
	{
		for(int j = 0; j < d.size() - i - 1; j++)
		{
			if(d[j] > d[j + 1])
			{
				double temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}

	return d;
}

double Mode(vector<double> d)
{
	vector<int> numbers;
	for(int i = 0; i < 10; i++)
	{
		numbers.push_back(0);
	}

	for(int i = 0; i < d.size(); i++)
	{
		numbers[d[i]]++;
	}

	int max = -1000;
	int secondMax = -2000;
	int maxPosition = -1;
	for(int i = 0; i < numbers.size(); i++)
	{
		if(numbers[i] > max)
		{
			maxPosition = i;
			secondMax = max;
			max = numbers[i];
		}
	}

	if(max == secondMax)
		return -1;
	return maxPosition;
}

//not certain I used the correct formula....
double UnbiasedSampleVariance(vector<double> d, double mean)
{
	double innerSum = 0;
	for(int i = 0; i < d.size(); i++)
	{
		innerSum += pow(d[i] - mean,2);
	}
	innerSum /=(d.size() - 1);
	return sqrt(innerSum);
}

int main()
{
	vector<double> piVector = BubbleSort(CreatePiVector());

	cout<<"The first 50 digits of pi are:"<<endl;

	double mean = 0;
	for(int i = 0; i < piVector.size(); i++)
	{
		cout<<piVector[i]<<endl;
		mean += piVector[i];
	}

	mean = mean/piVector.size();
	double median = (BubbleSort(piVector)[piVector.size()/2] + BubbleSort(piVector)[piVector.size()/2])/2;
	cout<<endl<<"The arithmetic mean is:"<<endl<<mean<<endl;
	cout<<endl<<"The median is:"<<endl<<median<<endl;
	if(Mode(piVector) == -1)
		cout<<endl<<"There is no mode, two numbers occur with the same frequency"<<endl;
	else
		cout<<endl<<"The mode is:"<<endl<<Mode(piVector)<<endl;
	cout<<endl<<"The Unbiased Sample Variance is:"<<endl<<UnbiasedSampleVariance(piVector, mean)<<endl;

}



