
// Motor Control Using PWM

int green_led = 9;  //green led is attached to pin 9
int red_led = 10;   //red led is attached to pin 10
int red_bright = 0;  //brightness of red led is initialized to zero
int green_bright = 0;  //brightness of green led is initialized to zero

void setup()  { 
  // declare pin 9 and pin 10 to be outputs:
  pinMode(green_led, OUTPUT);  //declaring pin 9 as output pin
  pinMode(red_led, OUTPUT);  //declaring pin 10 as output pin
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9 from 0 to 255, keeping pin 10 at ZERO:
  for (red_bright = 0; red_bright < 255; red_bright++){
   analogWrite(red_led, red_bright);
   analogWrite(green_led, green_bright);
  }
  
  delay(1000);
  
  // set the brightness of pin 9 back from 255 to 0, keeping pin 10 at ZERO: 
  for (red_bright = 255; red_bright > 0; red_bright--){
    analogWrite(red_led, red_bright);
    analogWrite(green_led, green_bright);
  }
  
  // keep a delay of 1 sec so both leds are off
  delay(1000);
  
  // set the brightness of pin 10 from 0 to 255, keeping pin 9 at ZERO:
  for (green_bright = 0; green_bright < 255; green_bright++){
   analogWrite(red_led, red_bright);
   analogWrite(green_led, green_bright);
  }
  
  delay(1000);
  
  // set the brightness of pin 10 back from 255 to 0, keeping pin 9 at ZERO:
  for (green_bright = 255; green_bright > 0; green_bright--){
    analogWrite(red_led, red_bright);
    analogWrite(green_led, green_bright);
  }
  
  // keep a delay of 1 sec so both leds are off
  delay(1000);
  
}

