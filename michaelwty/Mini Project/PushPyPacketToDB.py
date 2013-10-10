import serial, psycopg2, json, sys, pprint, time, datetime

SERIALPORT = 'COM6'
DBHOST = "127.0.0.1"
DBPORT = 5432
DBNAME = "postgres"
DBUSER = "postgres"
DBPASSWORD = "159357"



def main():
    # setup our serial
    ser = serial.Serial(SERIALPORT,9600)

    # define our connection string
    #*conn_string = "host=DBHOST dbname=postgres user=postgres password=DBPASSWORD"

    # print the connection string we will use to connect
    #*print "Connecting to database\n ->%s" % (conn_string)
    
    # set connection to our postgresql database
    conn=psycopg2.connect(
        host = DBHOST,
        database = DBNAME,
        user = DBUSER,
        password = DBPASSWORD
        )

    cursor = conn.cursor()
    #*print "Connected!\n"

    # create our table
    #cursor.execute("CREATE TABLE light_sensor(id VARCHAR(5), sensor_value VARCHAR(20), timestamp VARCHAR(30))")
    #*print "A new table created!\n"

    

    while(1):
        data_json = ser.readline()
        data_dic = json.loads(data_json) # decode
        data_dic['timestamp'] = str(datetime.datetime.now())# add 'timestamp' into our data_dictionary

        print data_dic # test point
        
        cursor.execute("INSERT INTO light_sensor(id,sensor_value,timestamp) VALUES (%(id)s, %(sensor_value)s, %(timestamp)s)", data_dic)
        conn.commit()
        time.sleep(1) # Delay for 5 seconds

    #cursor.execute("INSERT INTO light_sensor(id,sensor_value,timestamp) VALUES("1","387.0","12:00")")
    
    #***cursor.execute("CREATE TABLE cars(id INT PRIMARY KEY, name VARCHAR(20), price INT)")



    # execute our Query

    #*cursor.execute("SELECT * FROM my_table")

    # retrieve the records from the database

    #*records = cursor.fetchall()
 
    # print out the records using pretty print
    # note that the NAMES of the columns are not shown, instead just indexes.
    # for most people this isn't very useful so we'll show you how to return
    # columns as a dictionary (hash) in the next example.
    #*pprint.pprint(records)

    
    
if __name__ == "__main__":
    main()
