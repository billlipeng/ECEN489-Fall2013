int i = 0;  // loop variable

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9,10 to be an output:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  writeGreenLED();
  delay(1000);
  writeRedLED();
  delay(1000);
}

int writeRedLED() {
  for (i = 0; i < 255; i++) { // loop from 0 to 254 (fade in)
    analogWrite(10, i);      // set the LED brightness
    delay(10); // fade 30ms
  }

  for (i = 255; i > 0; i--) { // loop from 255 to 1 (fade out)
    analogWrite(10, i); // set the LED brightness
    delay(10);          // fade 30ms
  }
}

int writeGreenLED() {
  for (i = 0; i < 255; i++) { // loop from 0 to 254 (fade in)
    analogWrite(9, i);      // set the LED brightness
    delay(10); // fade 30ms
  }

  for (i = 255; i > 0; i--) { // loop from 255 to 1 (fade out)
    analogWrite(9, i); // set the LED brightness
    delay(10);          // fade 30ms
  }
}

