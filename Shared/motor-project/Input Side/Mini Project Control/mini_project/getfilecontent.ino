/*
Motor Controller
*/


#define sensorPin1 A0  //junction of D1 and D2...read voltage
#define sensorPin2 A1  //junction of D3 and D4...read voltage

int controlPin1 = 10;
int arduino_id;
float temp_avg;

void setup() {
  pinMode(controlPin1, OUTPUT);
  Serial.begin(9600);
}


void loop() {


    temp_avg = Serial.parseInt();

    int lowerBound = 297;
    int upperBound = 306;
    int range = upperBound - lowerBound;
    
    int difference = temp_avg - lowerBound;
    double valueToWrite = 255*difference/range;
    if(valueToWrite > 255)
      valueToWrite = 255;
    else if(valueToWrite < 75)
      valueToWrite = 0;
      
    Serial.print("{ \" motorVoltage \" : ");
    Serial.print(valueToWrite*5/255);
    Serial.print(" }");
    analogWrite(controlPin1, valueToWrite);
    delay(10);
    /*
    if(temp_avg > 300)  {
            Serial.println("{ \" motorVoltage \" : 5.00 }");
            digitalWrite(controlPin1, HIGH);
            delay(10);
     } else if((temp_avg <= 300 )&&(temp_avg > 298)) {
            Serial.println("{ \" motorVoltage \" : 2.50 }");
            analogWrite(controlPin1, 127);
            delay(10);            
     } else if(temp_avg <= 297) {
            Serial.println("{ \" motorVoltage \" : 0 }");
            analogWrite(controlPin1, 0);
            delay(10);    
     } 
     */
    
}


