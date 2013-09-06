/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int red = 2;
int green = 3;
int photo = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(photo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT); 
 Serial.begin(9600); 
}

// the loop routine runs over and over again forever:
void loop() {
  int ms = analogRead(photo);
  Serial.print(analogRead(photo));
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(green, HIGH);
  delay(ms);               // wait for a second
  digitalWrite(green, LOW);    // turn the LED off by making the vol
  
  
  
  tage LOW
  digitalWrite(red, LOW);
  delay(ms);               // wait for a second
  Serial.print("\n");
}
