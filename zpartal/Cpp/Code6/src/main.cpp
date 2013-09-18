/*
Zachary Partal
HW6 Code
ECEN 489
9/18/2013
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

// Pass into two pointers to swap
void swap_by_pointers(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Pass variables to swap by reference
void swap_by_reference(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main(int argc, char **argv) {
	// Convert char array values and store in ints
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	// First swap by pointers
	swap_by_pointers(&x, &y);
	cout << "Swap by pointers: " << x << " " << y << endl; // should result in 2 1

	// Then swap by reference
	swap_by_reference(x, y);
	cout << "Swap again by reference: " << x << " " << y << endl; // should swap back to original 1 2

	return 0;
}
