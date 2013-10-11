import serial, psycopg2, json, sys, pprint, time, datetime

SERIALPORT = 'COM3'
DBHOST = "ec2-184-73-175-240.compute-1.amazonaws.com"
DBPORT = 5432
DBNAME = "d9mfolvfgchviv"
DBUSER = "eybgpzgirvbvkb"
DBPASSWORD = "0l4089PrKyiYjC42_gkMsUD9id"
TABLENAME = "lightsensordata"


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

    cursor.execute("SELECT sensor_value FROM light_sensor WHERE id = '1' ")
    for (sensor_value, ) in cursor.fetchall():
        if int(sensor_value) < 500:
            print 'OFF'
            ser.write("F\n")
        else:
            print sensor_value
            ser.write("O\n")
        time.sleep(1) 
    
if __name__ == "__main__":
    main()
