#include "project_analysis_statistics.h"

double dot(const vector<double>& A, const vector<double>& B)
{
	auto n1 = A.size();
	auto n2 = B.size();

	if (n1!= n2) {
		cerr<<"Cannot take dot product if vector lengths are not the same"<<endl;
		return -1;
	}
	
	double result = 0.0;

	for (int i = 0;i < n1; i++) {
		result += A[i] * B[i];
	}

	return result;
}

double scorePercentage(const double tilt_angle, const vector<double>& acceleration)
{
	double acc_mag = sqrt(acceleration[0]*acceleration[0] + acceleration[1]*acceleration[1] + acceleration[2]*acceleration[2]);
	vector<double> acc_mod = acceleration;

	for (int i = 0; i < 3; i++){
		acc_mod[i] = acceleration[i]/acc_mag;
	}

	double acc_angle = acos(acc_mod[2]);

	double acc_percent = 0.0;
	double tilt_percent = 0.0;

	if (acc_angle < pi/18)
		acc_percent = 1.0;
	else if (acc_angle < pi/9)
		acc_percent = 0.75;
	else if (acc_angle < pi/4)
		acc_percent = 0.5;
	else if (acc_angle < pi/3)
		acc_percent = 0.25;

	if (tilt_angle < pi/18)
		tilt_percent = 1.0;
	else if (tilt_angle < pi/9)
		tilt_percent = 0.75;
	else if (tilt_angle < pi/4)
		tilt_percent = 0.5;
	else if (tilt_angle < pi/3)
		tilt_percent = 0.25;

	double total_percent = acc_percent*tilt_percent;

	return total_percent;
}

double scorePercentage(const double tilt_angle, AccelerationVector acceleration)
{
	double acc_mag = sqrt(acceleration.x*acceleration.x + acceleration.y*acceleration.y + acceleration.z*acceleration.z);
	AccelerationVector acc_mod = acceleration;

	
		acc_mod.x = acceleration.x/acc_mag;
		acc_mod.y = acceleration.y/acc_mag;
		acc_mod.z = acceleration.z/acc_mag;
	

	double acc_angle = acos(acc_mod.z);

	double acc_percent = 0.0;
	double tilt_percent = 0.0;

	if (acc_angle < pi/18)
		acc_percent = 1.0;
	else if (acc_angle < pi/9)
		acc_percent = 0.75;
	else if (acc_angle < pi/4)
		acc_percent = 0.5;
	else if (acc_angle < pi/3)
		acc_percent = 0.25;

	if (tilt_angle < pi/18)
		tilt_percent = 1.0;
	else if (tilt_angle < pi/9)
		tilt_percent = 0.75;
	else if (tilt_angle < pi/4)
		tilt_percent = 0.5;
	else if (tilt_angle < pi/3)
		tilt_percent = 0.25;

	double total_percent = acc_percent*tilt_percent;

	return total_percent;
}

		
