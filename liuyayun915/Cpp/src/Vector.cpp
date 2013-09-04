#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;



float Temperature;
vector<float> Temperature_Vec;



void Read_In_Temperatures()
{

	cout<<"The temperatures in Fahrenheit are:\n"<<endl;
	while(cin >> Temperature){
		Temperature_Vec.push_back(Temperature);
	}

}

void Print_Vector(vector<float> ivec)
{
	int ix;
	if(ivec.empty()) return;
	for(ix=0; ix < ivec.size(); ++ix)
		cout << setprecision(3)<<ivec[ix] << "¡ãF"<<" ";
	cout<<"\n";
	cout<<"The vector contains "<< ix<<" "<<"elements.\n"<<endl;
}

void Process_Vector_And_Print_It(vector<float> tempvec)
{
	int element_cnt;
	cout<<"The temperatures in Celsius are:"<<endl;
	for(auto &element : tempvec){
		element_cnt++;
		element = (element-32) * 5/9;
	}

	for(auto element : tempvec){
		cout << setprecision(3)<<element<<"¡ãC"<<" ";
	}
    cout<<"\n";
	cout<<"After processing, the vector contains "<<element_cnt<<
			" "<<"new elements."<<endl;

}




int main()
{


    Read_In_Temperatures();
    Print_Vector(Temperature_Vec);
    Process_Vector_And_Print_It(Temperature_Vec);

	return 0;
}
