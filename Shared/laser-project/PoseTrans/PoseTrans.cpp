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
#include <string>
#include <armadillo>
#include <time.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <GL/glut.h>
#include <json/json.h>

using namespace std;
using namespace arma;
using namespace Json;

struct termios tty;
struct termios tty_old;

int USB; // holds tty port info for reading

void sampleDataGenerator() {
	// generate sample JSON data file (emulate serial data from microcontroller)
  	Value poseTransInput;

  	srand(time(NULL));
  	FILE *f = fopen("PoseTransInput", "w");
  	for (int i = 0; i < 10; ++i) {
  		poseTransInput["x1\'"] = rand() %10 - 5;
  		poseTransInput["x2\'"] = rand() %10 - 5;
  		poseTransInput["x3\'"] = rand() %10 - 5;
  		poseTransInput["y1\'"] = rand() %10 - 5;
  		poseTransInput["y2\'"] = rand() %10 - 5;
  		poseTransInput["y3\'"] = rand() %10 - 5;
  		poseTransInput["z1\'"] = rand() %10 - 5;
  		poseTransInput["z2\'"] = rand() %10 - 5;
  		poseTransInput["z3\'"] = rand() %10 - 5;
  		poseTransInput["r1"] = rand() %10 - 5;
  		poseTransInput["r2"] = rand() %10 - 5;
  		poseTransInput["r3"] = rand() %10 - 5;
  		poseTransInput["l1"] = rand() %10 - 5;
  		poseTransInput["l2"] = rand() %10 - 5;
  		poseTransInput["l3"] = rand() %10 - 5;

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
  		//newPoseJSON["constant"] = newPose(3,0);

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
}

vector<mat> sphere;
void generateSphere() {
	int radius = 5;
	int x0 = 0;
	int y0 = 0;
	int z0 = 0;
	mat point(3,1);
	for (double theta = 0.0; theta <= 2 * 3.14159; theta = theta + (3.14159 / 32)) {
		for (double psi = 0.0; psi <= 3.14159; psi = psi + (3.14159 / 32)) {
			point(0,0) = x0 + (radius * cos(theta) * sin(psi));
			point(1,0) = y0 + (radius * sin(theta) * sin(psi));
			point(2,0) = z0 + (radius * cos(psi));
			sphere.push_back(point);
		}
	}

}

vector<mat> spherePoseTrans;
void poseTransSphere() {
	mat pose(4,4);
	mat newPose(4,1);
	mat displacement(4,1);
	displacement(0,0) = 10;
	displacement(1,0) = 10;
	displacement(2,0) = 10;
	displacement(3,0) = 1;
	pose(0,0) = 1; pose(0,1) = 0; pose(0,2) = 0;
	pose(1,0) = 0; pose(1,1) = 1; pose(1,2) = 0;
	pose(2,0) = 0; pose(2,1) = 0; pose(2,2) = 1;
	pose(3,0) = 0; pose(3,1) = 0; pose(3,2) = 0; pose(3,3) = 1;

	for (int i = 0; i < sphere.size(); ++i) {
		pose(0,3) = sphere[i](0,0);
		pose(1,3) = sphere[i](1,0);
		pose(2,3) = sphere[i](2,0);

		newPose = pose * displacement;
		spherePoseTrans.push_back(newPose);
	}


}

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

// OPENGL STUFF

static int body = 0;
const char* sourcefile = "/home/clayclay/Desktop/ECEN403LaserProject/Project/Shared/laser-project/PoseTrans/PoseTransOutput";
int WINDOW_WIDTH =800, WINDOW_HEIGHT=800;


// mouse state
int prevX = 0, prevY = 0;
bool leftPressed = false, rightPressed = false, middlePressed = false;

// view state
float rotMat [ 16 ] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
float focus [ 3 ] = {0,-10,-30};

struct IMUdata{
	double x;
	double y;
	double z;
	//double range;
};

IMUdata originalData[10000];
vector<IMUdata> vectorData;

void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void readfile(void){
	usleep(100);
	ifstream ifs(sourcefile);
	//Value jsonData;



  	Value PoseJSONobj;
  	Reader reader;
  	vector<Value> JSONobjsVector;
	char test;
	string JSONobj;
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

		//infile >> jsonData;
		//Value coordinates;// = jsonData["coordinates"];
		for (int i = 0; i < JSONobjsVector.size(); ++i){
			originalData[i].x = JSONobjsVector[i].get("x", -1).asDouble();
			originalData[i].y = JSONobjsVector[i].get("y", -1).asDouble();
			originalData[i].z = JSONobjsVector[i].get("z", -1).asDouble();
			cout << originalData[i].x << "  " << originalData[i].y << "  " << originalData[i].z << endl;
			vectorData.push_back(originalData[i]);
		}
	
	/*
	for (vector<IMUdata>::iterator iter1=vectorData.begin(); iter1 !=vectorData.end(); ++iter1){
		cout<< iter1->x <<" "<< iter1->y <<" " << iter1->z << endl;
	}
	*/
}		


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Set up viewing matrices
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, float(WINDOW_WIDTH)/WINDOW_HEIGHT, .01, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Camera
	glTranslatef(focus[0], focus[1], focus[2]);
	glMultMatrixf(rotMat);
	
	//draw base
	glPushMatrix();
	glRotatef((GLfloat) body, 0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glScalef(4.0, 0.8, 2);
	glutSolidCube(1.0);		
	glPopMatrix();

	//draw coordinate system
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 50.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(50.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 10.0);
	glEnd();

	// Start the point draw
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	// Loop through the vector of point.
	//for (vector<IMUdata>::iterator iter2=vectorData.begin(); iter2 !=vectorData.end(); ++iter2){
	//	glVertex3f(double(iter2->x),double(iter2->y),double(iter2->z));
	//}
	for (int i = 0; i < sphere.size(); ++i) {
		double x = sphere[i](0,0);
		double y = sphere[i](1,0);
		double z = sphere[i](2,0);
		glVertex3f(x,y,z);
	}
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < spherePoseTrans.size(); ++i) {
		double x = spherePoseTrans[i](0,0);
		double y = spherePoseTrans[i](1,0);
		double z = spherePoseTrans[i](2,0);
		glVertex3f(x,y,z);
	}
	// Finish drawing the points.
	glEnd();

	// Swap the front and back buffers.
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
		focus [ 2 ] = focus [ 2 ]+0.4;
		glutPostRedisplay();
		break;
	case 'Z':
		focus [ 2 ] = focus [ 2 ]-0.4;
		glutPostRedisplay();
		break;
	case 'r':
		readfile();
		glutPostRedisplay();
		break;
	}
}

void mouse(int button, int state, int x, int y){
	y = WINDOW_HEIGHT - y;
	if (state == GLUT_DOWN)
	{
		prevX = x;
		prevY = y;
	}

	if (button == GLUT_LEFT_BUTTON)
	{
		leftPressed = state == GLUT_DOWN;
	}
	if (button == GLUT_MIDDLE_BUTTON)
	{
		middlePressed = state == GLUT_DOWN;
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		rightPressed = state == GLUT_DOWN;
	}
}

void motion(int x, int y){
	y = WINDOW_HEIGHT - y;

	float dx = (x - prevX);
	float dy = (y - prevY);

	if (leftPressed)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(dx, 0, 1, 0);
		glRotatef(dy, -1, 0, 0);
		glMultMatrixf(rotMat);
		glGetFloatv(GL_MODELVIEW_MATRIX, rotMat);
	}
	else if (middlePressed)
	{
		focus [ 0 ] += 0.01 * dx;
		focus [ 1 ] += 0.01 * dy;
	}
	prevX = x;
	prevY = y;

	glutPostRedisplay();
}

// END OPENGL STUFF

int main (int argc, char** argv) {

	// OPENGL MAIN LOOP STUFF

	glutInit(&argc,argv);

	// Set our window size.
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0,0);

	// Create the window with specified title
	glutCreateWindow("Laser Visualization");

	// Set up for double buffering and transparency display.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// Set our callbacks for display, timer, and keyboard input.
	init();
	//sampleDataGenerator(); // generate sample data
	generateSphere();
	poseTransSphere();
	//glutIdleFunc(readfile);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	//glutTimerFunc(50,display,0);

	// Enter the main loop -- control does not return from here, except at the
	// end of the program.
	glutMainLoop();

	// END OPENGL MAIN LOOP STUFF



  	return 0;
}
