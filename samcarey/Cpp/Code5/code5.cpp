#include <iostream>

using namespace std;

int main(){
	
	double num, den;

	top:
	try{
		cout << "Numerator: " << flush;
		cin >> num;
		cout << "Denominator: " << flush;
		cin >> den;
		if (den == 0)
			throw 1;
		cout << num << " / " << den << " = " << num/den << endl;
		cout << "Thanks and Gig 'em!" << endl;	
	}
	catch(int i){
		cout << "Denominator cannot be zero. Please try again." << endl;
		goto top;
	}
	
	return 0;
}
