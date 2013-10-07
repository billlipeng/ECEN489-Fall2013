#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argi, char *arg[]) {

	int a = atoi(arg[1]), b = atoi(arg[2]);
	int t = 0, *temp = &t, *r_a = &a, *r_b = &b ;
	int &ra = a, &rb = b, &rt = t;
	

	rt = ra;
	ra = rb;
	rb = rt;
	cout << "The swapped values are: " << ra << " " << rb << endl;
}
