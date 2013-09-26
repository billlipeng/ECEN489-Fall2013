#include <string>
#include <iostream>
#include <postgresql/libpq-fe.h>

using namespace std;

/* Close connection to database */
void CloseConn(PGconn *conn)
{
  PQfinish(conn);
  getchar();
}

/* Establish connection to database */
PGconn *ConnectDB()
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
  conn = PQconnectdb("user=postgres password=test123 dbname=testdb       	hostaddr=127.0.0.1 port=5432");

  // Check to see that the backend connection was successfully made
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cout << "Connection to database failed.\n";
    CloseConn(conn);
  }

  cout << "Connection to database - OK\n";

  return conn;
}


/* Create grade table */
void CreateGradeTable(PGconn *conn)
{
  // Execute with sql statement
  // table has two columns of type character array (30)
  PGresult *res = PQexec(conn, "CREATE TABLE grades (grade1 char(30), grade2 char(30))");
   
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Create grade table failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Create grade table - OK\n";

  // Clear result
  PQclear(res);
}

/* Append SQL statement and insert record into grade table */
void InsertGradeRec(PGconn *conn, const char * grade1, const char * grade2)
{
  // Append the SQL statment
  std::string sSQL;
  sSQL.append("INSERT INTO grades VALUES ('");
  sSQL.append(grade1);
  sSQL.append("', '");
  sSQL.append(grade2);
  sSQL.append("')");
 
  // Execute with sql statement
  PGresult *res = PQexec(conn, sSQL.c_str());

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Insert grade record failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Insert grade record - OK\n";

  // Clear result
  PQclear(res);
}


/* Fetch grade record and display it on screen */
void FetchGradeRec(PGconn *conn)
{
  // Will hold the number of field in grade table
  int nFields;

  // Start a transaction block
  PGresult *res  = PQexec(conn, "BEGIN");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "BEGIN command failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Clear result
  PQclear(res);

  // Fetch rows from grade table
  res = PQexec(conn, "DECLARE emprec CURSOR FOR select * from grades");
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "DECLARE CURSOR failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Clear result
  PQclear(res);

  res = PQexec(conn, "FETCH ALL in emprec");

  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    cout << "FETCH ALL failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Get the field name
  nFields = PQnfields(res);

  // Prepare the header with grade table field name
  cout << "\nFetch grade record:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    // Next, print out the grade record for each row
    for (int i = 0; i < PQntuples(res); i++)
    {
        for (int j = 0; j < nFields; j++)
            printf("%-30s", PQgetvalue(res, i, j));
        printf("\n");
    }
 
    PQclear(res);

    // Close the emprec
    res = PQexec(conn, "CLOSE emprec");
    PQclear(res);

    // End the transaction
    res = PQexec(conn, "END");

  // Clear result
    PQclear(res);
}

/* Erase all record in grade table */
void RemoveAllgradeRec(PGconn *conn)
{
  // Execute with sql statement
  PGresult *res = PQexec(conn, "DELETE FROM grades");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Delete grades record failed.\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "\nDelete grades record - OK\n";

  // Clear result
  PQclear(res);
}


/* Drop grade table from the database */
void DropgradeTable(PGconn *conn)
{
  // Execute with sql statement
  PGresult *res = PQexec(conn, "DROP TABLE grades");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Drop grade table failed.\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Drop grade table - OK\n";

  // Clear result
  PQclear(res);
}


int main()
{
  PGconn *conn = NULL;
 
  //connect to database
  conn = ConnectDB();
 
  if (conn != NULL)
  {
 
    //create a table
    CreateGradeTable(conn);
    
    //insert some data into table
    InsertGradeRec(conn, "80" ,"100");
    InsertGradeRec(conn, "75" , "95");
    
    // view data	
    FetchGradeRec(conn);

    //purge table and data
    cout << "\nPress ENTER to remove all records & table.....\n";
    getchar();
    RemoveAllgradeRec(conn);
    DropgradeTable(conn);
   
    //close connection to database
    CloseConn(conn);
  }

  return 0;
}


