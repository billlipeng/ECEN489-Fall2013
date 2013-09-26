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

/* Fetch employee record and display it on screen */
void FetchGradeRec(PGconn *conn)
{
  // Will hold the number of field in employee table
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

  // Fetch rows from employee table
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

  // Prepare the header with employee table field name
  cout << "\nFetch grade record:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    // Next, print out the employee record for each row
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


int main()
{
  PGconn *conn = NULL;
 
  conn = ConnectDB();
 
  if (conn != NULL)
  {
    FetchGradeRec(conn);
    CloseConn(conn);
  }

  return 0;
}


