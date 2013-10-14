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

// motor control logic, needs temp_avg reading from serial in order to operate
  
 // while (Serial.available() > 0) {
    
    //look for first integer in JSON string
  // arduino_id = Serial.parseInt();
 //  Serial.print("Arduino ID: ");
   //Serial.println(arduino_id);

   //look for sensor data value in JSON string
   temp_avg = Serial.parseInt();
 //  Serial.print("Temperature: ");
   //Serial.println(temp_avg);
   
/*   
   String s;
   while(Serial.available() > 0)
  {
      char c = Serial.read();
      Serial.print('a');
      //s = s + c;
  }
  */
 // Serial.print(temp_avg);
  delay(10);
  
  //Serial.print(s);

//  Serial.print(temp_avg);
    if(temp_avg > 300)  {
            Serial.println("{ \" motorVoltage \" : 5.00 }");
            digitalWrite(controlPin1, HIGH);
            delay(10);
     } else if((temp_avg <= 300 )&&(temp_avg > 297)) {
            Serial.println("{ \" motorVoltage \" : 2.50 }");
            analogWrite(controlPin1, 127);
            delay(10);            
     } else if(temp_avg <= 297) {
            Serial.println("{ \" motorVoltage \" : 0 }");
            analogWrite(controlPin1, 0);
            delay(10);    
     } 
    
}


