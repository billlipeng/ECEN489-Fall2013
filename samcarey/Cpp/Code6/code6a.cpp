#include <iostream>

using namespace std;

void swap(int*, int*);

int main(){

	int int1, int2;
	cout << "Before swap..." << endl;
	cout << "Integer 1: " << flush;
	cin >> int1;
	cout << "Integer 2: " << flush;
	cin >> int2;
	swap(&int1, &int2);
	cout << "After swap..." << endl;
	cout << "Integer 1: " << int1 << endl;
	cout << "Integer 2: " << int2 << endl;
	cout << "Thanks and Gig 'em!" << endl;
	
	return 0;
}

void swap(int *int1, int *int2){
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}
