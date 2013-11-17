/* This file is part of the Razor AHRS Firmware */

// I2C code to read the sensors

// Sensor I2C addresses
#define ACCEL_ADDRESS ((int) 0x53) // 0x53 = 0xA6 / 2
#define MAGN_ADDRESS  ((int) 0x1E) // 0x1E = 0x3C / 2
#define GYRO_ADDRESS  ((int) 0x68) // 0x68 = 0xD0 / 2

// Arduino backward compatibility macros
#if ARDUINO >= 100
  #define WIRE_SEND(b) Wire.write((byte) b) 
  #define WIRE_RECEIVE() Wire.read() 
#else
  #define WIRE_SEND(b) Wire.send(b)
  #define WIRE_RECEIVE() Wire.receive() 
#endif


void I2C_Init()
{
  Wire.begin();
}

void Accel_Init()
{
  Wire.beginTransmission(ACCEL_ADDRESS);
  WIRE_SEND(0x2D);  // Power register
  WIRE_SEND(0x08);  // Measurement mode
  Wire.endTransmission();
  delay(5);
  Wire.beginTransmission(ACCEL_ADDRESS);
  WIRE_SEND(0x31);  // Data format register
  WIRE_SEND(0x08);  // Set to full resolution
  Wire.endTransmission();
  delay(5);
  
  // Because our main loop runs at 50Hz we adjust the output data rate to 50Hz (25Hz bandwidth)
  Wire.beginTransmission(ACCEL_ADDRESS);
  WIRE_SEND(0x2C);  // Rate
  WIRE_SEND(0x09);  // Set to 50Hz, normal operation
  Wire.endTransmission();
  delay(5);
}

// Reads x, y and z accelerometer registers
void Read_Accel()
{
  int i = 0;
  byte buff[6];
  
  Wire.beginTransmission(ACCEL_ADDRESS); 
  WIRE_SEND(0x32);  // Send address to read from
  Wire.endTransmission();
  
  Wire.beginTransmission(ACCEL_ADDRESS);
  Wire.requestFrom(ACCEL_ADDRESS, 6);  // Request 6 bytes
  while(Wire.available())  // ((Wire.available())&&(i<6))
  { 
    buff[i] = WIRE_RECEIVE();  // Read one byte
    i++;
  }
  Wire.endTransmission();
  
  if (i == 6)  // All bytes received?
  {
    // No multiply by -1 for coordinate system transformation here, because of double negation:
    // We want the gravity vector, which is negated acceleration vector.
    accel[0] = (((int) buff[3]) << 8) | buff[2];  // X axis (internal sensor y axis)
    accel[1] = (((int) buff[1]) << 8) | buff[0];  // Y axis (internal sensor x axis)
    accel[2] = (((int) buff[5]) << 8) | buff[4];  // Z axis (internal sensor z axis)
  }
  else
  {
    num_accel_errors++;
    if (output_errors) Serial.println("!ERR: reading accelerometer");
  }
}





void Gyro_Init()
{
  // Power up reset defaults
  Wire.beginTransmission(GYRO_ADDRESS);
  WIRE_SEND(0x3E);
  WIRE_SEND(0x80);
  Wire.endTransmission();
  delay(5);
  
  // Select full-scale range of the gyro sensors
  // Set LP filter bandwidth to 42Hz
  Wire.beginTransmission(GYRO_ADDRESS);
  WIRE_SEND(0x16);
  WIRE_SEND(0x1B);  // DLPF_CFG = 3, FS_SEL = 3
  Wire.endTransmission();
  delay(5);
  
  // Set sample rato to 50Hz
  Wire.beginTransmission(GYRO_ADDRESS);
  WIRE_SEND(0x15);
  WIRE_SEND(0x0A);  //  SMPLRT_DIV = 10 (50Hz)
  Wire.endTransmission();
  delay(5);

  // Set clock to PLL with z gyro reference
  Wire.beginTransmission(GYRO_ADDRESS);
  WIRE_SEND(0x3E);
  WIRE_SEND(0x00);
  Wire.endTransmission();
  delay(5);
}

// Reads x, y and z gyroscope registers
void Read_Gyro()
{
  int i = 0;
  byte buff[6];
  
  Wire.beginTransmission(GYRO_ADDRESS); 
  WIRE_SEND(0x1D);  // Sends address to read from
  Wire.endTransmission();
  
  Wire.beginTransmission(GYRO_ADDRESS);
  Wire.requestFrom(GYRO_ADDRESS, 6);  // Request 6 bytes
  while(Wire.available())  // ((Wire.available())&&(i<6))
  { 
    buff[i] = WIRE_RECEIVE();  // Read one byte
    i++;
  }
  Wire.endTransmission();
  
  if (i == 6)  // All bytes received?
  {
    gyro[0] = -1 * ((((int) buff[2]) << 8) | buff[3]);    // X axis (internal sensor -y axis)
    gyro[1] = -1 * ((((int) buff[0]) << 8) | buff[1]);    // Y axis (internal sensor -x axis)
    gyro[2] = -1 * ((((int) buff[4]) << 8) | buff[5]);    // Z axis (internal sensor -z axis)
  }
  else
  {
    num_gyro_errors++;
    if (output_errors) Serial.println("!ERR: reading gyroscope");
  }
}

int calibrate_sensors(){    // Set zero sensor values
  float cal_val;
   // Read incoming control messages
  if (Serial.available() !=0)
  {
    int command = Serial.read();
    
    if ( command == 'a') {
    Serial.println("Calibrate Acc 3 axies.");
    Serial.println("Make IMU horizontal and upward to set Acc_X and Acc_Y zero.");
    Serial.println("Waiting...");
    delay(5000);
    Serial.println("Calibrating...");
    for(int n=0; n< 2; n++) { // accel[0], accel[1] are acc_x and acc_y respectively
    cal_val = 0;
    for(int i=0; i<50; i++) {
       Read_Accel();
       cal_val += accel[n]; 
    }  
   // Serial.println(cal_val);
    sensorZero[n] = cal_val/50.0;
    }   
    cal_val = 0;
    Serial.println("Calibration finished");
    Serial.println("Make IMU vertical and leftward to set Acc_z zero.");
    Serial.println("Waiting...");
    delay(5000);
    Serial.println("Calibrating...");
    for(int i=0; i<50; i++) {
      Read_Accel();
      cal_val += accel[2];  // acc_z
    }
   // Serial.println(cal_val);
    sensorZero[2] = cal_val/50.0;
    cal_val = 0;
    Serial.println("Calibration finished.");
    Serial.println("Calibration results are");
    for(int j=0; j<3; j++)
      Serial.println(sensorZero[j]); 
    return 0;
    } 
    else if ( command == 'g') {      
      Serial.println("Calibrate Gyro 3 axies.");
      Serial.println("Waiting...");
      delay(5000);    
      for(int n=0; n< 3; n++) {
        cal_val = 0;
        for(int i=0; i<50; i++) {
           Read_Accel();
           cal_val += gyro[n];   
        }
        sensorZero[n+3] = cal_val/50.0;
      } 
      Serial.println("Calibration finished."); 
      Serial.println("Gyro calibration values are");
      for(int j=3; j<6; j++)
        Serial.println(sensorZero[j]); 
      return 1; 
    }
    
    else return 0;
   }  
   return 0;
}

void update_sensors(){
  float update_val;
  for(int n=0; n< 3; n++) {
    update_val = 0;
    for(int i=0; i< 5; i++) {
        Read_Accel();
        update_val += accel[n];
    }
    // Apply sensor calibration
    sensorValue[n] = update_val/5 - sensorZero[n];
  }
  
  for(int n=0; n< 3; n++) {
    update_val = 0;
    for(int i=0; i< 5; i++) {
        Read_Gyro();
        update_val += gyro[n];
    }
    // Apply sensor calibration
    sensorValue[n+3] = update_val/5 - sensorZero[n+3];
  }
  // Serial.println(sensorValue[2]);
}

float getGyroRate(int channel) {                                       
  return float(sensorValue[channel]/GYR_SCALE_FACTOR);                 // in g
}

float getAccAngle(int channel) {    
  return arccos(sensorValue[channel]/GRAVITY);                // in degree/s
}

float arccos(float x){
  if(x>1) x=1;
  else if(x<-1) x=-1;
  float angle = 57.3*acos(x);
  //angle = abs(angle);
  return angle;
}
