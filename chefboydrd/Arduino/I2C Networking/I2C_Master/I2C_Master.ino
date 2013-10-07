#include <Wire.h>

/*
Title: I2C Master Sketch
Author: John Boyd
Notes:

*/

// ---------------------
// CONTROL PARAMETERS
// ---------------------
const int ledPin = 13;
const int byteCount = 4;

// ---------------------
// VARIABLE DECLARATIONS
// ---------------------
int i = 0;
long received = 0;
double voltage = 0;

// ---------------------
// FUNCTION DECLARATIONS
// ---------------------


// ---------------------
// DEVICE INITIALIZATION
// ---------------------
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

// ---------------------
// MAIN LOOP
// ---------------------

void loop()
{
  Wire.requestFrom(1, byteCount);    // request number of bytes from slave device

  while(Wire.available())    // slave may send less than requested
  { 
    i++;
    received = received << 8;
    received |= Wire.read();
    
    if(i == byteCount)
    {
      voltage = received / 100; // Convert long back to double
      Serial.print("Voltage on slave ");
      Serial.print(1);
      Serial.print(" = ");
      Serial.println(voltage); // Send to COM
    }
  }

  i = 0;
  
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

