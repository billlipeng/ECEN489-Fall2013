/*
Title: Arduino Temperature Sensor
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
float calibrationValue[3] = {0,0,0};
float calibrationResistance[3] = {0,0,0};
float A = 0.0;
float B = 0.0;
float C = 0.0;
float resistance = 0.0;
float Temp = 0.0;

// ---------------------
// FUNCTION DECLARATIONS
// ---------------------
String getInput();
double getResistance();
int calculateCoefficients(float V[3], float R[3]);
double calcTemperature(double resistance, float A, float B, float C);

// ---------------------
// DEVICE INITIALIZATION
// ---------------------
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  Serial.println("----------------------------------");
  Serial.println("::::Arduino Temperature Sensor::::");
  Serial.println("----------------------------------\n");
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
      Serial.println("We will require three sample temperature measurements.");
      
      String temp = "";
      
      for(int i = 0; i < 3; i++)  // Iterate for as many calibration factors as you will need
      {
        Serial.print(i+1);
        Serial.print(") ");
        
        temp = getInput("Enter the current temperature (C): ");
        Serial.println(temp);
        
        calibrationValue[i] = atof(temp.c_str());        
        calibrationResistance[i] = getResistance(sensorPin);
      }
      
      // Display calibration info
      Serial.println("\nCalibration matrix:\n");
      Serial.println("Temperature (C)\t| Resistance (Ohms)");
      Serial.println("-------------------------------------------");
      Serial.print(calibrationValue[0]);
      Serial.print("\t\t| ");
      Serial.println(calibrationResistance[0]);
      Serial.print(calibrationValue[1]);
      Serial.print("\t\t| ");
      Serial.println(calibrationResistance[1]);
      Serial.print(calibrationValue[2]);
      Serial.print("\t\t| ");
      Serial.println(calibrationResistance[2]);
      
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
      Serial.print("C = ");
      Serial.println(C);
      
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
      Temp = calcTemperature(resistance, A, B, C);
      
      Serial.print(Temp);
      Serial.println(" (C)");
      
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
  Serial.println(ADCVal);
  return (161.1 * ADCVal) / (5 - .00488 * ADCVal);  // For 10 bit ADC
}

int calculateCoefficients(float V[3], float R[3])
{
  float L[2] = {0, 0};
  float Y[2] = {0, 0};
  
  // Calculate L values
  L[0] = log(R[0]);
  L[1] = log(R[1]);
  L[2] = log(R[2]);
  
  // Calculate Y values
  Y[0] = 1 / (V[0] + 273.15);
  Y[1] = 1 / (V[1] + 273.15);
  Y[2] = 1 / (V[2] + 273.15);
  
  // Calculate gammas
  float gamma2 = (Y[1] - Y[0]) / (L[1] - L[0]);
  float gamma3 = (Y[2] - Y[0]) / (L[2] - L[0]);
  
  float temp1 = (gamma3 - gamma2) / (L[2] - L[1]);
  float temp2 = (1 / (L[0] + L[1] + L[2]));
  
  // Calculate A, B & C
  C = temp1 * temp2;
  B = gamma2 - (C * (pow(L[0], 2.0) + (L[0] * L[1]) + pow(L[1], 2.0)));
  A = Y[0] - ((B + (pow(L[0], 2.0) * C)) * L[0]);
  
  return 0;
} 

double calcTemperature(double resistance, float A, float B, float C) 
{
   double temp = (C * pow(log(resistance), 3.0));
   double temp2 = (B * log(resistance));
   return (( 1 / (A + temp2 + temp)) - 273.15);
}
