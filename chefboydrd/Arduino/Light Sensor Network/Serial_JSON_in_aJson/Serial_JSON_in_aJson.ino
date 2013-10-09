#include <aJSON.h>

/*
Title: Arduino Light Sensor
Author: John Boyd
Notes:

*/

// ---------------------
// CONTROL PARAMETERS
// ---------------------
int ledPin = 13;    // select the input pin for the potentiometer

// ---------------------
// VARIABLE DECLARATIONS
// ---------------------
char jsonString[256] = "";
String LEDstate = "OFF";

// ---------------------
// FUNCTION DECLARATIONS
// ---------------------
  String getInput();

// ---------------------
// DEVICE INITIALIZATION
// ---------------------
  void setup() {
  // Initialize serial port
  Serial.begin(9600);
  
  // Set ledPin as output
  pinMode(ledPin, OUTPUT);
}


// ---------------------
// MAIN LOOP
// ---------------------
void loop() {
  strcpy(jsonString, getInput("").c_str());
  
  aJsonObject* root = aJson.parse(jsonString);
  LEDstate = aJson.getObjectItem(root, "LEDstate")->valuestring;

  if(LEDstate == "ON")
    digitalWrite(ledPin, HIGH);
  else if(LEDstate == "OFF")
    digitalWrite(ledPin, LOW);
}


// ---------------------
// FUNCTION DEFINITIONS
// ---------------------
String getInput(String prompt)
{
  char readChar = ' ';
  String Input = "";
  
  if(prompt != "")
  {
    Serial.print(prompt);
  }
  
  while (!Serial.available());  // Holds the program while waiting for input
  
  while (readChar != '\n') 
  {
    if(Serial.available())
    {
      readChar = (char)Serial.read();
      if(readChar != '\n')
      {
        Input += readChar;      
      }
      else break;
    }
  }
  
  return Input;  
}
