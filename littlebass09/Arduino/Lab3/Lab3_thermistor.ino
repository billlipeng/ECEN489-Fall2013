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
double vB = 0;
double resistance = 0;
double temperature = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  
}

double calculateResistance(double vB)
{
  return (vB*33000)/(5 - vB);
}

double calculateTemperature(double Rpd)
{
  double a = 4.993;
  double b = -.7397;
  double c = .002438;

  return 1/(a + b*log(Rpd) + c*(log(Rpd)*log(Rpd)*log(Rpd)));
}

void loop() {
  sensorValue = analogRead(sensorPin);    
  vB = ((double)sensorValue)/1024.0*5;
  resistance = calculateResistance(vB);
  temperature = calculateTemperature(resistance);
  Serial.print("Sensor Value = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  Serial.print("vB = ");
  Serial.print(vB);
  Serial.print("\n");
  Serial.print("Resistance = ");
  Serial.print(resistance);
  Serial.print("\n");
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print("\n\n");
  
  delay(1000);  
}
