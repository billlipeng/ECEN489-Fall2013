

#include<iostream>
#include<fstream>
#include<vector>
#include "performance_metric.h"


using namespace std;

int main()
{
	ifstream ReadPosition;
	ifstream ReadTilt;
	
	ReadPosition.open("Tilted10.txt");
	//ReadTilt.open("tilt.txt");

	double read_inx;
	double read_iny;
	double read_inz;

	double read_intilt;

	vector<double> x_position;
	vector<double> y_position;
	vector<double> z_position;

	vector<double> tilt_angle;

	char temp1,temp2;

	while(!ReadPosition.eof())
	{
		ReadPosition>>read_inx>>temp1>>read_iny>>temp2>>read_inz;
		x_position.push_back(read_inx);
		y_position.push_back(read_iny);
		z_position.push_back(read_inz);

		//ReadTilt>>read_intilt;
		//tilt_angle.push_back(read_intilt);

	}

	cout<<"x pos            y pos                 z pos              tilt angle  "<<endl;

	auto itery = y_position.begin();
	auto iterz = z_position.begin();
	auto itertilt = tilt_angle.begin();

	/*for(auto iter = x_position.begin();iter<x_position.end();iter++) {
		cout<<*iter<<"               "<<*itery<<"                 "<<*iterz<<"               "<<endl;//(*itertilt)*180.0/pi<<endl;
		itery++;
		iterz++;*/
		//itertilt++;
	//}

	auto vecsize = x_position.size();

	double total_score = 0.0;
	double score = 0.0;
	//double tilt = 0.0;
	vector<double>velocity;
	velocity.push_back(0.0);
	velocity.push_back(0.0);
	velocity.push_back(0.0);


	for(int i = 0;i<140; i++) {
		vector<double> temp;
	    temp.push_back(x_position[i+10]);
		temp.push_back(y_position[i+10]);
		temp.push_back(z_position[i+10]);

		score = scorePercentageVertical(0.0,temp,velocity,0.04);
		total_score +=score;
	}

	cout<<"Total Score: "<<total_score<<endl;
	cout<<"Vector size is "<<x_position.end()-x_position.begin()<<endl;



	char x;
	cin>>x;

	return 0;
}






