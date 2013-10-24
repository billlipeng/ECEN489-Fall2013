#include "stdafx.h"
#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/******************************************************************
	Notes:
	This is the same utility as in the earlier homework assignment.
	Image size is 400 by 400 by default.  You may adjust this if
		you want to.
	You can assume the window will NOT be resized.
	Call clearFramebuffer to clear the entire framebuffer.
	Call setFramebuffer to set a pixel.  This should be the only
		routine you use to set the color (other than clearing the
		entire framebuffer).  drawit() will cause the current
		framebuffer to be displayed.
	As is, your ray tracer should probably be called from
		within the display function.  There is a very short sample
		of code there now.  You can replace that with a call to a
		function that raytraces your scene (or whatever other
		interaction you provide.
	You may add code to any of the subroutines here,  You probably
		want to leave the drawit, clearFramebuffer, and
		setFramebuffer commands alone, though.
  *****************************************************************/

#define ImageW 400
#define ImageH 400

float framebuffer[ImageH][ImageW][3];

struct color {
	float r, g, b;		// Color (R,G,B values)
};

// Draws the scene
void drawit(void)
{
   glDrawPixels(ImageW,ImageH,GL_RGB,GL_FLOAT,framebuffer);
   glFlush();
}

// Clears framebuffer to black
void clearFramebuffer()
{
	int i,j;

	for(i=0;i<ImageH;i++) {
		for (j=0;j<ImageW;j++) {
			framebuffer[i][j][0] = 0.0;
			framebuffer[i][j][1] = 0.0;
			framebuffer[i][j][2] = 0.0;
		}
	}
}

// Sets pixel x,y to the color RGB
void setFramebuffer(int x, int y, float R, float G, float B)
{
	if (R<=1.0)
		if (R>=0.0)
			framebuffer[x][y][0]=R;
		else
			framebuffer[x][y][0]=0.0;
	else
		framebuffer[x][y][0]=1.0;
	if (G<=1.0)
		if (G>=0.0)
			framebuffer[x][y][1]=G;
		else
			framebuffer[x][y][1]=0.0;
	else
		framebuffer[x][y][1]=1.0;
	if (B<=1.0)
		if (B>=0.0)
			framebuffer[x][y][2]=B;
		else
			framebuffer[x][y][2]=0.0;
	else
		framebuffer[x][y][2]=1.0;
}
// ************************************************************************* //

float dotproduct(float *u, float *v) 
{
	return u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
}

void normalize(float *u) 
{
	float magnitude = sqrt(abs(dotproduct(u,u)));
	u[0] = u[0]/magnitude;
	u[1] = u[1]/magnitude;
	u[2] = u[2]/magnitude;
}

float magnitude(float *u)
{
	return sqrt(u[0]*u[0] + u[1]*u[1] + u[2]*u[2]);
}

float *reflection(float *u, float* normal)
{
	float reflect[] = {normal[0]*2*dotproduct(u,normal)-u[0], normal[1]*2*dotproduct(u,normal)-u[1], normal[2]*2*dotproduct(u,normal)-u[2]};
	return reflect;
}

// *********************************************************************************** //

bool enablereflection = false;
color backgroundcolor;
color *lightcolor;
color *planecolor;
color *spherecolor;

struct lighting {
	float *Ambient_rgb;
	float *Diffuse_rgb;
	float *Specular_rgb;
	float Specular_exp;
};

lighting planelight;
lighting spherelight;
float *intensity;

vector <float *> lights; // type 0
vector <float *> planes; // type 1
vector <float *> spheres; // type 2

float eyeposition[] = {100.0, 200.0, 300.0};
float eyereference[] = {0.0, 200.0, 300.0};
float light1position[] = {300.0, 100.0, 100.0};
float light2position[] = {0.0, 0.0, 50.0};
float plane1position[] = {0.0, 1.0, 0.0, 0.0,};
float plane2position[] = {0.7, 0.0, 0.4, 0.0,};
float sphere1position[] = {250.0, 250.0, -200.0, 80.0}; 
float sphere2position[] = {100.0, 250.0, -100.0, 40.0}; 
float sphere3position[] = {130.0, 300.0, 0.0, 20.0};
float sphere4position[] = {300.0, 250.0, 0.0, 30.0};

void buildobjectlist(){
	lights.clear();
	planes.clear();
	spheres.clear();

	// lights
	lights.push_back(light1position);
	lights.push_back(light2position);
	intensity = new float[2];
	intensity[0] = 2.0;
	intensity[1] = 1.0;
	
	// shapes
	planes.push_back(plane1position);
	planes.push_back(plane2position);
	spheres.push_back(sphere1position);
	spheres.push_back(sphere2position);
	spheres.push_back(sphere3position);
	spheres.push_back(sphere4position);
	
	// colors
	int number_shapes = planes.size()+spheres.size();
	lightcolor = new color[number_shapes];
	planecolor = new color[number_shapes];
	spherecolor = new color[number_shapes];

	backgroundcolor.r = 0.0; backgroundcolor.g = 0.0; backgroundcolor.b = 0.0;
	lightcolor[0].r = 0.0; lightcolor[0].g = 0.0; lightcolor[0].b = 0.0;lightcolor[1].r = 0.0; lightcolor[1].g = 0.03; lightcolor[1].b = 0.03;
	planecolor[0].r = 0.0; planecolor[0].g = 0.0; planecolor[0].b = 1.0;planecolor[1].r = 0.7; planecolor[1].g = 0.0; planecolor[1].b = 0.0;
	spherecolor[0].r = 0.9; spherecolor[0].g = 0.7; spherecolor[0].b = 0.0;
	spherecolor[1].r = 0.5; spherecolor[1].g = 0.0; spherecolor[1].b = 0.7;
	spherecolor[2].r = 0.1; spherecolor[2].g = 0.6; spherecolor[2].b = 0.9;
	spherecolor[3].r = 0.9; spherecolor[3].g = 0.6; spherecolor[3].b = 0.9;

	// coefficients
	planelight.Ambient_rgb = new float[3];planelight.Ambient_rgb[0] = 0.3;planelight.Ambient_rgb[1] = 0.3;planelight.Ambient_rgb[2] = 0.3;
	planelight.Diffuse_rgb = new float[3];planelight.Diffuse_rgb[0] = 0.5;planelight.Diffuse_rgb[1] = 0.5;planelight.Diffuse_rgb[2] = 0.5;
	planelight.Specular_rgb = new float[3];planelight.Specular_rgb[0] = 0.4;planelight.Specular_rgb[1] = 0.4;planelight.Specular_rgb[2] = 0.4;
	planelight.Specular_exp = 5;

	spherelight.Ambient_rgb = new float[3];spherelight.Ambient_rgb[0] = 0.1;spherelight.Ambient_rgb[1] = 0.1;spherelight.Ambient_rgb[2] = 0.1;
	spherelight.Diffuse_rgb = new float[3];spherelight.Diffuse_rgb[0] = 0.2;spherelight.Diffuse_rgb[1] = 0.2;spherelight.Diffuse_rgb[2] = 0.2;
	spherelight.Specular_rgb = new float[3];spherelight.Specular_rgb[0] = 0.4;spherelight.Specular_rgb[1] = 0.4;spherelight.Specular_rgb[2] = 0.4;
	spherelight.Specular_exp = 25;
}

float getplaneintersection(float *start, int index, float *ray)
{
	float eye[] = {start[0], start[1], start[2]}; 
	float intersect = -(dotproduct(planes[index],eye)+planes[index][3])/dotproduct(planes[index], ray);
	if(intersect<0) {
		return -10;
	} else {
		return intersect;
	}
}

float getsphereintersection(float *start, int index, float *ray)
{
	float eye[] = {start[0], start[1], start[2]}; 
	float diff[] = {spheres[index][0]-eye[0], spheres[index][1]-eye[1], spheres[index][2]-eye[2]};
	float diff_mag = sqrt(abs(dotproduct(diff,diff)));
	float t=0;
	float answer;
	float det;

	det = (abs(dotproduct(ray,diff)*dotproduct(ray,diff))-(diff_mag*diff_mag)+spheres[index][3]*spheres[index][3]);
	if (det < 0) {
		answer = -10;
	} else {
		t =-1.0*dotproduct(ray,diff)-sqrt(det);
		if (t < 0) {
			answer = -10;
		} else {
			answer = t;
		}
	}
	return answer;
}

float *getnearestintersection(float *start, float *ray, vector<float*> planes, vector<float*> spheres){
	float min = 5000.0; 
	float intersect_type_number[] = {min, -1, -1};
	
	float intersect;

	for(int i=0; i<planes.size(); i++){
		intersect = getplaneintersection(start, i, ray);
		if((intersect < min) && (intersect!=-10)) {
			min = intersect;
			intersect_type_number[1] = 1;
			intersect_type_number[2] = i;
		}
	}
	for(int i=0; i<spheres.size(); i++){
		intersect = getsphereintersection(start, i, ray);
		if((intersect < min) && (intersect!=-10)) {
			min = intersect;
			intersect_type_number[1] = 2;
			intersect_type_number[2] = i;
		}
	}
	intersect_type_number[0] = min;
	if(min==5000.0){ 
		intersect_type_number[0] = -10;
		intersect_type_number[1] = -1;
		intersect_type_number[2] = -1;
	}
	return intersect_type_number;
}

color getreflection(float *start, float *ray, float i, int type, int index, int reflect_level)
{
	float eye[] = {start[0], start[1], start[2]};
	float point[] = {eye[0] - ray[0]*i, eye[1] - ray[1]*i, eye[2] - ray[2]*i};
	float *norm = new float[3];
	lighting shape_light;
	color temp_color;
	color type_color;
	if (type == 1) {
		norm[0] = planes[index][0];
		norm[1] = planes[index][1];
		norm[2] = planes[index][2];
		shape_light = planelight;
		type_color = planecolor[index];
	} else if (type == 2) {
		norm[0] = point[0]-spheres[index][0];
		norm[1] = point[1]-spheres[index][1];
		norm[2] = point[2]-spheres[index][2];
		shape_light = spherelight;
		type_color = spherecolor[index];
	}
	temp_color.r = type_color.r*shape_light.Ambient_rgb[0];
	temp_color.g = type_color.g*shape_light.Ambient_rgb[1];
	temp_color.b = type_color.b*shape_light.Ambient_rgb[2];
	for(int i=0; i<lights.size(); i++) {
		float light_vector[] = {lights[i][0]-point[0], lights[i][1]-point[1], lights[i][2]-point[2]};
		float temp[] = {point[0]+norm[0]*0.00000001, point[1]+norm[1]*0.00000001, point[2]+norm[2]*0.00000001};
		float reflect = getnearestintersection(temp, light_vector, planes, spheres)[0];
		normalize (light_vector);
		normalize (norm);
		if(enablereflection && (reflect != -10)){
			if(reflect < 1){
				continue;
			}
		}
		if (enablereflection && (reflect_level != 0)) {
			color c;
			float neg_ray[] = {-ray[0], -ray[1], -ray[2]};
			float ref[] = {reflection(neg_ray,norm)[0], reflection(neg_ray,norm)[1], reflection(neg_ray,norm)[2]};
			reflect = getnearestintersection(temp, ref, planes, spheres)[0];
			float new_type = getnearestintersection(temp, ref, planes, spheres)[1];
			float new_index = getnearestintersection(temp, ref, planes, spheres)[2];
			if(reflect != -10) {
				c = getreflection(ref, neg_ray, reflect, new_type, new_index, reflect_level-1);
			} else {
				c.r = 0.0;
				c.g = 0.0;
				c.b = 0.0;
			}
			temp_color.r += .99*c.r;
			temp_color.g += .99*c.g;
			temp_color.b += .99*c.b;
		}
		if(dotproduct(light_vector, norm) > 0){
			temp_color.r += intensity[i]*shape_light.Diffuse_rgb[0]*(dotproduct(light_vector, norm));
			temp_color.g += intensity[i]*shape_light.Diffuse_rgb[1]*(dotproduct(light_vector, norm));
			temp_color.b += intensity[i]*shape_light.Diffuse_rgb[2]*(dotproduct(light_vector, norm));
			
			float R[] = {reflection(light_vector, norm)[0], reflection(light_vector, norm)[1], reflection(light_vector, norm)[2]};
			float eye_V[] = {eye[0]-point[0], eye[1]-point[1], eye[2]-point[2]};
			normalize (eye_V);
			float spec = dotproduct(R, eye_V);
			spec = max((float)0.0, spec);
			float temp = pow(spec,shape_light.Specular_exp);
			float specular[] = {shape_light.Specular_rgb[0]*temp, shape_light.Specular_rgb[1]*temp, shape_light.Specular_rgb[2]*temp};
			temp_color.r += intensity[i]*specular[0]/10 + lightcolor[i].r;
			temp_color.g += intensity[i]*specular[1]/10 + lightcolor[i].g;
			temp_color.b += intensity[i]*specular[2]/10 + lightcolor[i].b;
		}
	}
	return temp_color;
}

// ****************************************************************************** //

void init()
{
	clearFramebuffer();
}

void display()
{
	buildobjectlist();
	for (int i=0; i < ImageW; i++) {
		for (int j=0; j < ImageH; j++) {
			float ray[3] = {1*(eyeposition[0]-i),-1*(eyeposition[1]-j),1*eyeposition[2]};
			float point[3] = {i,j,0};
			normalize(ray);
			bool plotted = false;

			int number_shapes = planes.size()+spheres.size();
			float inter = getnearestintersection(eyeposition, ray, planes, spheres)[0];
			float type = getnearestintersection(eyeposition, ray, planes, spheres)[1];
			int index = getnearestintersection(eyeposition, ray, planes, spheres)[2];
			int reflect_level = 1;

			if (type == -1) { // background
				setFramebuffer(j, i, backgroundcolor.r, backgroundcolor.g, backgroundcolor.b);
			} else if (type == 0) { // light

			} else if (type == 1) { // plane
				color planecolorolor = getreflection(eyeposition, ray, inter, type, index, reflect_level);
				setFramebuffer(j, i, planecolorolor.r, planecolorolor.g, planecolorolor.b);
			} else if (type == 2) { // sphere
				color spherecolorolor = getreflection(eyeposition, ray, inter, type, index, reflect_level);
				setFramebuffer(j, i, spherecolorolor.r, spherecolorolor.g, spherecolorolor.b);
			}
		}
	}	
	drawit();
}
// ***************************************************************************** //

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case '1':
			enablereflection = true;
			glutPostRedisplay();
			break;
		case '2':
			enablereflection = false;
			glutPostRedisplay();
			break;
	}
}
// **************************************************************************** //

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(ImageW,ImageH);
	glutInitWindowPosition(100,100);
	glutCreateWindow("- Assignment 5 -");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	init();	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}