/*
 * fetchDataRecord2.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: Brian
 */


#include "project_analysis_statistics.h"

void fetchDataRecordScore(PGconn *conn, vector<double>& result, string major, char gender, int age)
{

	string getDataString;
	if (major == "ANY" && gender == 'A' && age == 0) {
	  getDataString = "SELECT score FROM data_summary ";//WHERE ";
	}

	else if (major != "ANY" && (gender == 'A' && age == 0)) { //Only major is selected
	  	getDataString = "SELECT score FROM data_summary WHERE major = '";
	    getDataString = getDataString + major;
	}

	else if (gender != 'A' && (major == "ANY" && age == 0)) { //Only gender is selected
	    getDataString = "SELECT score FROM data_summary WHERE gender = ";
	    getDataString = getDataString + gender;
	}

	 else if (age != 0 && (major == "ANY" && gender == 'A')) { // Only age is selected
	    getDataString = "SELECT score FROM data_summary WHERE age = '";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	 }

	 else if ((age != 0 && gender!= 'A') &&(major == "ANY")) { // Gender and age is selected
	    getDataString = "SELECT score FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND gender = '" + gender + "'";
	 }

	 else if ((major != "ANY" && gender!= 'A') &&(age == 0)) { // Gender and major is selected
	    getDataString = "SELECT score FROM data_summary WHERE major = ";
	    getDataString = getDataString + major + "AND gender = '" + gender + "'";

	 }

	 else if ((age != 0 && major!= "ANY") &&(gender == 'A')) { // Major and age is selected
	    getDataString = "SELECT score FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND major = '" + major + "'";
	 }

	 else if ((age != 0 && major!= "ANY") &&(gender != 'A')) {//All three categories are selected
		getDataString = "SELECT score FROM data_summary WHERE age = ";
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

    for (int i = 0; i < dataInfoRows; i++) {
	    char* tempDataInfo = PQgetvalue(res, i, 0);
	    stringstream ss_temp;
	    ss_temp<<tempDataInfo;
	    double dataInfoPoint;
	    ss_temp>>dataInfoPoint;
	    result.push_back(dataInfoPoint);

	}

	cout<<"Fetched "<<dataInfoRows<<" Data info points from database"<<endl;
	PQclear(res);
	return;

}


void fetchDataRecordRightScore(PGconn *conn, vector<double>& result, string major, char gender, int age)
{

	string getDataString;
	if (major == "ANY" && gender == 'A' && age == 0) {
	  getDataString = "SELECT right_score FROM data_summary ";//WHERE ";
	}

	else if (major != "ANY" && (gender == 'A' && age == 0)) { //Only major is selected
	  	getDataString = "SELECT right_score FROM data_summary WHERE major = '";
	    getDataString = getDataString + major;
	}

	else if (gender != 'A' && (major == "ANY" && age == 0)) { //Only gender is selected
	    getDataString = "SELECT right_score FROM data_summary WHERE gender = ";
	    getDataString = getDataString + gender;
	}

	 else if (age != 0 && (major == "ANY" && gender == 'A')) { // Only age is selected
	    getDataString = "SELECT right_score FROM data_summary WHERE age = '";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	 }

	 else if ((age != 0 && gender!= 'A') &&(major == "ANY")) { // Gender and age is selected
	    getDataString = "SELECT right_score FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND gender = '" + gender + "'";
	 }

	 else if ((major != "ANY" && gender!= 'A') &&(age == 0)) { // Gender and major is selected
	    getDataString = "SELECT right_score FROM data_summary WHERE major = ";
	    getDataString = getDataString + major + "AND gender = '" + gender + "'";

	 }

	 else if ((age != 0 && major!= "ANY") &&(gender == 'A')) { // Major and age is selected
	    getDataString = "SELECT right_score FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND major = '" + major + "'";
	 }

	 else if ((age != 0 && major!= "ANY") &&(gender != 'A')) {//All three categories are selected
		getDataString = "SELECT right_score FROM data_summary WHERE age = ";
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

    for (int i = 0; i < dataInfoRows; i++) {
	    char* tempDataInfo = PQgetvalue(res, i, 0);
	    stringstream ss_temp;
	    ss_temp<<tempDataInfo;
	    double dataInfoPoint;
	    ss_temp>>dataInfoPoint;
	    result.push_back(dataInfoPoint);

	}

	cout<<"Fetched "<<dataInfoRows<<" Data info points from database"<<endl;
	PQclear(res);
	return;

}


void fetchDataRecordLeftScore(PGconn *conn, vector<double>& result, string major, char gender, int age)
{

	string getDataString;
	if (major == "ANY" && gender == 'A' && age == 0) {
	  getDataString = "SELECT left_score FROM data_summary ";//WHERE ";
	}

	else if (major != "ANY" && (gender == 'A' && age == 0)) { //Only major is selected
	  	getDataString = "SELECT left_score FROM data_summary WHERE major = '";
	    getDataString = getDataString + major;
	}

	else if (gender != 'A' && (major == "ANY" && age == 0)) { //Only gender is selected
	    getDataString = "SELECT left_score FROM data_summary WHERE gender = ";
	    getDataString = getDataString + gender;
	}

	 else if (age != 0 && (major == "ANY" && gender == 'A')) { // Only age is selected
	    getDataString = "SELECT left_score FROM data_summary WHERE age = '";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	 }

	 else if ((age != 0 && gender!= 'A') &&(major == "ANY")) { // Gender and age is selected
	    getDataString = "SELECT left_score FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND gender = '" + gender + "'";
	 }

	 else if ((major != "ANY" && gender!= 'A') &&(age == 0)) { // Gender and major is selected
	    getDataString = "SELECT left_score FROM data_summary WHERE major = ";
	    getDataString = getDataString + major + "AND gender = '" + gender + "'";

	 }

	 else if ((age != 0 && major!= "ANY") &&(gender == 'A')) { // Major and age is selected
	    getDataString = "SELECT left_score FROM data_summary WHERE age = ";
	    stringstream ss_age;
	    ss_age<<age;
	    string age_str = ss_age.str();
	    getDataString = getDataString + age_str;
	    getDataString = getDataString + " AND major = '" + major + "'";
	 }

	 else if ((age != 0 && major!= "ANY") &&(gender != 'A')) {//All three categories are selected
		getDataString = "SELECT left_score FROM data_summary WHERE age = ";
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

    for (int i = 0; i < dataInfoRows; i++) {
	    char* tempDataInfo = PQgetvalue(res, i, 0);
	    stringstream ss_temp;
	    ss_temp<<tempDataInfo;
	    double dataInfoPoint;
	    ss_temp>>dataInfoPoint;
	    result.push_back(dataInfoPoint);

	}

	cout<<"Fetched "<<dataInfoRows<<" Data info points from database"<<endl;
	PQclear(res);
	return;

}







