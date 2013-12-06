/*
 * connectToDatabase.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: Brian
 */


#include "test_statistics.h"

PGconn* connectToDatabase()
{
  PGconn *conn = NULL;
  // Make a connection to the database
/********************************/
// Database Info:
// name: testdb
// host address: 127.0.0.1
// port: 5432
// username: postgres
// password: test123
/********************************/
  //conn = PQconnectdb("user=hand_user password=hand_password dbname=hand host=fulla.ece.tamu.edu port=5432");
  conn = PQconnectdb("user=postgres password=test123 dbname=testdb host=localhost port=5432");

  // Check to see that the backend connection was successfully made
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cerr << "Connection to database failed.\n";
	PQfinish(conn);
	return nullptr;
  }

  cout << "Connection to database - OK\n";

  return conn;
}

void insertDataPoint(PGconn *conn, string major, char gender, int age, char dom_hand, double score_rvlh, double score_right_rvlh, double score_left_rvlh, double score_lvrh, double score_right_lvrh, double score_left_lvrh, double score, double score_right, double score_left, string identifier)
{
  // Append the SQL statment
  string cmd = "INSERT INTO data_summary (major, gender, dominant_hand, age, score_total_rvlh, score_right_rvlh, score_left_rvlh, score_total_lvrh, score_right_lvrh, score_left_lvrh, score_total, score_right_total, score_left_total, identifier) VALUES ('";

  cmd = cmd + major + "' , '" + gender + "' , '" + dom_hand + "', ";


  stringstream temp;
  temp<<age;
  string ss_age = temp.str();

  temp.str(string());
  temp<<score_rvlh;
  string ss_score_rvlh = temp.str();

  temp.str(string());
  temp<<score_right_rvlh;
  string ss_score_right_rvlh = temp.str();

  temp.str(string());
  temp<<score_left_rvlh;
  string ss_score_left_rvlh = temp.str();

  temp.str(string());
  temp<<score_lvrh;
  string ss_score_lvrh = temp.str();

  temp.str(string());
  temp<<score_right_lvrh;
  string ss_score_right_lvrh = temp.str();

  temp.str(string());
  temp<<score_left_lvrh;
  string ss_score_left_lvrh = temp.str();

  temp.str(string());
  temp<<score;
  string ss_score = temp.str();

  temp.str(string());
  temp<<score_right;
  string ss_score_right = temp.str();

  temp.str(string());
  temp<<score_left;
  string ss_score_left = temp.str();

  cmd = cmd + ss_age + "," + ss_score_rvlh + "," + ss_score_right_rvlh  + "," + ss_score_left_rvlh  + "," + ss_score_lvrh + "," + ss_score_right_lvrh + "," + ss_score_left_lvrh + "," + ss_score + "," + ss_score_right + "," + ss_score_left + ", '" + identifier + "');";
  const char* command = cmd.c_str();

  cout<<command<<endl;

  // Execute with sql statement
  PGresult *res = PQexec(conn, command);

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Insert data record failed\n";
    PQclear(res);
    PQfinish(conn);
  }

  else {//cout << "Insert data record - OK\n";
  PQclear(res);}
  // Clear result

}

