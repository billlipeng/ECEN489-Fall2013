/*
 * performance_matric2.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Brian
 */




#include "performance_metric.h"

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
/*
double scorePercentageVertical(const double tilt_angle, const vector<double>& acceleration, vector<double>& velocity, double ts)
{
	vector<double> current_velocity;
	current_velocity.push_back(velocity[0] + acceleration[0]*ts);
	current_velocity.push_back(velocity[1] + acceleration[1]*ts);
	current_velocity.push_back(velocity[2] + acceleration[2]*ts);

	cout<<"Z_vel: "<<current_velocity[2]<<"                ";
	//cout<<"X_vel: "<<current_velocity[0]<<endl;
	cout<<"Y_vel: "<<current_velocity[1]<<endl;

	double vel_mag = sqrt(current_velocity[0]*current_velocity[0] + current_velocity[1]*current_velocity[1] + current_velocity[2]*current_velocity[2]);

	vector<double> vel_mod = current_velocity;

	for (int i = 0; i < 3; i++){
		vel_mod[i] = current_velocity[i]/vel_mag;
	}

	double acc_angle = acos(abs(vel_mod[2]));

	double vel_percent = 0.01;
	double tilt_percent = 0.1;

	if (abs(acc_angle) < pi/18)
		vel_percent = 1.0;
	else if (abs(acc_angle) < pi/9)
		vel_percent = 0.75;
	else if (abs(acc_angle) < pi/4)
		vel_percent = 0.5;
	else if (abs(acc_angle) < pi/3)
		vel_percent = 0.25;
	else if (abs(acc_angle) < 85*pi/180)
		vel_percent = 0.1;


	if (tilt_angle < pi/18)
		tilt_percent = 1.0;
	else if (tilt_angle < pi/9)
		tilt_percent = 0.75;
	else if (tilt_angle < pi/4)
		tilt_percent = 0.5;
	else if (tilt_angle < pi/3)
		tilt_percent = 0.25;


	double total_percent = vel_percent*tilt_percent;
	velocity = current_velocity;

	return total_percent;
}*/

double scorePercentageVertical(const double tilt_angle, const vector<double>& acceleration, vector<double>& velocity, double ts)
{
	//vector<double> current_velocity;
	//current_velocity.push_back(velocity[0] + acceleration[0]*ts);
	//current_velocity.push_back(velocity[1] + acceleration[1]*ts);
	//current_velocity.push_back(velocity[2] + acceleration[2]*ts);

	//cout<<"Z_vel: "<<current_velocity[2]<<"                ";
	//cout<<"X_vel: "<<current_velocity[0]<<endl;
	//cout<<"Y_vel: "<<current_velocity[1]<<endl;

	double acc_mag = sqrt(acceleration[0]*acceleration[0] + acceleration[1]*acceleration[1] + acceleration[2]*acceleration[2]);

	vector<double> acc_mod = acceleration;

	for (int i = 0; i < 3; i++){
		acc_mod[i] = acceleration[i]/acc_mag;
	}

	double acc_angle = acos(abs(acc_mod[2]));

	double vel_percent = 0.01;
	double tilt_percent = 0.1;

	if (acceleration[0] < 5.0 && acceleration[1]< 5.0 && acceleration[2] < 5.0)
			vel_percent = 0.0;
	else if (abs(acc_angle) < pi/18)
		vel_percent = 1.0;
	else if (abs(acc_angle) < pi/9)
		vel_percent = 0.75;
	else if (abs(acc_angle) < pi/4)
		vel_percent = 0.5;
	else if (abs(acc_angle) < pi/3)
		vel_percent = 0.25;
	else if (abs(acc_angle) < 85*pi/180)
		vel_percent = 0.1;


	if (tilt_angle < pi/18)
		tilt_percent = 1.0;
	else if (tilt_angle < pi/9)
		tilt_percent = 0.75;
	else if (tilt_angle < pi/4)
		tilt_percent = 0.5;
	else if (tilt_angle < pi/3)
		tilt_percent = 0.25;


	cout<<"Acc percent: "<<vel_percent<<endl;
	cout<<"Tilt percent: "<<tilt_percent<<endl;
	double total_percent = vel_percent*tilt_percent;
	//velocity = current_velocity;

	return total_percent;
}

void positionEstimate(vector<double>& position, vector<double>& velocity, vector<double>& acceleration, double ts)
{
	vector<double> current_velocity;
	current_velocity.push_back(velocity[0]+acceleration[0]*ts);
	current_velocity.push_back(velocity[1]+acceleration[1]*ts);
	current_velocity.push_back(velocity[2]+acceleration[2]*ts);

	position[0] = position[0]+0.5*acceleration[0]*(ts*ts)+velocity[0]*ts;
	position[1] = position[1]+0.5*acceleration[1]*(ts*ts)+velocity[1]*ts;
	position[2] = position[2]+0.5*acceleration[2]*(ts*ts)+velocity[2]*ts;

	return;
}


/*
double scorePercentage(const double tilt_angle, const vector<double>& acceleration)
{
	double acc_mag = sqrt(acceleration[0]*acceleration[0] + acceleration[1]*acceleration[1] + acceleration[2]*acceleration[2]);
	vector<double> acc_mod = acceleration;

	for (int i = 0; i < 3; i++){
		acc_mod[i] = acceleration[i]/acc_mag;
	}

	double acc_angle = acos(abs(acc_mod[2]));

	double acc_percent = 0.01;
	double tilt_percent = 0.0;

	if (abs(acc_angle) < pi/18)
		acc_percent = 1.0;
	else if (abs(acc_angle) < pi/9)
		acc_percent = 0.75;
	else if (abs(acc_angle) < pi/4)
		acc_percent = 0.5;
	else if (abs(acc_angle) < pi/3)
		acc_percent = 0.25;
	else if (abs(acc_angle) < 85*pi/180)
		acc_percent = 0.1;


	if (tilt_angle < pi/18)
		tilt_percent = 1.0;
	else if (tilt_angle < pi/9)
		tilt_percent = 0.75;
	else if (tilt_angle < pi/4)
		tilt_percent = 0.5;
	else if (tilt_angle < pi/3)
		tilt_percent = 0.25;
	else
		tilt_percent = 0.1;

	double total_percent = acc_percent*tilt_percent;

	return total_percent;
}
/*
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


		*/
