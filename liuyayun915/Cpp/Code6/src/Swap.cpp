#include <iostream>
#include <string>

using namespace std;

void swap_pointer(int *p1, int *p2);
void swap_reference(int &v1, int &v2);

int main()
{

	int integer1[2], integer2[2];

	cout<<"This part is implemented using pointers. Please input two integers.\n";
	cin >> integer1[0] >> integer1[1];
	swap_pointer(&integer1[0], &integer1[1]);
	cout<<"The swapped values are: "<<integer1[0]<<","<<integer1[1]<<"."<<endl;

	cout<<"This part is implemented using references. Please input two integers.\n\n";
	cin >> integer2[0]>> integer2[1];
	swap_reference(integer2[0],integer2[1]);
	cout<<"The swapped values are: "<<integer2[0]<<","<<integer2[1]<<"."<<endl;
	cout<<"Gig'em, Aggies!";
	return 0;
}

void swap_pointer(int *p1, int *p2){
	if(*p1 == *p2)
		return;
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

}

void swap_reference(int &v1, int &v2){
	if(v1 == v2)
		return;

	int tmp = v2;
	v2 = v1;
	v1 = tmp;
}
