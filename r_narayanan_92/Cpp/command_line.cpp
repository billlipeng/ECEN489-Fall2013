/*
 * command_line.cpp
 *
 *  Created on: Sep 18, 2013
 *      Author: Narayanan Rengaswamy
 */

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout; using std::endl;

int main(int argc, char *argv[]) {

	int a = atoi(argv[1]), b = atoi(argv[2]);
	int t = 0, *temp = &t, *r_a = &a, *r_b = &b ;
	int &ra = a, &rb = b, &rt = t;

	//Comment either of the 4-line blocks of code below to see desired result

	// Using Pointers
	*temp = *r_a;
	*r_a = *r_b;
	*r_b = *temp;
	cout << "The swapped values (using pointers) are: " << *r_a << " " << *r_b << endl;


	// Using References
	/*rt = ra;
	ra = rb;
	rb = rt;
	cout << "The swapped values (using references) are: " << ra << " " << rb << endl;*/

}
