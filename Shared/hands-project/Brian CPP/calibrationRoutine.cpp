
#include "project_analysis_statistics.h";

void verticalHandRotateCoordinates(double* new_coord[3], const double* old_coord[3])
{
	double x = *old_coord[0];
	double y = *old_coord[1];
	double z = *old_coord[2];

	double alpha = atan(x/y);
	double beta = atan((x*sin(alpha)+y*cos(alpha))/z);

	double x_prime = cos(alpha)*x - sin(alpha)*y;
	double y_prime = sin(alpha)*cos(beta)*x + cos(alpha)*cos(beta)*y - sin(beta)*z;
	double z_prime = sin(alpha)*sin(beta)*x +cos(alpha)*sin(beta)*y + cos(beta)*z;

	*new_coord[0] = x_prime; *new_coord[1] = y_prime; *new_coord[2] = z_prime;

	return;
}


void horizontalHandRotateCoordinates(double* new_coord[3], const double* old_coord[3])
{
	double x = *old_coord[0];
	double y = *old_coord[1];
	double z = *old_coord[2];

	double alpha = atan(y/z);
	double beta = atan((y*sin(alpha)+z*cos(alpha))/x);

	double x_prime = cos(beta)*x + sin(alpha)*sin(beta)*y + cos(alpha)*sin(beta)*z;
	double y_prime = cos(alpha)*y - sin(alpha)*z;
	double z_prime = -sin(beta)*x +sin(alpha)*cos(beta)*y + cos(alpha)*cos(beta)*z;

	*new_coord[0] = x_prime; *new_coord[1] = y_prime; *new_coord[2] = z_prime;

	return;
}

