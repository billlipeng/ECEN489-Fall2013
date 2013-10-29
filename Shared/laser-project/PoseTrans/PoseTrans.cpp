/* 
*	This program uses the Armadillo linear algrebra library
*	for the matrix math operations and the jsoncpp
*	JSON library for outputting data to the Visualization module.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <string.h>
#include <json/json.h>
#include <string>
#include <armadillo>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;
using namespace arma;
using namespace Json;

struct termios tty;
struct termios tty_old;

int USB; // holds tty port info for reading

void serialPortSetup() {
	// begin serial port setup code

	memset(&tty, 0, sizeof(tty));

	tty_old = tty;
	
	cfsetospeed(&tty, (speed_t)B9600);
	cfsetispeed(&tty, (speed_t)B9600);

	tty.c_cflag		= CS8 | CREAD | CLOCAL;
	tty.c_cc[VMIN]	= 1;
	tty.c_cc[VTIME]	= 10;
	cfmakeraw(&tty);
	fcntl(USB, F_SETFL, O_NONBLOCK);
	// end serial port setup code
}

void readSerialPort() {
	USB = open("/dev/tty1", O_NOCTTY | O_RDONLY, 0640);
	printf("USB = %d\n", USB);
	if (USB == -1) {
		printf("\n open() failed with error [%s]\n",strerror(errno));
	}

	tcflush(USB, TCIFLUSH);
	if (tcsetattr(USB, TCSANOW, &tty) != 0) {
		printf("\n tcsetattr() failed with error [%s]\n",strerror(errno));
	}
	close(USB);
}

int main () {

	// testing with Armadillo matrices
	cout << "\nMatrix Multiplication Test!\n";
	mat m1(4,4); // 4x4 matrix
	mat m2(4,1); // 4x1 matrix
	mat result(4,1); // 4x1 matrix 

	// fill matrix m1 with random info except last row is 0 0 0 1
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != 3)
	  			m1(i, j) =  i * 10;
	  		else if (i == 3 && j != 3)
	  			m1(i, j) = 0;
	  		else 
	  			m1(i, j) = 1;
		}
	}

	// fill matrix m2 with all 2's
  	for (int i = 0; i < 4; ++i) {
  		m2(i, 0) = 2;
  	}

  	result = m1 * m2;
  	cout << "M1 [4x4]\n" << m1 << endl;
  	cout << "M2 [4x1]\n" << m2 << endl;
  	cout << "Result [4x1]\n" << result << endl;

  	// generate sample JSON data file (emulate serial data from microcontroller)
  	Value poseTransInput;

  	srand(time(NULL));
  	for (int i = 0; i < 50; ++i) {
  		poseTransInput["x1\'"] = rand() % 10;
  		poseTransInput["x2\'"] = rand() % 10;
  		poseTransInput["x3\'"] = rand() % 10;
  		poseTransInput["y1\'"] = rand() % 10;
  		poseTransInput["y2\'"] = rand() % 10;
  		poseTransInput["y3\'"] = rand() % 10;
  		poseTransInput["z1\'"] = rand() % 10;
  		poseTransInput["z2\'"] = rand() % 10;
  		poseTransInput["z3\'"] = rand() % 10;
  		poseTransInput["r1"] = rand() % 10;
  		poseTransInput["r2"] = rand() % 10;
  		poseTransInput["r3"] = rand() % 10;

  		FastWriter fw;
  		string poseInputJSON = fw.write(poseTransInput);

  		FILE *f = fopen("PoseTransInput", "a");
  		if (f == NULL) {
  			printf("\nError opening file!\n");
  			exit(1);
  		}
  		fprintf(f, "%s", poseInputJSON.c_str());
  		fclose(f);
  	}

  	Value PoseJSONobj;
  	Reader reader;
  	ifstream ifs("PostTransInput", ifstream::in);
  	vector<Value> JSONobjsVector;
  	string JSONobj;
  	char test;
  	int counter = 0;
  	while (!ifs.eof()) {
  		cout << counter++ << endl;
  		ifs >> test;
  		if (test == '}') {
  			bool parsingSuccessful = reader.parse(JSONobj, PoseJSONobj, false);
  			if (!parsingSuccessful) {
  				cout << reader.getFormatedErrorMessages();
  			} else JSONobjsVector.push_back(PoseJSONobj);
  		} else if (test != '}') {
  			JSONobj += test;
  		} else { cout << "\nError parsing!\n"; exit(1);}

  	}
  	
  	StyledWriter sw;
  	for (int i = 0; i < JSONobjsVector.size(); ++i) {
  		cout << sw.write(JSONobjsVector[i]);
  	}

  	return 0;
}
