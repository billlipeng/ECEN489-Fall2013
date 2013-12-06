/*
 * getData.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */




/*
 * fetchDataRecord2.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: Brian
 */


#include "test_statistics.h"


string getQuery(string identifier, string major,char gender ,int age, char dominant_hand)
{

	string command = "SELECT score_right_rvlh, score_left_rvlh, score_rvlh, score_right_lvrh, score_left_lvrh, score_lvrh, score_right_total, score_left_total, score_total ";
	command = command + " FROM data_summary ";

	if (identifier != "ANY") {
		command = command + "WHERE identifier = '" + identifier + "';";
		return command;
	}

	else if (major=="ANY" && gender=='A' && dominant_hand=='A' && age==0) {
			command = command + ";";;
			return command;
		}

	else command = command + " WHERE score_total IS NOT NULL ";

	if (major!="ANY") {
		command = command + " AND major = '" + major + "'";
	}

	if (gender != 'A') {
		command = command + " AND gender = '" + gender + "' ";
	}

	if (age !=0) {
		stringstream ss_ageminus, ss_ageplus;
		ss_ageminus<<(age-2);ss_ageplus<<(age+2);
		string age_mstr = ss_ageminus.str();
		string age_pstr = ss_ageplus.str();
		command = command + " AND age > " + age_mstr + " AND age < " + age_pstr;
	}

	if (dominant_hand!='A') {
		command = command + " AND dominant_hand = '" + dominant_hand + "' ";
	}

	command = command + ";";

	return command;
}


void fetchScoreRecord(PGconn *conn, vector<Score_Record>& result, string query)
{

	result.clear();

	const char* getData = query.c_str();
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
	    char* rvlh_r_temp = PQgetvalue(res, i, 0);
	    char* rvlh_l_temp = PQgetvalue(res, i, 1);
	    char* rvlh_temp = PQgetvalue(res, i, 2);
	    char* lvrh_r_temp = PQgetvalue(res, i, 3);
	    char* lvrh_l_temp = PQgetvalue(res, i, 4);
	    char* lvrh_temp = PQgetvalue(res, i, 5);
	    char* r_temp = PQgetvalue(res, i, 6);
	    char* l_temp = PQgetvalue(res, i, 7);
	    char* temp = PQgetvalue(res, i, 8);

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

