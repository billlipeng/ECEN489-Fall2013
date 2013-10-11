#Python 2.7.5 (default, May 15 2013, 22:44:16) [MSC v.1500 64 bit (AMD64)] on win32
#Type "copyright", "credits" or "license()" for more information

import serial, psycopg2, json, sys, pprint, time, datetime

SERIALPORT = 'COM3'
DBHOST = "127.0.0.1"
DBPORT = 5432
DBNAME = "postgres"
DBUSER = "postgres"
DBPASSWORD = "159357"

threshold_value = 10;
sensor_value=0;


def main():
    # setup our serial
    ser = serial.Serial(2);
    ser.baudrate = 9600;
    print ser.portstr;
    

    # define our connection string
    #*conn_string = "host=DBHOST dbname=postgres user=postgres password=DBPASSWORD"

    # print the connection string we will use to connect
    #*print "Connecting to database\n ->%s" % (conn_string)
    
    # set connection to our postgresql database
    #I commented out this block
    #conn=psycopg2.connect(
     #   host = DBHOST,
      #  database = DBNAME,
       # user = DBUSER,
        #password = DBPASSWORD
        #)
   # cursor = conn.cursor()



    #*print "Connected!\n"

    # create our table
    #cursor.execute("CREATE TABLE light_sensor(id VARCHAR(5), sensor_value VARCHAR(20), timestamp VARCHAR(30))")
    #*print "A new table created!\n"

    

##    while(1):
##        data_json = ser.readline()
##        data_dic = json.loads(data_json) # decode
##        data_dic['timestamp'] = str(datetime.datetime.now())# add 'timestamp' into our data_dictionary
##
##        print data_dic # test point
##        
##        #cursor.execute("INSERT INTO light_sensor(id,sensor_value,timestamp) VALUES (%(id)s, %(sensor_value)s, %(timestamp)s)", data_dic)
##        cursor.execute("SELECT sensor_value FROM light_sensor", data_dic)
##        conn.commit()
##        time.sleep(1) # Delay for 5 seconds
    
    #cursor.execute("INSERT INTO light_sensor(id,sensor_value,timestamp) VALUES("1","387.0","12:00")")
    
    #***cursor.execute("CREATE TABLE cars(id INT PRIMARY KEY, name VARCHAR(20), price INT)")


#I commented out this block too
    # execute our Query
    ###cursor.execute("SELECT sensor_value FROM light_sensor WHERE id = '1' ")
    ###for (sensor_value, ) in cursor.fetchmany([10]):
      ###  if float(sensor_value) < threshold_value:
         ###   print 'OFF'
            ###ser.write("{\"light_level\":\"0\"}\n")
        ###else:
           ### print sensor_value
            ###ser.write("{\"light_level\":\"");ser.write(string(sensor_value));
            ###ser.write("\"}\n");
        ###time.sleep(1)
    

    index = 0;
    index1 = 0;

    for index1 in range(0,10000):
        for index in range(0,255):

            if index < threshold_value:
                ser.write("{\"lightLevel\":\"0\"}\n");
                print ser.readline();
                
            else:
                ser.write("{\"lightLevel\":\""+str(index)+"\"}\n");
                print ser.readline();
            
		time.sleep(1)
        index1 = index1 + 1;
    



    #pprint.pprint(count)
    #ser.write(count)
    
    #pprint.pprint(count)
    #jdata = json.dumps(count)
    #serdata = ser.writelines(count)
    #pprint.pprint(data_dic)
    
    #print serdata
    #cursor.copy_expert("COPY light_sensor TO STDOUT WITH CSV HEADER", sys.stdout)

    #jdata = json.loads(count)
    
    #for x in range(0, int(count)):
    #    cursor.execute("SELECT id ,sensor_value FROM light_sensor")

    # retrieve the records from the database

    #   records = cursor.fetchall()
 
    # print out the records using pretty print
    # note that the NAMES of the columns are not shown, instead just indexes.
    # for most people this isn't very useful so we'll show you how to return
    # columns as a dictionary (hash) in the next example.
    #    pprint.pprint(records)


    
    
if __name__ == "__main__":
    main()
