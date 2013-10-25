#include <vector>

#include <gl/glut.h>

void display()
{
    // Start the point draw
    glBegin(GL_POINTS);

	// Loop through the vector of point.
    for(/* stuff goes here*/)
    {
        glVertex3d(/*The point*/);
    }

    // Finish drawing the points.
    glEnd();

    // Swap the front and back buffers.
    glutSwapBuffer();
	
}

void keyboard (unsigned char key, int x, int y)
{
    
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);

    // Set our window size.
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100,100);
	
    // Create the window with specified title
    glutCreateWindow("Laser Visualization");
	
    // Set up for double buffering and transparency display.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Set our callbacks for display, timer, and keyboard input.
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
    
    // Enter the main loop -- control does not return from here, except at the
    // end of the program.
	glutMainLoop();

    // Exit with success status.
	return 0;
}
