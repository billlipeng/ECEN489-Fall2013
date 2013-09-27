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
double temperature = 0;
int stage = 1;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
}

double calculateResistance(double vB)
{
  return (vB*33000)/(5 - vB);
}

double calculateCoefficientC(double t1, double t2, double t3, double r1, double r2, double r3)
{
  double x1 = log(r1);
  double x2 = log(r2);
  double x3 = log(r3);
  double y1 = x1*x1*x1;
  double y2 = x2*x2*x2;
  double y3 = x3*x3*x3;
  double d1 = 1/t1;
  double d2 = 1/t2;
  double d3 = 1/t3;
  
  double numerator = (d3 - d1 + (d2 - d1)/(x2 - x1)*x1 - ((d2 - d1)*x3)/(x2 - x1)); 
  double denominator = (y3 - y1 - (y1 - y2)/(x2 - x1)*x1 - (y1 - y2)/(x2 - x1)*x3);
  Serial.print("numerator = ");
  Serial.print(numerator);
  Serial.print("\n");
  Serial.print("denominator = ");
  Serial.print(denominator);
  Serial.print("\n");
  Serial.print("numerator/denominator = ");
  Serial.print(numerator/denominator);
  Serial.print("\n");
  
  
  return numerator/denominator;
}

double calculateCoefficientB(double t1, double t2, double t3, double r1, double r2, double r3, double c)
{
  double x1 = log(r1);
  double x2 = log(r2);
  double x3 = log(r3);
  double y1 = x1*x1*x1;
  double y2 = x2*x2*x2;
  double y3 = x3*x3*x3;
  double d1 = 1/t1;
  double d2 = 1/t2;
  double d3 = 1/t3;
  
  return (d2 - d1 + c*(y1-y2))/(x2 - x1);
}

double calculateCoefficientA(double t1, double t2, double t3, double r1, double r2, double r3, double b, double c)
{
  double x1 = log(r1);
  double x2 = log(r2);
  double x3 = log(r3);
  double y1 = x1*x1*x1;
  double y2 = x2*x2*x2;
  double y3 = x3*x3*x3;
  double d1 = 1/t1;
  double d2 = 1/t2;
  double d3 = 1/t3;
  
  return d1 - b*x1 - c*y1;
}

double calculateTemperature(double Rpd, double a, double b, double c)
{
  double z = Rpd;
  return 1/(a + b*z + c*z*z*z);
}

void loop() {  

  if(proceed & stage != 4)
  {
    Serial.print("Enter value to record a voltage\n");
    proceed = false;
  }
  
  valueEntered = false;
  char a = Serial.read();
  if(a != -1 | stage == 4)
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
        c = calculateCoefficientC(voltage1, voltage2, voltage3, resistance1, resistance2, resistance3);
        b = calculateCoefficientB(voltage1, voltage2, voltage3, resistance1, resistance2, resistance3, c);
        a = calculateCoefficientA(voltage1, voltage2, voltage3, resistance1, resistance2, resistance3, b, c);
        Serial.print("a = ");
        Serial.print(a);
        Serial.print("\n");
        Serial.print("b = ");
        Serial.print(b);
        Serial.print("\n");
        Serial.print("c = ");
        Serial.print(c);
        Serial.print("\n");
        stage = 1;
        break;
    }
    proceed = true;
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
    temperature = calculateTemperature(resistance, a, b, c);
    Serial.print("Sensor Value = ");
    Serial.print(sensorValue);
    Serial.print("\n");
    Serial.print("vA = ");
    Serial.print(vA);
    Serial.print("\n");
    Serial.print("Resistance = ");
    Serial.print(resistance);
    Serial.print("\n");
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.print("\n");
    
    delay(1000); 
  }
}
