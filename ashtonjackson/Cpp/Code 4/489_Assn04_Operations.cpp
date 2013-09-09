#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<fstream>
#include<numeric>
#include<iterator>
#include<cmath>
using namespace std;

int main() {
	vector<double> PiVals;
	char buffer[51];
	char buffer1[51];

	//Insert Pi Digits
	ifstream pifile("pi.txt");
		copy(istream_iterator<double>(pifile),
		istream_iterator<double>(),
		back_inserter(PiVals));
	//Get Size of pi; print size & digits
	int Size = PiVals.size();
	cout << "The first " << Size << " numbers in the decimal expansion of pi are:";
	cout << endl;
	for(int i=0; i < Size; i++)
	  cout << PiVals[i] << " ";
  	  cout << endl;

  	 //Calculate and Display the Mean:
  	 double Sum = 0;
  	 double Diff = 0;
  	 double SV = 0;
  	 for(int i=0; i<51; i++)
  	 {
  		 if(buffer[i]!=46)
			{
				double a = static_cast<double> (buffer[i]-'0');
				PiVals.push_back(a);
			}
  	 }

  	 for(int j=0; j<Size; j++)
  	 Sum = Sum + PiVals[j];
  	 double Mean = Sum/Size;
  	 cout << "Mean: " << Mean;
  	 cout << endl;



  	 //Calculate and Display the Median:
   	 if (Size % 2 == 0) {
   		  cout << "Median: " << (PiVals[(Size-1)/2] + PiVals[Size/2]) / 2; //Works only for even #s of digits
   		  cout << endl;
   	 }
   	 else {
   		  cout << "Median: " << (PiVals[Size/2]); //Works only for odd #s of digits
   		  cout << endl;
   	  }

   	 //Calculate and Display the Mode:
   	 std::vector<int> Mode(51,0);
   	 for(int k = 0; k < 50; ++k )
   		 ++Mode[PiVals[k]];
   	 	 cout<<"Mode: "<<(max_element(Mode.begin(),Mode.end())-Mode.begin()) << endl;

   	  //Calculate and Display the Sample Variance:
   	  	 for(int m=0; m<51; m++)
   	  	 {
   	  		 if(buffer1[m]!=46)
   				{
   					double b = static_cast<double> (buffer1[m]-'0');
   					PiVals.push_back(b);
   				}
   	  	 }

   	  	 for(int l=0; l<Size; l++)
   	  	 Diff = abs (Mean - PiVals[l]) * abs (Mean - PiVals[l]);
   	  	 SV = Diff/Mean;
   	  	 cout << "Sample Variance: " << SV;
   	   	 cout << endl;
   	 return 0;
}
