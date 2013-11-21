
#include"project_analysis_statistics.h";

//Establish connection to database 
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
  conn = PQconnectdb("user=postgres password=test123 dbname=testdb hostaddr=127.0.0.1 port=5432");

  // Check to see that the backend connection was successfully made
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cerr << "Connection to database failed.\n";
	PQfinish(conn);
	return nullptr;
    //CloseConn(conn);
  }

  cout << "Connection to database - OK\n";

  return conn;
}

void insertDataPoint(PGconn *conn, string major, char gender, int age, double score)
{
  // Append the SQL statment
  string cmd = "INSERT INTO data_summary (major, gender, age, score) VALUES ('";
  
  cmd = cmd + major + "' , '" + gender + "' , ";

  stringstream ss_age1, ss_score1;
  ss_age1 << age; ss_score1 << score; 
  string ss_age = ss_age1.str();
  string ss_score = ss_score1.str();

  const char* age_str = ss_age.c_str();
  const char* score_str = ss_score.c_str();
  
  string sqlcommand = cmd + age_str + ", " + score_str + ");" ;
   
  const char* command = sqlcommand.c_str();
  //cout<<command<<endl;
   
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
