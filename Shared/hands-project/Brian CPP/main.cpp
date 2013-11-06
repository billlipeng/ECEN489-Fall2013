//Right now I have a function which can read data from the database
//Data can be selected based on major, age, and gender, or any one of the parameters by themselves
//Might want to add functionality to read based on gender and age alone without major.
//Might also want to add functionality where records can be chosen based on being above or below a certain age.

#include "project_analysis_statistics.h"

using namespace Numeric_lib;

int main()
{

	//PGconn* conn = connectToDatabase();

	/*for (int i = 0;i < 100; i++) { 
		double n = i*1.0;
		insertDataPoint(conn,"Electrical Engineering",'M',24,n);
	}*/

	//vector<double> EE_results(1,0);
	//vector<double>& EE1 = EE_results;

	//fetchDataRecord(conn,EE1);

	/*for(auto iter = EE1.begin();iter<EE1.end();iter++){
		cout<<*iter<<endl;
	}*/

	/*double median = findMedian(EE1);
	cout<<"Median is "<<median<<endl;
	double mean = findMean(EE1);
	cout<<"Mean is "<<mean<<endl;
	double stddev = findStandardDeviation(EE1);
	cout<<"Std Dev is "<<stddev<<endl;
	*/

	/*vector<double> A;
	A.push_back(1.0);
	A.push_back(2.0);
	A.push_back(3.0);
	vector<double> B;
	B.push_back(1.0);
	B.push_back(5.0);
	B.push_back(2.0);

	double prod = dot(A,B);

	cout<<"Dot product is "<<prod<<endl;
	*/

	/*double tilt = pi/14;
	vector<double> acc;
	acc.push_back(0.0);
	acc.push_back(2.0);
	acc.push_back(2.0);

	double result = scorePercentage(tilt,acc);

	cout<<"percentage total is "<<result<<endl;*/

	Matrix<double,2> C(3,3);

	

	


	char X;
	cin>>X;

	return 0;

}













