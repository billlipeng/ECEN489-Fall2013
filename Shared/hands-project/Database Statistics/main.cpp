/*
 * main.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: Brian
 */




//Right now I have a function which can read data from the database
//Data can be selected based on major, age, and gender, or any one of the parameters by themselves
//Might want to add functionality to read based on gender and age alone without major.
//Might also want to add functionality where records can be chosen based on being above or below a certain age.

#include "project_analysis_statistics.h"

int main()
{
	cout<<"Hello this program has started"<<endl;

	PGconn* conn = connectToDatabase();

	for (int i = 0;i < 100; i++) {
		double n = i*1.0;
		insertDataPoint(conn,"Electrical Engineering",'M',24,n,n,n);
	}
	for (int i = 0;i<50;i++) {
		double k = i*1.0;
		double n = i+cos(k)*sqrt(k);
		insertDataPoint(conn,"Psychology",'F',22,n,n,n);
	}

	vector<double> EE_results(1,0);
	vector<double>& EE1 = EE_results;

	fetchDataRecordScore(conn,EE1); //Fetches all scores

	for(auto iter = EE1.begin();iter<EE1.begin()+100;iter++){
		cout<<*iter<<endl;
	}

	double median = findMedian(EE1);
	cout<<"Median is "<<median<<endl;
	double mean = findMean(EE1);
	cout<<"Mean is "<<mean<<endl;
	double stddev = findStandardDeviation(EE1);
	cout<<"Std Dev is "<<stddev<<endl;

	char X;
	cin>>X;

	return 0;

}













