#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int value1, value2;
int passArgv (int argc, char* argv[]){
	if(argc != 3){
		cout<<"Useage: input two integers to swap. "<<endl;
		return 0;
	}
	value1 = atoi(argv[1]);
	value2 = atoi(argv[2]);
	return 1;
}

void swap(int *p1, int *p2){
	*p1 = value2;
	*p2 = value1;
}

int main (int argc, char** argv) {
	passArgv(argc,argv);
	
	int *p1 = &value1;		//point to values
	int *p2 = &value2;
	cout<<"The input integers:   "<<*p1<<" "<<*p2<<endl;
	
	//do swap
	swap(*p1, *p2);
	cout<<"The swapped integers: "<<*p1<<" "<<*p2<<endl;		//print swapped values
    return 0;
}
