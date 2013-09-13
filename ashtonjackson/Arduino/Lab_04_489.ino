/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int Forward = 9;           // the pin that the LED is attached to
int Back = 10;
int forwardSpeed = 0;    // how bright the LED is
int backSpeed = 0;    // how many points to fade the LED by
int totalSpeed = 0;
int incrementSpeed = 5;
int ForwardOrBack = 0; // 0 = back; 1 = forward

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(Forward, OUTPUT);
  pinMode(Back, OUTPUT);
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // Sets one direction to zero:
  if (ForwardOrBack == 0) {
    analogWrite(Back, totalSpeed); 
    analogWrite(Forward, 0); 
  }  
  else {
    analogWrite(Back, 0);
    analogWrite(Forward, totalSpeed);
  }
  
  // change the brightness for next time through the loop:
  totalSpeed = totalSpeed + incrementSpeed;

  // reverse the direction of the fading at the ends of the fade: 
  if (totalSpeed == 0 || totalSpeed == 255) {
    incrementSpeed = -incrementSpeed ; 
  }     
    if (totalSpeed == 0) {
    ForwardOrBack = (ForwardOrBack ==1) ? 0 : 1; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);    
  Serial.print("Total Speed: ");
  Serial.print(ForwardOrBack);
  Serial.print("\n");
}

