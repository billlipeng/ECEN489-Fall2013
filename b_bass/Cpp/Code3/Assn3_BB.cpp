
#include<iostream>
#include<string>
#include<vector>

using namespace std;
using std::vector;

int main()
{
	vector<double> temperatures;

	cout<<"Please enter a series of temperatures"<<endl;
	cout<<"When you are done, enter a non-numeric character to stop"<<endl;


	double var_temp;

	while(cin>>var_temp)
		temperatures.push_back(var_temp);

	int vec_size = temperatures.size();

	cout<<"The number of temperatures entered is "<<vec_size<<endl;;
	cout<<"These temperatures are :"<<endl;

	for (int n = 0;n<vec_size;++n)
		cout<<temperatures[n]<<endl;

	for (int n = 0;n<vec_size;++n)
		temperatures[n] = (temperatures[n]-32)*5.0/9.0;

	cout<<"The number of temperatures entered is "<<vec_size<<endl;;
	cout<<"These temperatures in celsius are :"<<endl;

	for (int n = 0;n<vec_size;++n)
		cout<<temperatures[n]<<endl;



	//The following worked fine in visual studio but not in Eclipse.
	//They also seem like they are not necessary in Eclipse but are in Visual for the console application

	//cout<<"Please enter any character to exit the program"<<endl;

	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//char c;
	//cin>>c;

	return 0;

}
