import serial, psycopg2, json, sys, pprint, time, datetime, math

SERIALPORT = 'COM11'
DBHOST = "fulla.ece.tamu.edu"
DBPORT = 5432
DBNAME = "light_team"
DBUSER = "light_team_user"
DBPASSWORD = "light_team_password"
TABLENAME = "lightsensor"

def main():
    # setup our serial
    ser = serial.Serial(SERIALPORT,9600)

    # set connection to our postgresql database
    con=psycopg2.connect(
        host = DBHOST,
        database = DBNAME,
        user = DBUSER,
        password = DBPASSWORD
        )

    cur = con.cursor()
    print "Connected!\n"

    while(1):
        cur.execute("SELECT timestamp, id, sensor_value from " + TABLENAME + " where id = '1' order by timestamp desc limit 1")
        record = cur.fetchone()
        print record
        fval = float(record[2])
        ival = int(math.floor(fval))
        ser.write("%03d" % (ival,))  
        time.sleep(.1)              
    
if __name__ == "__main__":
    main()
