/*
 * fetchDataRecord2.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: Brian
 */


#include "project_analysis_statistics.h"


void fetchDataRecordScore(PGconn *conn, vector<Score_Record>& result, string major, char gender, int age)
{

	string getDataString;
	string column_labels = "score_rvlh, score_right_rvlh, score_left_rvlh, score_lvrh, score_right_lvrh, score_left_lvrh, score_total, score_right_total, score_left_total";

	if (major == "ANY" && gender == 'A' && age == 0) {
	  getDataString = "SELECT " + column_labels + " FROM data_summary ";
	}

	else if (major != "ANY" && (gender == 'A' && age == 0)) { //Only major is selected
	  	getDataString = "SELECT " + column_labels + " FROM data_summary WHERE major = '";
	    getDataString = getDataString + major;
	}

	else if (gender != 'A' && (major == "ANY" && age == 0)) { //Only gender is selected
	    getDataString = "SELECT " + column_labels + " FROM data_summary WHERE gender = ";
	    getDataString = getDataString + gender;
	}

	 else if (age != 0 && (major == "ANY" && gender == 'A')) { // Only age is selected
	    getDataString = "SELECT " + column_labels + " FROM data_summary WHERE age = '";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	 }

	 else if ((age != 0 && gender!= 'A') &&(major == "ANY")) { // Gender and age is selected
	    getDataString = "SELECT " + column_labels + " FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND gender = '" + gender + "'";
	 }

	 else if ((major != "ANY" && gender!= 'A') &&(age == 0)) { // Gender and major is selected
	    getDataString = "SELECT " + column_labels + " FROM data_summary WHERE major = ";
	    getDataString = getDataString + major + "AND gender = '" + gender + "'";

	 }

	 else if ((age != 0 && major!= "ANY") &&(gender == 'A')) { // Major and age is selected
	    getDataString = "SELECT " + column_labels + " FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND major = '" + major + "'";
	 }

	 else if ((age != 0 && major!= "ANY") &&(gender != 'A')) {//All three categories are selected
		getDataString = "SELECT " + column_labels + " FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND major = '" + major + "' AND gender = '" + gender + "'";

	 }

	 else
	 {
		 cout<<"Uh-Oh, no scores match that column list"<<endl;
	 }

	 const char* getData = getDataString.c_str();

	 cout<<getData<<endl;

	 PGresult* res = PQexec(conn, getData);

	 if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			cout << "SELECT returned an error\n";
			PQclear(res);
		    PQfinish(conn);
			char x;
			cin>>x;
		}

	 int dataInfoRows = PQntuples(res);
	 int siz = PQnfields(res);
	 cout<<siz<<" columns returned"<<endl;

    for (int i = 0; i < dataInfoRows; i++) {
    	Score_Record temp_score;
	    char* rvlh_temp = PQgetvalue(res, i, 0);
	    char* rvlh_r_temp = PQgetvalue(res, i, 1);
	    char* rvlh_l_temp = PQgetvalue(res, i, 2);
	    char* lvrh_temp = PQgetvalue(res, i, 3);
	    char* lvrh_r_temp = PQgetvalue(res, i, 4);
	    char* lvrh_l_temp = PQgetvalue(res, i, 5);
	    char* temp = PQgetvalue(res, i, 6);
	    char* r_temp = PQgetvalue(res, i, 7);
	    char* l_temp = PQgetvalue(res, i, 8);

	    stringstream ss_temp;
	    double doub_temp;

	    ss_temp<<rvlh_temp; ss_temp>>doub_temp;
	    temp_score._score_rvlh = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<rvlh_r_temp; ss_temp>>doub_temp;
	    temp_score._score_right_rvlh = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<rvlh_l_temp; ss_temp>>doub_temp;
	    temp_score._score_left_rvlh = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<lvrh_temp; ss_temp>>doub_temp;
	    temp_score._score_lvrh = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<lvrh_r_temp; ss_temp>>doub_temp;
	    temp_score._score_right_lvrh = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<lvrh_l_temp; ss_temp>>doub_temp;
	    temp_score._score_left_lvrh = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<temp; ss_temp>>doub_temp;
	    temp_score._score_total = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<r_temp; ss_temp>>doub_temp;
	    temp_score._score_right_total = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());
	    ss_temp<<l_temp; ss_temp>>doub_temp;
	    temp_score._score_left_total = doub_temp;
		ss_temp.clear();
	    ss_temp.str(string());

	    result.push_back(temp_score);

	}

	cout<<"Fetched "<<dataInfoRows<<" Data info points from database"<<endl;
	PQclear(res);
	return;

}


