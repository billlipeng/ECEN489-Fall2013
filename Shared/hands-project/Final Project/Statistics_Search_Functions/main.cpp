/*
 * main.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */


//The filenames entered in this code are for Brians computer. Filepaths will have to be altered to be used on a different machine.



#include "test_statistics.h"

int main()
{
	PGconn* conn = connectToDatabase();
	/*
	for (int i = 0; i < 100; i++) {
		stringstream ss1;
		ss1<<i;
		string identify = "person" + ss1.str();
		string identify2 = "person" + ss1.str() + "b";
		insertDataPoint(conn, "ECEN",'M',21,'R',i,i,i,i*.25,i*.5,i*.5,6*i,3*i,2*i,identify);
		insertDataPoint(conn, "MEEN",'M',22,'R',i,.1*i,i,.7*i,i,i,.8*i,i,i,identify2);
	}
	*/
	string major;char gender;char dominant_hand;int age;string identifier;
	vector<Score_Record> score_records;
	string file, hist_file;
	vector<double> temp_scores;
	vector<string> all_params;
	vector<int> temp_hist;
	vector<int> hist_intervals;

	all_params.push_back("total");all_params.push_back("right");
	all_params.push_back("left");all_params.push_back("vertical");
	all_params.push_back("horizontal");

	removeParameterFile();
	removeIdentifierFile();

	cout<<"Program Started"<<endl;
	int num_comp;
	cout<<"This program will allow you to compare score records from the database based on major, age, gender, etc..."<<endl;
	cout<<"The default arguments are to search all categories with no specification of that parameter."<<endl;
	cout<<"To enter the default arguments, one can enter any for major and a for gender and dominant hand, as well as 0 for the age"<<endl;
	cout<<"Alternatively, one can just hit the return key twice in a row on all arguments except major to get the default arguments."<<endl;

	cout<<"How many records would you like to compare?"<<endl;
	cin>>num_comp;
	removeDataFiles(num_comp);

	for (int i = 0; i < num_comp; i++) {
		int k = 5*i;

		getParameters(major, gender, dominant_hand, age, identifier);
		string query = getQuery(identifier,major,gender,age,dominant_hand);
		fetchScoreRecord(conn, score_records,query);
		printIdentifier(identifier,major,gender,age,dominant_hand);

		for (int n = 1;n < 6; n++) {
			file = getFilename(k+n);
			returnVector(score_records,temp_scores,all_params[n-1]);
			printVector(temp_scores,file);
			printParameter(all_params[n-1]);

			hist_file = getHistFilename(k+n);
			findHistogram(temp_scores,temp_hist,hist_intervals,20);
			printVector(temp_hist,hist_file);

			temp_hist.clear();
			temp_scores.clear();
		}

	}

	cout<<"Thank you, now proceed to Matlab to plot results"<<endl;
	cout<<"Enter any character to exit"<<endl;


	char x;
	cin>>x;


	return 0;

}
