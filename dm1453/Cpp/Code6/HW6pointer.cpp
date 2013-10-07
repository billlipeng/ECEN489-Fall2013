#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argi, char *arg[]) {

	int a = atoi(arg[1]), b = atoi(arg[2]);
	int t = 0, *temp = &t, *r_a = &a, *r_b = &b ;
	int &ra = a, &rb = b, &rt = t;

	*temp = *r_a;
	*r_a = *r_b;
	*r_b = *temp;
	cout << "The swapped values are: " << *r_a << " " << *r_b << endl;

}
