#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <gl/glut.h>
#include <json/json.h>

using namespace std;

static int body = 0;
char* sourcefile = "F:\\jsonIMU.txt";
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
	ifstream infile(sourcefile);
	Json::Value jsonData;

		infile >> jsonData;
		Json::Value coordinates = jsonData["coordinates"];
		for(int i = 0; i < coordinates.size(); ++i){
		originalData[i].x = coordinates[i]["x"].asDouble();
		originalData[i].y = coordinates[i]["y"].asDouble();
		originalData[i].z = coordinates[i]["z"].asDouble();
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
		glVertex3d(0.0, 10.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(10.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 10.0);
	glEnd();

	// Start the point draw
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(15.0);
	glBegin(GL_POINTS);
	// Loop through the vector of point.
	for (vector<IMUdata>::iterator iter2=vectorData.begin(); iter2 !=vectorData.end(); ++iter2){
		glVertex3f(double(iter2->x),double(iter2->y),double(iter2->z));
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


int main(int argc, char** argv)
{
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
	glutIdleFunc(readfile);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	// Enter the main loop -- control does not return from here, except at the
	// end of the program.
	glutMainLoop();

	// Exit with success status.
	return 0;
}