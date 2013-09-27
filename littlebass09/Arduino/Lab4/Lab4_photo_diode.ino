/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
double vA = 0;
double resistance = 0;
double lux = 0;
double voltages[3] = {0,0,0};
double resistances[3];
boolean wait = false;
double voltage1 = 0;
double voltage2 = 0;
double voltage3 = 0;
double resistance1 = 0;
double resistance2 = 0;
double resistance3 = 0;
double a = 0;
double b = 0;
double c = 0;
boolean proceed = true;
boolean valueEntered = false;
int stage = 1;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
}

double calculateResistance(double vA)
{
  return (50000)/vA - 10000;
}

double calculateCoefficientA(double lux1, double lux2, double lux3, double r1, double r2, double r3)
{
  double R1 = log(r1);
  double R2 = log(r2);
  double R3 = log(r3);
  double sumR = R1 + R2 + R3;
  double sumX = lux1 + lux2 + lux3;
  double sumXSquared = lux1*lux1 + lux2*lux2 + lux3*lux3;
  double sumXR = lux1*R1 + lux2*R2 + lux3*R3;  
  double result = (sumXSquared*sumR - sumX*sumXR)/(3*sumXSquared - sumX*sumX);
  return exp(result);
}

double calculateCoefficientB(double lux1, double lux2, double lux3, double r1, double r2, double r3)
{
  double R1 = log(r1);
  double R2 = log(r2);
  double R3 = log(r3);
  double sumR = R1 + R2 + R3;
  double sumX = lux1 + lux2 + lux3;
  double sumXSquared = lux1*lux1 + lux2*lux2 + lux3*lux3;
  double sumXR = lux1*R1 + lux2*R2 + lux3*R3;  
  double result = (3*sumXR - sumX*sumR)/(3*sumXSquared - sumX*sumX);
  return result;
}

int calculateLux(double Rpd, double a, double b)
{
  return (log(Rpd) - log(a))/b;
}

void loop() {
  if(stage < 5)
  {
    if(proceed & stage != 4)
    {
      Serial.print("Enter value to record a voltage\n");
      proceed = false;
    }
    
    valueEntered = false;
    char z = Serial.read();
    if(z != -1 | stage == 4)
      valueEntered = true;
      
    if(valueEntered)
    {
      switch(stage)
      {
        case 1:
          sensorValue = analogRead(sensorPin);    
          voltage1 = ((double)sensorValue)/1024.0*5;
          resistance1 = calculateResistance(voltage1);
          stage++;
          Serial.print("Voltage1 = ");
          Serial.print(voltage1);
          Serial.print("\n");
          Serial.print("Resistance1 = ");
          Serial.print(resistance1);
          Serial.print("\n");
          Serial.print("Stage = ");
          Serial.print(stage);
          Serial.print("\n");
          break;
        case 2:
          sensorValue = analogRead(sensorPin);    
          voltage2 = ((double)sensorValue)/1024.0*5;
          resistance2 = calculateResistance(voltage2);
          stage++;
          Serial.print("Voltage2 = ");
          Serial.print(voltage2);
          Serial.print("\n");
          Serial.print("Resistance2 = ");
          Serial.print(resistance2);
          Serial.print("\n");
          Serial.print("Stage = ");
          Serial.print(stage);
          Serial.print("\n");
          break;
        case 3:
          sensorValue = analogRead(sensorPin);    
          voltage3 = ((double)sensorValue)/1024.0*5;
          resistance3 = calculateResistance(voltage3);
          stage++;
          Serial.print("Voltage3 = ");
          Serial.print(voltage3);
          Serial.print("\n");
          Serial.print("Resistance3 = ");
          Serial.print(resistance3);
          Serial.print("\n");
          Serial.print("Stage = ");
          Serial.print(stage);
          Serial.print("\n");
          break;
        case 4:
          a = calculateCoefficientA(0, 500, 1000, resistance1, resistance2, resistance3);
          b = calculateCoefficientB(0, 500, 1000, resistance1, resistance2, resistance3);
          Serial.print("a = ");
          Serial.print(a);
          Serial.print("\n");
          Serial.print("b = ");
          Serial.print(b);
          Serial.print("\n");
          stage = 100;
          break;
      }
      proceed = true;
    }
    else
    {
      delay(10);
    }
  }
  else
  {
    double mean = 0;
    for(int i = 0; i < 5; i++)
    {
      mean = mean + analogRead(sensorPin);
    }  
    vA = mean/1024;
    resistance = calculateResistance(vA);
    lux = calculateLux(resistance, a, b);
    //Serial.print("Sensor Value = ");
//    Serial.print(sensorValue);
//    Serial.print("\n");
//    Serial.print("vA = ");
//    Serial.print(vA);
//    Serial.print("\n");
//    Serial.print("Resistance = ");
//    Serial.print(resistance);
//   Serial.print("\n");
    Serial.print("Lux = ");
    Serial.print(lux);
    Serial.print("\n");
    
    delay(100);  
  }
}
