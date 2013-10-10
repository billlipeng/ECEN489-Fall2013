/*
Motor Controller
*/

#include <aJSON.h>
#include <avr/pgmspace.h>

#define sensorPin1 A0  //junction of D1 and D2...read voltage
#define sensorPin2 A1  //junction of D3 and D4...read voltage

int enablePin = 10;
int controlPin1 = 9;
int controlPin2 = 8;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int reading1, reading2;
double voltage, voltage1, voltage2;
double temp_avg;

void setup() {
  
  pinMode(enablePin, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  
  Serial.begin(9600);
  inputString.reserve(200);
}


void loop() {

  string json_string;
  
   if (stringComplete) {
    Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
//  aJsonObject* jsonObject = aJson.parse(json_string);
//  aJsonObject* name = aJson.getObjectItem(jsonObject , "temp_avg");
//  Serial.println(name->valuestring);
  /*
  need mini parser for JSON object
  JSON object contains average temperature
  
  define temperature ranges
  if received 
*/
  
// motor control logic, needs temp_avg reading from serial in order to operate
  
  if(temp_avg > 325)  {
      analogWrite(controlPin1, 255);
      delay(10);
  } else if((temp_avg <= 325 )&&(temp_avg > 280)) {
      analogWrite(controlPin1, 128);
      delay(10);
  } else if(temp_avg <= 280) {
      analogWrite(controlPin1, 0);
      delay(10);    
  }
    


  reading1 = analogRead(A0);
  reading2 = analogRead(A1);
  voltage1 = reading1 * (5.0/1023);
  voltage2 = reading2 * (5.0/1023);
  voltage = abs(voltage1-voltage2);
  
  Serial.println(voltage);
  //code to interface with database
  //send voltage readings to voltage table
  delay(500);
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
