/*
  Zachary Partal
  ECEN 489 Lab 2
 */

int led1 = 6;
int led2 = 7;

int led_state1 = HIGH;
int led_state2 = LOW;

unsigned long curr_ms = 0;
long prev_ms_light = 0;
long prev_ms_pr = 0; 
int blink_interval = 1000; // blink interval in ms
int print_interval = 1000;

int pr_val = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(A0, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  curr_ms = millis();
  
  if (curr_ms - prev_ms_light > blink_interval) {
    prev_ms_light = curr_ms;
    
    if (led_state1 == LOW) {
      led_state1 = HIGH;
      led_state2 = LOW;
    }
    else {
      led_state1 = LOW;
      led_state2 = HIGH; 
    }    
  }

  if (curr_ms - prev_ms_pr > print_interval) {
    prev_ms_pr = curr_ms;
    pr_val = analogRead(A0);
    Serial.println(pr_val);    
  }
  
  // Write Pins
  digitalWrite(led1, led_state1);
  digitalWrite(led2, led_state2);
}
