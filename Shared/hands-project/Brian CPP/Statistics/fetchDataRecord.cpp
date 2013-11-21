
#include "project_analysis_statistics.h"

void fetchDataRecord(PGconn *conn, vector<double>& result, string major, char gender, int age)
{

	for(auto iter = result.begin();iter<result.end();iter++){
		//cout<<*iter<<endl;
	}

  if (major == "ANY" && gender == 'A' && age == 0)
  {
	  string getDataString = "SELECT score FROM data_summary ";//WHERE ";
	 	
	  const char* getData = getDataString.c_str();
	  //cout<<getData<<endl;


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

  else if (major != "ANY" && (gender == 'A' && age == 0)) { //Only major is selected
	  string getDataString = "SELECT score FROM data_summary WHERE major = '";
	  getDataString = getDataString + major;
	  
	  const char* getData = getDataString.c_str();
	  //cout<<getData<<endl;
	  
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

  else if (gender != 'A' && (major == "ANY" && age == 0)) { //Only gender is selected
	  string getDataString = "SELECT score FROM data_summary WHERE gender = ";
	  getDataString = getDataString + gender;
	  
	  const char* getData = getDataString.c_str();
	  //cout<<getData<<endl;

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

  else if (age != 0 && (major == "ANY" && gender == 'A')) { // Only age is selected
	  string getDataString = "SELECT score FROM data_summary WHERE age = '";
	  stringstream ss_age;
	  ss_age<<age;
	  string age_str = ss_age.str();
	  getDataString = getDataString + age_str;
	
	  const char* getData = getDataString.c_str();
	 // cout<<getData<<endl;

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

  else if ((age != 0 && gender!= 'A') &&(major == "ANY")) { // Gender and age is selected
	  string getDataString = "SELECT score FROM data_summary WHERE age = ";
	  stringstream ss_age;
	  ss_age<<age;
	  string age_str = ss_age.str();
	  getDataString = getDataString + age_str;
	  getDataString = getDataString + " AND gender = '" + gender + "'";

	
	  const char* getData = getDataString.c_str();
	 // cout<<getData<<endl;

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

  else cout<<"Uh-Oh, no scores match that column list"<<endl;

  return;
}