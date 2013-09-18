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

void swap(int &r1, int &r2){
	int temp = r1;
	r1 = r2;
	r2 = temp;
}

int main (int argc, char** argv) {
	passArgv(argc,argv);
	
	cout<<"The input integers:   "<<value1<<" "<<value2<<endl;
	
	//do swap
	swap(value1, value2);
	cout<<"The swapped integers: "<<value1<<" "<<value2<<endl;		//print swapped values
    return 0;
}
