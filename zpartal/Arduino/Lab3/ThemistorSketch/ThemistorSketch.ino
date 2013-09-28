/*
  Thermistor
 */

#include <math.h>

int sensorPin1 = A1;
int sensorPin2 = A2;
double vdc = 5.0;
double shhCoef[3];

double readFromSerial() {
  char buffer[] = {' ',' ',' '};
  while(!Serial.available());
  Serial.readBytesUntil('n',buffer,3);
  return atof(buffer);
}

void calibration(double *coef) {
  // 0 -> 97663
  // 25 -> 30000
  // 100 -> 2032

  double r_0c = 0;
  double r_rt = 0;
  double r_100c = 0;
  double t_0c = 0;
  double t_rt = 0;
  double t_100c = 0;  

  Serial.println("(1) Calibrate\n(2) Use Preset Values");
  int response = readFromSerial();
  if (response == 1) {
    Serial.println("BEGIN CALIBRATION PROCESS");
    Serial.println("Enter Known Temp Low (Ice Water):");
    t_0c = readFromSerial() + 273.15;
    r_0c = readThermRes();

    // Debug
    Serial.print("t0c: ");
    Serial.print(t_0c);
    Serial.print(" r_0c: ");
    Serial.println(r_0c);

    Serial.println("Enter Known Temp Mid (Room Temp):");
    t_rt = readFromSerial()  + 273.15;
    r_rt = readThermRes();

    // Debug
    Serial.print("t_rt: ");
    Serial.print(t_rt);
    Serial.print(" r_rt: ");
    Serial.println(r_rt);

    Serial.println("Enter Known Temp High (Boiling Water):");
    t_100c = readFromSerial()  + 273.15;
    r_100c = readThermRes();

    // Debug
    Serial.print("t100c: ");
    Serial.print(t_100c);
    Serial.print(" r_100c: ");
    Serial.println(r_100c);
  }
  else if (response == 2) {
    // If use preset values
    r_0c = 46000;
    r_rt = 29000;
    r_100c = 6000;
    t_0c = 0+273;
    t_rt = 27+273;
    t_100c = 100+273;
  }
  else {};

  // Steinhart-Hart
  double a = 0;
  double b = 0;
  double c = 0;

  double L1 = log(r_0c);
  double L2 = log(r_rt);
  double L3 = log(r_100c);

  double Y1 = t_0c == 0 ? 0 : (double)1.0/(double)t_0c;
  double Y2 = t_rt == 0 ? 0 : (double)1.0/(double)t_rt;
  double Y3 = t_100c == 0 ? 0 : (double)1.0/(double)t_100c;

  // Serial.println("BLAH");
  // Serial.println(L1);
  // Serial.println(L2);
  // Serial.println(L3);
  // Serial.println(Y1,DEC);
  // Serial.println(Y2,DEC);
  // Serial.println(Y3,DEC);

  double g2 = (Y2-Y1)/(L2-L1);
  double g3 = (Y3-Y1)/(L3-L1);

  // Serial.println("BLAH2");
  // Serial.println(g2,DEC);
  // Serial.println(g3,DEC);

  c = ((g3-g2)/(L3-L2))*(1/(L1+L2+L3));
  b = g2 - c*(pow(L1,2.0)+L1*L2+pow(L2,2.0));
  a = Y1 - (b+pow(L1,2.0)*c)*L1;

  // Serial.println("abc");
  // Serial.println(a, DEC);
  // Serial.println(b, DEC);
  // Serial.println(c, DEC);
  coef[0] = a;
  coef[1] = b;
  coef[2] = c;
  // Serial.println("coefs: ");
  // Serial.println(shhCoef[0], DEC);
  // Serial.println(shhCoef[1], DEC);
  // Serial.println(shhCoef[2], DEC);
}

// Return Thermistors Resistance
double thermRes() {
  double v2 = analogRead(sensorPin2);
  double Va = v2 * (vdc/1024.0);
  double resistance = (Va*33000.0)/(5-Va);
  return (double)resistance;
}

double readThermRes () {
  // Collect 5 Values
  double res[5];
  for (int i = 0; i < 5; i++) {
    res[i] = thermRes();
    delay(10);
  }
  // Take average of 5 values
  double avgRes = 0;
  for (int i = 0; i < 5; i++) {
    avgRes += res[i];
  }
  return avgRes/5;
}

double getTemp () {
  // Serial.println("getTemp()");
  double currRes = (double)readThermRes();
  // Serial.println(currRes);
  double temp = (1/(shhCoef[0]+shhCoef[1]*log(currRes)+shhCoef[2]*pow(log(currRes),3.0))) - 273.15;
  // Serial.println(temp);
  return temp;
}

void setup()  {   
  Serial.begin(9600);
  calibration(shhCoef);
  double temp = getTemp();
}

void loop()  { 
  double temp = getTemp();
  Serial.print("TEMP: ");
  Serial.print(temp);
  Serial.println(" C");
  // double res = readThermRes();
  // Serial.println(res);
  delay(300);
}
