
/*
Title: Arduino Light Sensor
Author: John Boyd, Amended by Brian Bass
Notes:

*/

// ---------------------
// CONTROL PARAMETERS
// ---------------------
int ledPin = 5;    // select the input pin for the potentiometer

// ---------------------
// VARIABLE DECLARATIONS
// ---------------------
char jsonString[256] = "";
int lightLevel = 0;

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
  Serial.println("TESTING");
  
  // Set ledPin as output
  pinMode(ledPin, OUTPUT);
}


// ---------------------
// MAIN LOOP
// ---------------------
void loop() {
  strcpy(jsonString, getInput("").c_str());
  
  //Hard code the light value from the JSON string
  char digit1 = jsonString[15];
  char digit2 = jsonString[16];
  char digit3 = jsonString[17];
  
  //Concatenate the individual digits into a number
  char light[4];
  light[0] = digit1;
  light[1] = digit2;
  light[2] = digit3;
  lightLevel = atoi(light);  
  
  //Print to serial line just for troubleshooting purposes
  Serial.print("lightLevel is ");Serial.print(lightLevel);Serial.print("\n");
  analogWrite(ledPin, lightLevel);
  
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
  
  while (readChar != '\n') 
  {
    while(Serial.available())
    {
      readChar = (char)Serial.read();
      if(readChar != '\n')
      {
        Input += readChar;      
      }
      else break;
    }
    
  }
  Serial.print(Input);
  return Input;  
}
