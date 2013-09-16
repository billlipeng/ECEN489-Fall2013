void setup()  { 
  // declare pin 9,10 to be an output:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
} 

void loop()  { 
  oneDirection(); // first spin motor one direction
  delay(1000);	// delay for one second
  otherDirection(); // make motor spin the other direction
  delay(1000); // delay for one second
}

// make motor spin in one direction
int oneDirection() {
  for (int i = 0; i < 255; i++) { // rev up motor
    analogWrite(10, 0);
    analogWrite(9, i);
    delay(10);
  }

  for (int i = 255; i > 0; i--) { // rev down motor
    analogWrite(10, 0);
    analogWrite(9, i);
    delay(10);
  }
}

// make motor spin in other direction
int otherDirection() {
  for (int i = 0; i < 255; i++) { // rev up motor
    analogWrite(9, 0); // make sure other output is not "hanging"
    analogWrite(10, i); // sets motor speed
    delay(10); // delay of 10ms allows for gradual speed change
  }

  for (int i = 255; i > 0; i--) { // rev down motor
    analogWrite(9, 0);
    analogWrite(10, i); 
    delay(10);          
  }
}

