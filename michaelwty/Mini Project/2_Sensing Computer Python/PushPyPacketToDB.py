import serial, psycopg2, json, sys, pprint, time, datetime

SERIALPORT = 'COM3'     
DBHOST = "ec2-184-73-175-240.compute-1.amazonaws.com"
DBPORT = 5432
DBNAME = "d9mfolvfgchviv"
DBUSER = "eybgpzgirvbvkb"
DBPASSWORD = "0l4089PrKyiYjC42_gkMsUD9id"


def main():
    # setup our serial
    ser = serial.Serial(SERIALPORT,9600)

    # set connection to our postgresql database
    conn=psycopg2.connect(
        host = DBHOST,
        database = DBNAME,
        user = DBUSER,
        password = DBPASSWORD
        )

    cursor = conn.cursor()    

    while(1):
        data_json = ser.readline()
        data_dic = json.loads(data_json) # decode
        data_dic['timestamp'] = str(datetime.datetime.now())# add 'timestamp' into our data_dictionary

        print data_dic # test point
        
        cursor.execute("INSERT INTO lightsensor(id,sensor_value,timestamp) VALUES (%(id)s, %(sensor_value)s, %(timestamp)s)", data_dic)
        conn.commit()
        #time.sleep(0.2) # Delay for 5 seconds    
    
if __name__ == "__main__":
    main()
