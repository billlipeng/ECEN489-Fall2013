#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <exception>

using namespace std;

int main()
{

	float dividend, divisor;
    char err;
	cout << "Please input the dividend and divisor. :)";
	while(cin >> dividend >> divisor){
		try{
         if(divisor != 0){
        	 cout <<"Valid. The result is ";
        	 cout <<setprecision(2)<<dividend/divisor<<"."<<endl;
         }
         else
        	 throw err;
		} catch(char err){
			cout << "Oh, divisor should not be zero! Try Again!"<<endl;

		}
	}
}
