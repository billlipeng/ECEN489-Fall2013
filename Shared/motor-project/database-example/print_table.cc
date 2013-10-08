
/// A simple example program that connects to the database and inserts
/// some random rows.

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <pqxx>

int main(int argc, char **argv)
{

    // Open a connection to the database.
    pqxx::connection conn(
        "host=fulla.ece.tamu.edu "
        "dbname=motor_team "
        "user=motor_team_user "
        "password=motor_team_password "
    );
    
    // Create a transaction.
    pqxx::work cur_transaction(conn, "DemoTransaction");
    
    pqxx::result all_temp_readings
        = cur_transaction.exec("select * from temp_readings");
    
    for(pqxx::result::const_iterator it = all_temp_readings.begin();
        it != all_temp_readings.end();
        ++it)
    {
        cout << "[arduino_id=" << (*it)["arduino_id"].as<int>()
             << ", reading_time_utc=" << (*it)["reading_time_utc"].as<string>()
             << ", temp_kelvin=" << (*it)["temp_kelvin"].as<string>() << "]"
             << endl;
    }

    // Commit the transaction.
    cur_transaction.commit();
}
