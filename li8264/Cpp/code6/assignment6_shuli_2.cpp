//============================================================================
// Name        : assignment6_shuli_2.cpp
// Author      : shuli
// Version     :
// Copyright   : Code6
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : assignment6_shuli.cpp
// Author      : shuli
// Version     :
// Copyright   : Code6
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int i,j;
	cout << "Please enter the first integral: " << endl;
		cin >> i;
		cout << "Please enter the first integral: " << endl;
		cin >> j;
		cout << "before swap():" <<i<<"," << j<<endl;
		swap(i, j);
		cout << "after swap(): " <<i<<"," << j<<endl;
	return 0;
}

void swap(int *v1, int *v2) {
	int a = *v1; //temporarily store content of val1 in a
	*v1 = *v2; //push content of val2 into val1
	*v2 = a;  //assign content of a (the previous content of val1) to val2
}

