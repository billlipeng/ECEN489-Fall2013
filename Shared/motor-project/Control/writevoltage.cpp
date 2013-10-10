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
// name: motor_team
// host address: 165.91.240.126 
// port: 5432
// username: motor_team_user
// password: motor_team_password
/********************************/
  conn = PQconnectdb("user=motor_team_user password=motor_team_password dbname=motor_team       	hostaddr=165.91.240.126 port=5432");

  // Check to see that the backend connection was successfully made
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cout << "Connection to database failed.\n";
    CloseConn(conn);
  }

  cout << "Connection to database - OK\n";

  return conn;
}


/* Create Voltage table 
void CreateVoltageTable(PGconn *conn)
{
  // Execute with sql statement
  // table has two columns of type character array (30)
  PGresult *res = PQexec(conn, "CREATE TABLE Voltages (Voltage1 char(30), Voltage2 char(30))");
   
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Create Voltage table failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Create Voltage table - OK\n";

  // Clear result
  PQclear(res);
}

*/

/* Append SQL statement and insert record into voltage table */
void InsertMotorRec(PGconn *conn, const char * arduino_id, const char * motor_voltage)
{
  // Append the SQL statment
  std::string sSQL;
  sSQL.append("INSERT INTO motor_readings (arduino_id, motor_voltage) VALUES ('");
  sSQL.append(arduino_id);
  sSQL.append("', '");
  sSQL.append(motor_voltage);
  sSQL.append("')");

 
  // Execute with sql statement
  PGresult *res = PQexec(conn, sSQL.c_str());

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Insert Motor Readings record failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Insert Motor Readings record - OK\n";

  // Clear result
  PQclear(res);
}


/* Fetch Voltage record and display it on screen
void FetchVoltageRec(PGconn *conn)
{
  // Will hold the number of field in Voltage table
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

  // Fetch rows from Voltage table
  res = PQexec(conn, "DECLARE emprec CURSOR FOR select * from motor_readings");
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

  // Prepare the header with motor_readings table field name
  cout << "\nFetch motor_readings record:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    // Next, print out the motor_readings record for each row
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

*/
/* Erase all record in Voltage table */
void RemoveAllVoltageRec(PGconn *conn)
{
  // Execute with sql statement
  PGresult *res = PQexec(conn, "DELETE FROM motor_readings");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Delete Motor Readings record failed.\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "\nDelete Motor Readings record - OK\n";

  // Clear result
  PQclear(res);
}


/* Drop Voltage table from the database 
void DropVoltageTable(PGconn *conn)
{
  // Execute with sql statement
  PGresult *res = PQexec(conn, "DROP TABLE Voltages");

  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "Drop Voltage table failed.\n";
    PQclear(res);
    CloseConn(conn);
  }

  cout << "Drop Voltage table - OK\n";

  // Clear result
  PQclear(res);
}
*/

int main()
{
  PGconn *conn = NULL;
 
  //connect to database
  conn = ConnectDB();
 
  if (conn != NULL)
  {
    
    //insert some data into table
    InsertMotorRec(conn, "1","2.3");
    InsertMotorRec(conn, "1","2.4");
    InsertMotorRec(conn, "2","2.2");
    InsertMotorRec(conn, "2","3.0");
    
    // view data	
  //  FetchVoltageRec(conn);

    //purge table and data
//    cout << "\nPress ENTER to remove all records & table.....\n";
//    getchar();
//    RemoveAllVoltageRec(conn);
//    DropVoltageTable(conn);
   
    //close connection to database
    CloseConn(conn);
  }

  return 0;
}


