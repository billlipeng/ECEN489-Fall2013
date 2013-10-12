import serial, psycopg2, json, sys, pprint, time, datetime

SERIALPORT = 'COM8'
DBHOST = "fulla.ece.tamu.edu"
DBPORT = 5432
DBNAME = "light_team"
DBUSER = "light_team_user"
DBPASSWORD = "light_team_password"
TABLENAME = "lightsensor"

def main():
    # setup our serial
    ser = serial.Serial(SERIALPORT,9600)

    # Calibration stuff
    print ser.readline()
    raw_input(">>")
    ser.write('\n')    
    print ser.readline()
    raw_input(">>")
    ser.write('\n')

    # set connection to our postgresql database
    con=psycopg2.connect(
        host = DBHOST,
        database = DBNAME,
        user = DBUSER,
        password = DBPASSWORD
        )

    cur = con.cursor()
    print "Connected!\n"

    # Clear the table
    cur.execute("DELETE FROM " + TABLENAME + ";")
    con.commit()


    while(1):
        for i in range(5):
            message = ser.readline()
            data = json.loads(message)
            data['timestamp'] = str(datetime.datetime.now())
            cur.execute("INSERT INTO " + TABLENAME + "(id,sensor_value,timestamp) VALUES (" + str(data["id"]) + ", " + str(data["sensor_value"]) + ", \'" + str(data["timestamp"])  + "\')")
            print data
        con.commit()
        
    
if __name__ == "__main__":
    main()
