import serial, psycopg2, json, sys, pprint, time, datetime
import numpy as np
from time import sleep
from collections import deque
from matplotlib import pyplot as plt


DBHOST = "fulla.ece.tamu.edu"
DBPORT = 5432
DBNAME = "light_team"
DBUSER = "light_team_user"
DBPASSWORD = "light_team_password"
TABLENAME = "lightsensor"


 
# class that holds analog data for N samples
class AnalogData:
  # constr
  def __init__(self, maxLen):
    self.ax = deque([0.0]*maxLen)
    self.ay = deque([0.0]*maxLen)
    self.ad = deque([0.0]*maxLen)
    self.ae = deque([0.0]*maxLen)
    self.maxLen = maxLen
 
  # ring buffer
  def addToBuf(self, buf, val):
    if len(buf) < self.maxLen:
      buf.append(val)
    else:
      buf.pop()
      buf.appendleft(val)

  # add data
  def add(self, data):
    assert(len(data) == 4)
    self.addToBuf(self.ax, data[0])
    self.addToBuf(self.ay, data[1])
    self.addToBuf(self.ad, data[2])
    self.addToBuf(self.ae, data[3])
    
# plot class
class AnalogPlot:
  # constr
  def __init__(self, analogData):
    # set plot to animated
    plt.ion() 
    self.axline, = plt.plot(analogData.ax)
    self.ayline, = plt.plot(analogData.ay)
    self.adline, = plt.plot(analogData.ad)
    self.aeline, = plt.plot(analogData.ae)
    plt.ylim([-50, 150])
 
  # update plot
  def update(self, analogData):
    self.axline.set_ydata(analogData.ax)
    self.ayline.set_ydata(analogData.ay)
    self.adline.set_ydata(analogData.ad)
    self.aeline.set_ydata(analogData.ae)
    plt.draw()
 
# main() function
def main():
  # initial values
  sensorValue1 = 0
  sensorValue2 = 0
  sensorValue3 = 0
  sensorValue4 = 0
  
   # set connection to our postgresql database
  conn=psycopg2.connect(
      host = DBHOST,
      database = DBNAME,
      user = DBUSER,
      password = DBPASSWORD
      )
  cursor = conn.cursor()
  print 'Connected!'

  # count the number of rows, look for the lastest timestamp
  cursor.execute(" SELECT sensor_value, timestamp FROM lightsensor")
  for count in xrange(cursor.rowcount):
    count += 1
    value,timestamp_n = cursor.fetchone()
  print 'The lastest indext is\n'
  print (count, value, timestamp_n)
  

  cursor.execute(" SELECT id,sensor_value, timestamp FROM lightsensor WHERE timestamp > %s", [timestamp_n])
  print 'The lastest created row is here.'


  # plot parameters 
  analogData = AnalogData(100)
  analogPlot = AnalogPlot(analogData)
  print 'plotting data...'
 
 
  while True:
     try:
       result = cursor.fetchmany()
       while result:
         for (id_v,sensorValue,timestamp)in result:
           if(id_v == '1'):
             sensorValue1 = sensorValue
           if(id_v == '2'):
             sensorValue2 = sensorValue
           if(id_v == '3'):
             sensorValue3 = sensorValue
           if(id_v == '4'):
             sensorValue4 = sensorValue
             
           print (id_v,sensorValue)
           
           data = [float(sensorValue1), float(sensorValue2),float(sensorValue3),float(sensorValue4)]
           analogData.add(data)
           analogPlot.update(analogData)
         result = cursor.fetchmany()

         
     except KeyboardInterrupt:
       print 'exiting'
       break
  # close serial
  ser.flush()
  ser.close()
 
# call main
if __name__ == '__main__':
  main()
