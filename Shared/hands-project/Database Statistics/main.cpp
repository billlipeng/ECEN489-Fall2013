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
		insertDataPoint(conn,"Electrical Engineering",'M',24,'R',n,1.1*n,1.2*n,1.5*n,1.6*n,1.75*n,2*n,3*n,4*n);
	}
	/*for (int i = 0;i<50;i++) {
		double k = i*1.0;
		double n = i+cos(k)*sqrt(k);
		insertDataPoint(conn,"Psychology",'F',22,'L',n,n,n,n,n,n,n,n,n);
	}
*/
	vector<Score_Record> EE_results;
	vector<Score_Record> EE1;// = EE_results;

	fetchDataRecordScore(conn,EE1); //Fetches all scores

	for(auto iter = EE1.begin();iter<EE1.begin()+10;iter++){
		cout<<(*iter)._score_rvlh<<'\t'<<(*iter)._score_lvrh<<'\t'<<(*iter)._score_total<<endl;
	}

	/*double median = findMedian(EE1);
	cout<<"Median is "<<median<<endl;
	double mean = findMean(EE1);
	cout<<"Mean is "<<mean<<endl;
	double stddev = findStandardDeviation(EE1);
	cout<<"Std Dev is "<<stddev<<endl;

	*/

	/*string cmd = "SELECT score_total, score_rvlh, score_lvrh FROM data_summary";
	const char* sqlcmd = cmd.c_str();

    PGresult* res = PQexec(conn, sqlcmd);

	 if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			cout << "SELECT returned an error\n";
			PQclear(res);
		    PQfinish(conn);
			char x;
			cin>>x;
		}

	 vector<double> result;

	 int dataInfoRows = PQntuples(res);

   for (int i = 0; i < dataInfoRows; i++) {
	    char* tempDataInfo = PQgetvalue(res, i, 0);
	    stringstream ss_temp;
	    ss_temp<<tempDataInfo;
	    double dataInfoPoint;
	    ss_temp>>dataInfoPoint;
	    cout<<dataInfoPoint<<endl;
	    result.push_back(dataInfoPoint);
	}
*/

	char X;
	cin>>X;

	return 0;

}













