/*
  Ashton Jackson Lab 02 
*/
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 7;
int led2 = 8;
int sensorPin = A0;
int sensorValue = 0;

// the setup routine runs once when you press reset:
void setup() {         
  Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT); 
  pinMode(A0, INPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  Serial.print("\t output = ");
}
