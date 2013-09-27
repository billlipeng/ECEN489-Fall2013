/*
  PhotoCell
 */

#include <math.h>

int sensorPin = A0;
int rawVal = 0;
double r2Val = 9380;
double vdc = 5.0;
double rmin = 0;
double rmax = 0;
double luxmin = 0;
double luxmax = 0;
double gamma = 0;

double readFromSerial() {
  char buffer[] = {' ',' ',' '};
  while(!Serial.available());
  Serial.readBytesUntil('n',buffer,3);
  return atof(buffer);
}

void calibration() {
  // double r_0 = 0;
  // double r_1 = 0;
  double l_0 = 0;
  double l_1 = 100;

  Serial.println("BEGIN CALIBRATION PROCESS");
  Serial.println("Darkness 0.1 Lux:");
  readFromSerial();
  rmin = readPhotoRes();
  Serial.print("RMIN: ");
  Serial.println(rmin);

  Serial.println("Brightness 10000 Lux:");
  readFromSerial();
  rmax = readPhotoRes();
  Serial.print("RMAX: ");
  Serial.println(rmax);

  gamma = (log(rmin)-log(rmax))/(log(10000)-log(.1));
}

// Return PhotoReistor Resistance
long photoRes() {
  double vin = analogRead(sensorPin);
  double Va = vin * (vdc/1023.0);
  long resistance = (vdc*r2Val)/Va - r2Val;
  return resistance;
}

long readPhotoRes () {
  // Collect 5 Values
  long res[5];
  for (int i = 0; i < 5; i++) {
    res[i] = photoRes();
    delay(10);
  }
  // Take average of 5 values
  long avgRes = 0;
  for (int i = 0; i < 5; i++) {
    avgRes += res[i];
  }
  return avgRes/5;
}

double getLux() {
	// double lux = 255.84*pow(readPhotoRes(),-10/9);
  double exponent = (log(rmin/readPhotoRes())/gamma)+log(0.1);
  double lux = pow(2.718,exponent);
  // Serial.print("LUX RAW: ");
  // Serial.println(lux, DEC);
	return lux;
}

void setup()  {   
  Serial.begin(9600);
  calibration();
}

void loop()  { 
  long resistance = photoRes(); 
  double lux = getLux(); 
  Serial.print("Resistance: ");
  Serial.print(resistance);
  Serial.print(" LUX: ");
  Serial.print(lux);
  Serial.println();
  delay(500);  
}