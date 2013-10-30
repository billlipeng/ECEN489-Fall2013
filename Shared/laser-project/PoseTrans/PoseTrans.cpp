/* 
*	This program uses the Armadillo linear algebra library
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

  	// generate sample JSON data file (emulate serial data from microcontroller)
  	Value poseTransInput;

  	srand(time(NULL));
  	FILE *f = fopen("PoseTransInput", "w");
  	for (int i = 0; i < 5; ++i) {
  		poseTransInput["x1\'"] = rand() %10 + 1;
  		poseTransInput["x2\'"] = rand() %10 + 1;
  		poseTransInput["x3\'"] = rand() %10 + 1;
  		poseTransInput["y1\'"] = rand() %10 + 1;
  		poseTransInput["y2\'"] = rand() %10 + 1;
  		poseTransInput["y3\'"] = rand() %10 + 1;
  		poseTransInput["z1\'"] = rand() %10 + 1;
  		poseTransInput["z2\'"] = rand() %10 + 1;
  		poseTransInput["z3\'"] = rand() %10 + 1;
  		poseTransInput["r1"] = rand() %10 + 1;
  		poseTransInput["r2"] = rand() %10 + 1;
  		poseTransInput["r3"] = rand() %10 + 1;
  		poseTransInput["l1"] = rand() %10 + 1;
  		poseTransInput["l2"] = rand() %10 + 1;
  		poseTransInput["l3"] = rand() %10 + 1;

  		StyledWriter fw;
  		string poseInputJSON = fw.write(poseTransInput);

  		if (f == NULL) {
  			printf("\nError opening file!\n");
  			exit(1);
  		}
  		fprintf(f, "%s", poseInputJSON.c_str());
  	}
  	fclose(f);

  	/*	The following code is testing reading JSON data from an input file,
	*	creating JSON objects from that data, and then outputting the new
	*	JSON objects to a separate file.		
	*/

  	Value PoseJSONobj;
  	Reader reader;
  	ifstream ifs;
  	ifs.open("PoseTransInput", ios::in);
  	vector<Value> JSONobjsVector;
  	string JSONobj;
  	char test;
  	while (ifs.is_open()) {
  		ifs.get(test);
  		if (ifs.eof()){
  			ifs.close();
  			break;
  		} else if (test == '}') {
  			JSONobj += test;
  			bool parsingSuccessful = reader.parse(JSONobj, PoseJSONobj, false);
  			if (!parsingSuccessful) {
  				cout << reader.getFormatedErrorMessages();
  			} else JSONobjsVector.push_back(PoseJSONobj);
  			PoseJSONobj.clear();
  			JSONobj.clear();
  		} else if (test != '}') {
  			JSONobj += test;
  		} else { cout << "\nError parsing!\n"; exit(1);}
  	}
  	
  	FILE *out = fopen("PoseTransReadTest", "w");
	if (out == NULL) {
		printf("\nError opening file!\n");
		exit(1);
	}

  	StyledWriter sw;
  	for (int i = 0; i < JSONobjsVector.size(); ++i) {
  		cout << "JSON Object " << i << ": \n" << sw.write(JSONobjsVector[i]);
  		fprintf(out, "%s", sw.write(JSONobjsVector[i]).c_str());
  	}
  	fclose(out);


  	/*	The following code is testing the creation of matrices 
  	*	using the data read from an input file and stored in the 
  	*	the vector JSONobjsVector. Then it will test matrix multiplication,
  	*	creating JSON objects from the products, and writing those objects to a fle.
  	*/  
  	mat pose(4,4);
  	mat vec(4,1);
  	mat newPose(4,1);

  	vector<mat> vectorTransMatrix;

  	FILE *o = fopen("PoseTransOutput", "w");
	if (o == NULL) {
		printf("\nError opening file!\n");
		exit(1);
	}

  	for (int i = 0; i < JSONobjsVector.size(); ++i) {
  		// create 4x4 pose matrix
  		cout << "\nCreating 4x4 pose matrix...\n";
  		// column 0 is x'
  		pose(0,0) = JSONobjsVector[i].get("x1\'", -1).asInt();
  		pose(1,0) = JSONobjsVector[i].get("x2\'", -1).asInt();
  		pose(2,0) = JSONobjsVector[i].get("x3\'", -1).asInt();
  		pose(3,0) = 0;

  		// column 1 is y'
  		pose(0,1) = JSONobjsVector[i].get("y1\'", -1).asInt();
  		pose(1,1) = JSONobjsVector[i].get("y2\'", -1).asInt();
  		pose(2,1) = JSONobjsVector[i].get("y3\'", -1).asInt();
  		pose(3,1) = 0;

  		// column 2 is z'
  		pose(0,2) = JSONobjsVector[i].get("z1\'", -1).asInt();
  		pose(1,2) = JSONobjsVector[i].get("z2\'", -1).asInt();
  		pose(2,2) = JSONobjsVector[i].get("z3\'", -1).asInt();
  		pose(3,2) = 0;

  		// column 3 is r vector
  		pose(0,3) = JSONobjsVector[i].get("r1", -1).asInt();
  		pose(1,3) = JSONobjsVector[i].get("r2", -1).asInt();
  		pose(2,3) = JSONobjsVector[i].get("r3", -1).asInt();
  		pose(3,3) = 1;

  		cout << "Creating 4x1 vector matrix...\n";
  		// create 4x1 vector matrix
  		vec(0,0) = JSONobjsVector[i].get("l1", -1).asInt();
  		vec(1,0) = JSONobjsVector[i].get("l2", -1).asInt();
  		vec(2,0) = JSONobjsVector[i].get("l3", -1).asInt();
  		vec(3,0) = 1;

  		newPose = pose * vec;

  		// begin creating JSON object from product
  		cout << "\nCreating JSON Object from matrix product...\n";
  		Value newPoseJSON;
  		newPoseJSON["x"] = newPose(0,0);
  		newPoseJSON["y"] = newPose(1,0);
  		newPoseJSON["z"] = newPose(2,0);
  		newPoseJSON["constant"] = newPose(3,0);

  		// store each product matrix in a C++ vector
  		vectorTransMatrix.push_back(newPose);

  		// output JSON data to file
	  	StyledWriter sw;
	  	fprintf(o, "%s", sw.write(newPoseJSON).c_str());
	  	cout << "Matrix Set " << i << ": \n" << pose << endl << vec;
	} 
	fclose(o);

	// output product matrices from C++ vector
	for (int i = 0; i < vectorTransMatrix.size(); ++i) {
		cout << "Vector " << i << ":\n" << vectorTransMatrix[i] << endl;
	}

  	return 0;
}
