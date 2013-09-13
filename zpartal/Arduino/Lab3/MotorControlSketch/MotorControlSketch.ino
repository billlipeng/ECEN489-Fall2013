/*
  Motor Control Sketch
 */

int forwardPin = 9;
int backwardPin = 10;
int forwardSpeed = 0;
int backwardSpeed = 0;
int speedAmount = 0;
int speedIncrement = 5;
int direction = 0; // 1 for forward, 0 for backward

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 

  // Gurantees at least one direcion is zero before write
  if (direction == 1) {
    analogWrite(forwardPin, speedAmount);
    analogWrite(backwardPin, 0);
  }
  else {
    analogWrite(forwardPin, 0);
    analogWrite(backwardPin, speedAmount);
  }

  // change the speedAmount for next time through the loop:
  speedAmount += speedIncrement;

  // reverse the direction of the fading at the ends of the fade: 
  if (speedAmount == 0 || speedAmount == 255) {
    speedIncrement = -speedIncrement;
  }

  if (speedAmount == 0) {
    direction = (direction == 1) ? 0 : 1;
  }
  
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);     
  Serial.print("speedAmount ");
  Serial.print(direction);
  Serial.print("\n");               
}
