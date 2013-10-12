//Written by Sam Carey

int sensorPin = A0;

#define AVG_LENGTH 5
#define ID 3

float sensor_val = 0;
float intercept = 0;
float slope = 0;
float minV = 0;
float maxV = 0;

double readFromSerial() {
  char buffer[] = {' ',' ',' '};
  while(!Serial.available());
  Serial.readBytesUntil('n',buffer,3);
  return atof(buffer);
}

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  calibrate();
}

void loop() {
  sensor_val = getPercent();
  
  //Manual implementation
  //{"sensor_val":50.00,"LEDstate":"ON"}
  Serial.print("{\"sensor_value\":");
  Serial.print(sensor_val);
  Serial.print(",\"id\":");
  Serial.print(ID);
  Serial.println("}");
 
  //Serial.print("\n");  //temporary for readability
  delay(200);
}

void calibrate(){  // y = mx + b
  Serial.println("Calibrate Max Brightness: ");
  readFromSerial();
  maxV = getAvg();  //max voltage/light
  Serial.println("Calibrate Min Brightness:");
  readFromSerial();
  minV = getAvg();  //min voltage/light
  
  slope = 100.0/(maxV-minV);  //assume linear percentage scale (0-100)
  intercept = -1*slope*minV;
}

float getPercent(){  // y = mx + b
  //return map(getAvg(), maxV, minV, 0, 100);
  return slope*getAvg() + intercept;
}

float getAvg(){
  float sum = 0;
  for (int i = 0 ; i < AVG_LENGTH ; ++i){
    sum += analogRead(sensorPin);
    delay(10);
  }
  return sum/AVG_LENGTH;
}