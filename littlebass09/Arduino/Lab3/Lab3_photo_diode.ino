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

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
}

double calculateResistance(double vA)
{
  return (50000)/vA - 10000;
}

int calculateLux(double Rpd)
{
  double a = .0000015662;
  double b = -.02656;
  double c = 112.972;
  
  return a*Rpd*Rpd + b*Rpd + c;
}

void loop() {
  sensorValue = analogRead(sensorPin);    
  vA = ((double)sensorValue)/1024.0*5;
  resistance = calculateResistance(vA);
  lux = calculateLux(resistance);
  Serial.print("Sensor Value = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  Serial.print("vA = ");
  Serial.print(vA);
  Serial.print("\n");
  Serial.print("Resistance = ");
  Serial.print(resistance);
  Serial.print("\n");
  Serial.print("Lux = ");
  Serial.print(lux);
  Serial.print("\n\n");
  
  delay(100);                  
}
