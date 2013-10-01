/*
Title: Arduino Light Sensor
Author: John Boyd
Notes:

*/

// ---------------------
// CONTROL PARAMETERS
// ---------------------
int sensorPin = A0;    // select the input pin for the potentiometer

// ---------------------
// VARIABLE DECLARATIONS
// ---------------------
int sensorValue = 0;  // variable to store the value coming from the sensor
int state = 1;  // Start off in calibration input state for state machine
float calibrationValue[2] = {0,0};
float calibrationResistance[2] = {0,0};
float A = 0.0;
float B = 0.0;


// ---------------------
// FUNCTION DECLARATIONS
// ---------------------
String getInput();
double getResistance();
int calculateCoefficients(float V[2], float R[2]);
float resistance = 0.0;
float lux = 0.0;


// ---------------------
// DEVICE INITIALIZATION
// ---------------------
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  Serial.println("----------------------------");
  Serial.println("::::Arduino Light Sensor::::");
  Serial.println("----------------------------\n");
}


// ---------------------
// MAIN LOOP
// ---------------------
void loop() {
  switch(state)
  {
    case 1:  // Calibration input state
    {
      Serial.println("----------------------------");
      Serial.println("::::  Calibration Mode  ::::");
      Serial.println("----------------------------\n");
      Serial.println("We will require two sample light measurements.");
      
      String temp = "";
      
      for(int i = 0; i < 2; i++)  // Iterate for as many calibration factors as you will need
      {
        Serial.print(i+1);
        Serial.print(") ");
        
        temp = getInput("Enter the current light value (Lux): ");
        Serial.println(temp);
        
        calibrationValue[i] = atof(temp.c_str());        
        calibrationResistance[i] = getResistance(sensorPin);
      }
      
      // Display calibration info
      Serial.println("\nCalibration matrix:\n");
      Serial.println("Light Level (Lux)\t| Resistance (Ohms)");
      Serial.println("-------------------------------------------");
      Serial.print(calibrationValue[0]);
      Serial.print("\t\t\t| ");
      Serial.println(calibrationResistance[0]);
      Serial.print(calibrationValue[1]);
      Serial.print("\t\t\t| ");
      Serial.println(calibrationResistance[1]);
      
      state++;  // Advance to next state
      break;
    }
    
    case 2:  // Calculate coefficients
    {
      calculateCoefficients(calibrationValue, calibrationResistance);
      Serial.println("\nCalibration coefficients:");
      Serial.print("A = ");
      Serial.println(A);
      Serial.print("B = ");
      Serial.println(B);
      
      Serial.println("\n Light level measurements (Enter 'q' to quit and re-calibrate):");
      
      state++;  // Advance to next state
      break; 
    }
    
    case 3:  // Measure and display lux levels
    {
      if(Serial.available())  // Check for abort
      {
        if(getInput("") == "q")
        {
          state = 1;
        }
      }
      
      resistance = getResistance(sensorPin);
      lux = pow(10,A*log10(resistance) + B);
      
      Serial.print(lux);
      Serial.println(" (Lux)");
      
      delay(1000);
      break; 
    }
  }
}


// ---------------------
// FUNCTION DEFINITIONS
// ---------------------
String getInput(String prompt)
{
  char readChar = ' ';
  String usrInput = "";
  
  Serial.print(prompt);
  
  while (!Serial.available());  // Holds the program while waiting for input
  
  while (readChar != '\n') 
  {
    if(Serial.available())
    {
      readChar = (char)Serial.read();
      if(readChar != '\n')
      {
        usrInput += readChar;      
      }
      else break;
    }
  }
  
  return usrInput;  
}

double getResistance(int pin)
{
  double ADCVal = (double)analogRead(pin);
  return 1024*((10000-9.77*ADCVal)/ADCVal);  // For 10 bit ADC
}

int calculateCoefficients(float V[2], float R[2])
{
  float X[2] = {0, 0};
  float Y[2] = {0, 0};
  X[0] = log10(V[0]);
  X[1] = log10(V[1]);
  Y[0] = log10(R[0]);
  Y[1] = log10(R[1]);
  
  float Z = 1/(X[0] - X[1]);
  A = Z*(Y[0] - Y[1]);
  B = Z*(X[0]*Y[1] - X[1]*Y[0]);
  return 0;
} 

