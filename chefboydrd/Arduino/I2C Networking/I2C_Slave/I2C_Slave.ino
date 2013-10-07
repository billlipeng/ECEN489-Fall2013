#include <Wire.h>

/*
Title: I2C Slave Sketch
Author: John Boyd
Notes:

*/

// ---------------------
// CONTROL PARAMETERS
// ---------------------
const int I2C_slaveAddress = 1;    // select the input pin for the potentiometer
const int ledPin = 13;
const int sensorPin = A0;

// ---------------------
// VARIABLE DECLARATIONS
// ---------------------
int i = 0;
double voltage = 0;
long output = 0;
// ---------------------
// FUNCTION DECLARATIONS
// ---------------------


// ---------------------
// DEVICE INITIALIZATION
// ---------------------
void setup()
{
  pinMode(ledPin, OUTPUT);
  Wire.begin(I2C_slaveAddress);
  Wire.onRequest(requestEvent);
}

// ---------------------
// MAIN LOOP
// ---------------------

void loop()
{
  delay(200);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  // Read voltage
  voltage = (double) analogRead(sensorPin) * .00488;
 
  // Convert double to long for transmission
  output = voltage * ;
  
  // Send long value
  Wire.write(output && 0xFF);
  Wire.write((output >> 8) && 0xFF);
  Wire.write((output >> 16) && 0xFF);
  Wire.write((output >> 24) && 0xFF);
}

