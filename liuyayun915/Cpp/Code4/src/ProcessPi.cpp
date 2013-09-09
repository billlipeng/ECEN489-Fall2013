#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;


string Pi = "3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4  3 3 8 3 2 7 9 5 0 2 8 8 4 1 9 7 1 6 9 3 9 9 3 7 5 1";


double sum;
double arithmetic_mean;
vector<double> vec_of_nums;




void Read_In_Elements()
{
	stringstream ss(Pi);
	double element;
	cout << "**************************** PI *********************************"<<endl;
	while(ss >> element ){
		vec_of_nums.push_back(element);
	}
}

/*void Print_All_Elements( vector<double> &temp_vec)
{
	auto pbeg = temp_vec.begin();
	while(pbeg != temp_vec.end())
	{
		cout << *pbeg++;
	}
	cout <<"\n"<<endl;

}*/

void Sort( vector<double> &temp_vec)
{


	cout << "It is sorting..."<<endl;
	sort(temp_vec.begin(), temp_vec.end());
	cout << "Sorted. The numbers in ascending order are:\n";
	for(unsigned int i =0; i < temp_vec.size();i++)
	{
			cout <<temp_vec[i]<<" ";
			sum += temp_vec[i];
	}
	cout <<"\n";

}

void Find_Median(vector<double> &temp_vec){
	int half_of_numbers;
	half_of_numbers = temp_vec.size()/2;

	if(temp_vec.size() % 2 == 0)// even

		cout << "The median of the numbers is "<<( temp_vec[half_of_numbers-1] + temp_vec[half_of_numbers])/2<<"."<<endl;
	else // odd
		cout << "The median of the numbers is! "<< temp_vec[half_of_numbers]<<".\n"<<endl;
}



void Find_Mode(vector<double> temp_vec, int *p, int *index)
{
 int cnt = 1, max_cnt = 1;
 bool at_least_two_mode= 0;
 *index = 0;
 for( unsigned int i = 0; i < temp_vec.size(); i++){
	 for(unsigned int j = i+1; j < temp_vec.size(); j++){
		 if( temp_vec[i] == temp_vec[j])
			 cnt ++;
	 at_least_two_mode = 1;
	 }

	 if(cnt > max_cnt){
		 max_cnt = cnt;
		 *index = 0;
		 p[*index] = temp_vec[i];
		 (*index)++;

	 }

	 else if(max_cnt == cnt){
		 p[*index] = temp_vec[i];
		 (*index)++;
	 }

	 cnt = 1;
 }
 if(! at_least_two_mode){
	 *index = 0;
	 for(int i = 0; i < temp_vec.size(); i++){
		p[*index] = temp_vec[i];
		(*index)++;
	 }
 }
}


void Calculate_Variance(vector<double> temp_vec, double mean)
{
   double sum_up;
   for(int i = 0; i < temp_vec.size(); i++)
	   sum_up += (temp_vec[i] - mean) *(temp_vec[i] - mean);

   cout << "The unbiased sample variance of the numbers is "<< sum_up/(temp_vec.size()-1)<<endl;

}


int main()
{
    int p[50];
    int index;
    double arithmetic_mean;
	Read_In_Elements();

	Sort(vec_of_nums);
    cout << "\n";
	arithmetic_mean = sum / vec_of_nums.size();// calculate the arithmetic mean
	cout <<"The arithmetic mean of the numbers is "<<setprecision(3)<<arithmetic_mean<<"."<<endl;

	Find_Median(vec_of_nums);       // find the median
    Calculate_Variance(vec_of_nums, arithmetic_mean);
	Find_Mode(vec_of_nums,p,&index); // find the mode
	cout <<"The mode of the numbers is ";
	for(int i = 0; i < index; i++)
		cout<< p[i]<<" ";
    cout<<".";
	return 0;
}
