#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

double sum;
double mean;
vector<double> pi;

void sort_of_vector(vector <double> &pi_vec )
{

   sort(pi_vec.begin(), pi_vec.end());
   cout << "The dataset after sorted is:\n";
   for(unsigned int i=0; i < pi_vec.size();i++)
	{
			cout <<pi_vec[i]<<" ";
			sum += pi_vec[i];
	}
	cout <<"\n";
	int tmp_cnt = 1,mode_cnt = 1;
	int mode;
	for(unsigned int i = 0;i < pi.size(); ++i)
		{
			if (pi[i] == pi[i-1]){
				tmp_cnt+=1;
				if (tmp_cnt>mode_cnt){
					mode_cnt = tmp_cnt;
					mode = pi[i];
				}
			}
			else if (pi[i] != pi[i-1]){
				tmp_cnt = 1;
				if (tmp_cnt>mode_cnt){
					mode_cnt = tmp_cnt;
					mode = pi[i];
				}
			}
		}
	cout << "The mode is:"<<mode<<endl;;

}

void median (vector <double> &pi_vec )
{
	 int number;
		number=pi_vec.size();
	if(number % 2 == 0)

			cout << "The median is: "<<( pi_vec[number/2-1] + pi_vec[number/2])/2<<endl;
		else
			cout << "The median is: "<< pi_vec[number/2]<<"\n"<<endl;
}

void variance(vector <double> pi_vec, double mean)
{
   double sum=0;
	   for(unsigned int i = 0; i < pi_vec.size(); i++)
	   sum+= (pi_vec[i] - mean) *(pi_vec[i] - mean);
       cout << "The unbiased sample variance of the numbers is "
    		   <<sum/(pi_vec.size()-1) << endl;

}


int main() {

string dataset = "3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4  "
			"3 3 8 3 2 7 9 5 0 2 8 8 4 1 9 7 1 6 9 3 9 9 3 7 5 1";
	stringstream pi_digit(dataset);
		double digit;
		while(pi_digit >> digit ){
			pi.push_back(digit);
		}
    sort_of_vector (pi);
    mean = sum / pi.size();
    cout<< "the arithmetic mean is:"<< mean<<endl;
    median(pi);
    variance( pi, mean);

	return 0;
}



