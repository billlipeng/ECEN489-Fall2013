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

MotorReading readFromArduino(string port, int outID) {
	cout << "Connecting to arduino..." << endl;
	
	FILE *file;
	file = fopen(port.c_str(),"r");  //Opening device file
	
	int arduino_id = 0;
	double motor_voltage = 0.0;
	
	char tempChar = ' ';
	int fieldCounter = 0;
	while (tempChar != '}') {
		char* temp;
		fgets(temp, 200, file);
		//cout << temp << endl;
		tempChar = fgetc(file);
		//fscanf(file, "%c", &tempChar); //Writing to the file
		if (tempChar == ':') {
			if (fieldCounter == 0) {
				// then we know we are getting arduino_id...BUT WE DONT CARE
				fscanf(file, "%d", &arduino_id);
				++fieldCounter; // increment field counter for next field (motor_voltage)
			} else if(fieldCounter == 1) {
				// then we know we're getting the voltage
				fscanf(file, "%lf", &motor_voltage);
				--fieldCounter; // reset field counter for next JSON object
				break; // we break from for loop because we should have parsed both JSON data fields by now
			} else cout <<"\nERROR PARSING JSON DATA\n\n";
		}
        //std::this_thread::sleep_for(std::chrono::seconds(1));
	}
    fclose(file);
	MotorReading a1(outID, motor_voltage);
	return a1;
}

void writeToArduino(vector<int> inID, vector<string> outPorts, int arduino_id, double avgTemperature) {
	cout << "\nConnecting to arduino...\n" << endl;
		
	// create JSON data object to send to arduino
	stringstream JSONdata;
	JSONdata << "{\"arduino_id\":";
	JSONdata << arduino_id;
	JSONdata << ",\"motor_voltage\":";
	JSONdata << avgTemperature;
	JSONdata << "}";
	
	string JSONobj = JSONdata.str();
	FILE *file;
	
	// CHANGE THE fopen PATH TO CORRESPONDING ARDUINO
	if (arduino_id == inID[0]) {
		file = fopen(outPorts[0].c_str(),"w");  //Opening device file
	}
	else if (arduino_id == inID[1]) {
		file = fopen(outPorts[1].c_str(),"w");  //Opening device file
	}
	else if (arduino_id == inID[2]) {
		file = fopen(outPorts[2].c_str(),"w");  //Opening device file
	}
	else if (arduino_id == inID[3]) {
		file = fopen(outPorts[3].c_str(),"w");  //Opening device file
	}
	else cerr << "\nINVALID INPUT ARDUINO ID!\n";

	if (file == NULL) 
		cerr << "\nFile pointer is NULL\n";
	
	fputs(JSONobj.c_str(), file); //Writing to the file
	//std::this_thread::sleep_for(std::chrono::seconds(1));
    fclose(file);
}

int main(int argc, char *argv[]) 
{
	PGconn *conn = NULL;
	conn = ConnectDB();

	if (conn != NULL)
	{
	/*	int debug = 0;
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
        } */
		
		vector<int> inID;	// input arduino IDs
		vector<int> outID;	// output arduino IDs
		vector<string> outPorts;	// character device file for output arduinos
		int numArduinos, inputID;
		string outputPort; 
		
		cout << "\n#### Arduino ID Input Stage: Input Side ####\n";
		cout << "How many Arduinos are there on the input stage? :";
		cin >> numArduinos;
		for (int i = 0; i < numArduinos; ++i) {
			cout << "Enter Arduino ID: ";
			cin >> inputID;
			inID.push_back(inputID);
		}
		
		cout << "\n#### Arduino ID Output Stage ####\n";
		cout << "How many Arduinos are there on the output stage? :";
		cin >> numArduinos;
		for (int i = 0; i < numArduinos; ++i) {
			cout << "Enter Arduino ID: ";
			cin >> inputID;
			outID.push_back(inputID);
			cout << "Enter Arduino Character Device File: ";
			cin >> outputPort;
			outPorts.push_back(outputPort);
		}
		
		while (true) {
			for (int i = 0; i < inID.size(); ++i) {
				AverageTemp at = getAVGTemp(inID[i]);
				writeToArduino(inID, outPorts, at.getID(), at.getTemp());
				MotorReading mr = readFromArduino(outPorts[i], outID[i]);
				
				stringstream stringStream;
				stringStream << mr.getID() << " " << mr.getVolt();
				string ID, voltage;
				stringStream >> ID;
				stringStream >> voltage;
				InsertMotorRec(conn, ID.c_str(), voltage.c_str());
			}
		}
		CloseConn(conn); 
	}
	return 0;
}

