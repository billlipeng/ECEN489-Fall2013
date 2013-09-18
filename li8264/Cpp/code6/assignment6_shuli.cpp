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

void swap (int &v1, int &v2)
{
int tmp=v2;
v2=v1;
v1=tmp;
}
