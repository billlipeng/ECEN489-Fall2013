//============================================================================
// Name        : Assignment4.cpp
// Author      : Desmond Uzor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//Function Prototypes
double Variance(vector<double> list, double mean);
double median(vector<double> list);
double average(vector<double> list);
void print_out (const vector<double>& v);


int main() {
	//50 digit value of pi is declared
	static const double pi[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3,
									5, 8, 9, 7, 9, 3, 2, 3, 8, 4,
									6, 2, 6, 4, 3, 3, 8, 3, 2, 7,
									9, 5, 0, 2, 8, 8, 4, 1, 9, 7,
									1, 6, 9, 3, 9, 9, 3, 7, 5, 1};

vector<double> numbers (pi, pi + sizeof(pi) / sizeof(pi[0]));
void print_out (const vector<double>& numbers);
 cout << "The median, mode and variance are  " << median(numbers) << " " << average(numbers)
		 << " "<< Variance(numbers, median(numbers));


return 0;
}

// Mean Function
double average(vector<double> list){
	double mean;
	double sum = 0;
	for (double i= 0; i <list.size(); ++i){
		sum = i + sum;
	}
	int size = list.size();
     mean = sum / size;
	return mean;
}

double median(vector<double> list){
	  size_t size = list.size();
	  double median;
	  sort(list.begin(), list.end());
	  if (size  % 2 == 0)
	  {
	      median = (list[size/2 - 1] + list[size/2]) / 2;
	  }
	  else {
	      median = list[size / 2];
	  }
	  return median;
}



double Variance(vector<double> list, double mean)
{
   double var;
	double sum = 0;
   for(unsigned int i = 0; i < list.size(); i++)
	   sum = (list[i] - mean) *(list[i] - mean);
   var = sum/(list.size()-1);
   return var;

}
// print out function
void print_out (const vector<double>& v){
  //vector<int> v;
  for (unsigned  i=0; i<v.size();i++){
    cout << v[i] << endl;
  }
}
