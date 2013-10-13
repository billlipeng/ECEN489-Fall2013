#include <string>
#include <sstream>
#include <iostream>
#include <postgresql/libpq-fe.h>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <cerrno>
#include <sys/time.h>
#include <thread>

using namespace std;

// class to create an average temperature object
class AverageTemp
{
	private:
		int arduino_id;
		double average_temp;
	public: 
		AverageTemp(int id, double temp) { arduino_id = id; average_temp = temp; }
		int getID() { return arduino_id; }
		int getTemp() { return average_temp; }
};

class MotorReading
{
	private:
		int arduino_id;
		double motor_volt;
	public:
		MotorReading(int id, double volt) { arduino_id = id; motor_volt = volt; }
		int getID() { return arduino_id; }
		int getVolt() { return motor_volt; }
};


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

  conn = PQconnectdb("user=motor_team_user password=motor_team_password dbname=motor_team hostaddr=165.91.240.126 port=5432");

  // Check to see that the backend connection was successfully made
  if (PQstatus(conn) != CONNECTION_OK)
  {
    cout << "Connection to database failed.\n";
    CloseConn(conn);
  }

  cout << "Connection to database - OK\n";

  return conn;
}

// Ashton's average temp function
AverageTemp getAVGTemp(int arduino_id) {
	// Values needed to make initial connection
	const char *keywords[] = {
        "host",
        "dbname",
        "user",
        "password",
        nullptr
    };
	const char *values[] = {
        "fulla.ece.tamu.edu",
        "motor_team",
        "motor_team_user",
        "motor_team_password",
        nullptr
    };

	// Initiate database connection with these values
	PGconn *conn = PQconnectdbParams(keywords,values, 0);
	
	if (PQstatus(conn) != CONNECTION_OK) {
		cerr << "PQStatus Returned CONNECTION_BAD" << endl;
	}
	
	stringstream convstream;
    convstream << arduino_id;
    string arduino_id_str;
    convstream >> arduino_id_str;
	
	// Parameter values needed in the queries below
	const char* paramValues[1];
	paramValues[0] = arduino_id_str.c_str();

	// Get 10 most current values of the two tables, where arduino ID is from paramValues
	const char *readTempInfo = "SELECT arduino_id, temp_kelvin from temp_readings WHERE arduino_id=$1 ORDER BY reading_time_utc DESC NULLS LAST Limit 10";

	// Submits a command, readTempInfo, to the server and waits for a result
	PGresult *TempInfo = PQexecParams(conn, readTempInfo, 1, NULL, paramValues, NULL, NULL, 0);

	if (PQresultStatus(TempInfo) != PGRES_TUPLES_OK) {
		cerr << "SELECT returned an error!" << endl;
	}
	
	// Get number of rows queried
	int TempInfoRow = PQntuples(TempInfo);
	
	// For each row, print the temperature and id, then an average of the temps
	int TempSum = 0;
	for (int i=0; i < TempInfoRow; i++) {
		char *PrintTempInfo0 = PQgetvalue(TempInfo, i, 0);
		char *PrintTempInfo1 = PQgetvalue(TempInfo, i, 1);
		stringstream stringStream;
		stringStream<<PrintTempInfo1;
		int currentValue;
		stringStream>>currentValue;
		TempSum += currentValue;
		cout << "ID: "<< PrintTempInfo0 <<endl;
		cout << "Temp: " << PrintTempInfo1 <<endl;
	}
	if (TempInfoRow != 0) {
		TempSum = TempSum/TempInfoRow;
		cout<<"Avg: "<<TempSum<<endl;
		cout << endl;
	}
    PQclear(TempInfo);

	AverageTemp a1(arduino_id, TempSum);	// create new average temp object with id 1 and avg

    // close the connection to the database and cleanup  
    PQfinish(conn);
	return a1;
}


/* 
void FetchTempRec(PGconn *conn, int tablePosition, double avg1temp, double avg2temp, double avg3temp, double avg4temp)
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
  res = PQexec(conn, "DECLARE emprec CURSOR FOR select * from temp_readings");
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    cout << "DECLARE CURSOR failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Clear result
  PQclear(res);

  res = PQexec(conn, "FETCH ALL in temprec");

  if (PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    cout << "FETCH ALL failed\n";
    PQclear(res);
    CloseConn(conn);
  }

  // Get the field name
  nFields = PQnfields(res);

  // Prepare the header with temperature table field name
  cout << "\nFetch temp record:";
  cout << "\n********************************************************************\n";
    for (int i = 0; i < nFields; i++)
        printf("%-30s", PQfname(res, i));
    cout << "\n********************************************************************\n";

    // Next, print out the temperature record for each row
    for (;  tablePosition < PQntuples(res); tablePosition++)
    {
        for (int j = 0; j < nFields; j++)
            printf("%-30s", PQgetvalue(res, tablePosition, j));
        printf("\n");
    }
	
	vector<double> a1temp(); // arduino 1 temperatures
	vector<double> a2temp(); // arduino 2 temperatures
	vector<double> a3temp(); // arduino 3 temperatures
	vector<double> a4temp(); // arduino 4 temperatures
	
	for (; tablePosition < PQntuples(res); tablePosition++)
    {
		if (PQgetvalue(res, tablePosition, 0) == 1) { // arduino 1 temp reading
			if (a1temp.size() <= 10) {
				a1temp.push_back(PQgetvalue(res, tablePosition, 2));
			} else {
				for (int i = 0; i < a1temp.size(); ++i) {
					avg1temp = avg1temp + a1temp[i];
				}
				avg1temp = avg1temp / 10;
			}
		}
		if (PQgetvalue(res, tablePosition, 0) == 2) { // arduino 2 temp reading
			if (a2temp.size() <= 10) {
				a2temp.push_back(PQgetvalue(res, tablePosition, 2));
			} else {
				for (int i = 0; i < a2temp.size(); ++i) {
					avg2temp = avg2temp + a2temp[i];
				}
				avg2temp = avg2temp / 10;
			}
		}
		if (PQgetvalue(res, tablePosition, 0) == 3) { // arduino 3 temp reading
			if (a3temp.size() <= 10) {
				a3temp.push_back(PQgetvalue(res, tablePosition, 2));
			} else {
				for (int i = 0; i < a3temp.size(); ++i) {
					avg3temp = avg3temp + a3temp[i];
				}
				avg3temp = avg3temp / 10;
			}
		}
		if (PQgetvalue(res, tablePosition, 0) == 4) { // arduino 4 temp reading
			if (a4temp.size() <= 10) {
				a4temp.push_back(PQgetvalue(res, tablePosition, 2));
			} else {
				for (int i = 0; i < a4temp.size(); ++i) {
					avg4temp = avg4temp + a4temp[i];
				}
				avg4temp = avg4temp / 10;
			}
		}
	}
	
 
    PQclear(res);

    // Close the emprec
    res = PQexec(conn, "CLOSE emprec");
    PQclear(res);

    // End the transaction
    res = PQexec(conn, "END");

  // Clear result
    PQclear(res);
} */

/* Append SQL statement and insert record into voltage table */
void InsertMotorRec(PGconn *conn, const char * arduino_id, const char * motor_voltage)
{
  // Append the SQL statement
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

/* example json object: MAKE ARDUINO SEND JUST LIKE THIS
	{"arduino_id":1,"motor_voltage":2.5}
*/

MotorReading readFromArduino() {
	cout << "Connecting to arduino..." << endl;
	
	FILE *file;
	file = fopen("/dev/ttyUSB0","r");  //Opening device file
	
	int arduino_id = 0;
	double motor_voltage = 0.0;
	
	char tempChar = ' ';
	int fieldCounter = 0;
	while (tempChar != '}') {
		fscanf(file, "%c", &tempChar); //Writing to the file
		if (tempChar == ':') {
			if (fieldCounter == 0) {
				// then we know we are getting arduino_id
				fscanf(file, "%d", &arduino_id);
				++fieldCounter; // increment field counter for next field (motor_voltage)
			} else if(fieldCounter == 1) {
				// then we know we're getting the voltage
				fscanf(file, "%lf", &motor_voltage);
				--fieldCounter; // reset field counter for next JSON object
				break; // we break from for loop because we should have parsed both JSON data fields by now
			} else cout <<"\nERROR PARSING JSON DATA\n\n";
		}
        std::this_thread::sleep_for(std::chrono::seconds(1));
	}
    fclose(file);
	MotorReading a1(arduino_id, motor_voltage);
	return a1;
}

void writeToArduino(int arduino_id, double avgTemperature) {
	cout << "Connecting to arduino..." << endl;
		
	// create JSON data object to send to arduino
	stringstream JSONdata;
	JSONdata << "{\"arduino_id\":";
	JSONdata << arduino_id;
	JSONdata << ",\"motor_voltage\":";
	JSONdata << avgTemperature;
	JSONdata << "}";
	
	FILE *file;
	file = fopen("/dev/ttyUSB0","w");  //Opening device file

	fprintf(file, JSONdata.str().c_str()); //Writing to the file
	std::this_thread::sleep_for(std::chrono::seconds(1));
    fclose(file);
}

int main(int argc, char *argv[]) 
{
	PGconn *conn = NULL;
	conn = ConnectDB();

	if (conn != NULL)
	{
		int debug = 0;
		cout << "DEBUG...\n";
		cout << "1.) Getting Average Temps\n"
			 << "2.) Writing Average Temp to Arduino\n"
			 << "3.) Reading Motor Voltage from Arduino\n"
			 << "4.) Insert Motor Voltage in DB\n"
			 << "0.) Quit\n";
		cin >> debug;
		while (debug)
        {
			switch(debug)
            {
            case 1: {
                AverageTemp a1 = getAVGTemp(12);
                cout << "\n\nArduino ID: " << a1.getID() << "Average Temp: " << a1.getTemp() << "\n";
                break;
            }
			case 2: {
                writeToArduino(99, 999.9);
                break;
            }
            case 3: {
                MotorReading mrA = readFromArduino();
                cout << "\n\nArduino ID: " << mrA.getID() << "Motor Reading: " << mrA.getVolt() << "\n";
                break;
            }
            case 4: {
                stringstream convstream;
                convstream << 99 << " " << 999.9;
                string arduino_id_str;
                convstream >> arduino_id_str;
                string voltage_str;
                convstream >> voltage_str;
                
                InsertMotorRec(conn, arduino_id_str.c_str(), voltage_str.c_str());
                break;
            }
            case 0: {
                CloseConn(conn); 
                return 0;
            }
            default: {
                cerr << "Unknown choice" << endl;
                break;
            }
            }
			
            cout << "DEBUG...\n";
            cout << "1.) Getting Average Temps\n"
                 << "2.) Writing Average Temp to Arduino\n"
                 << "3.) Reading Motor Voltage from Arduino\n"
                 << "4.) Insert Motor Voltage in DB\n"
                 << "0.) Quit\n";
            cin >> debug;
        }
		
		/*
		// Get AVG temperature reading from DB
		//FetchTempRec(conn, &tablePosition, &avg1temp, &avg2temp, &avg3temp, &avg4temp);
		AverageTemp a1() = getAvgTemp();

		// Write Avg Temperature to the Arduino Serially
		writeToArduino(a1.getID(), a1.getTemp()); // EDIT APPROPRIATELY

		// Read motor reading from Arduino
		MotorReading mrA() = readFromArduino();
		
		// Insert motor reading into DB
		InsertMotorRec(conn, mrA.getID(), mrA.getVolt());
		*/
		CloseConn(conn); 
	}
	return 0;
}

