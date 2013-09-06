/*
  Taahir Ahmed
  ECEN 489 Lab 2
  
  Simple program to control an output based on analog input.
  
*/

int sensor_pin = A0;
int output_pin = 13;

// The measured voltage
int sensor_value = 0;

// The setpoint we desire.
int setpoint = 512;

void setup()
{
    // Declare the output pin as such.
    pinMode(output_pin, OUTPUT);
}

void loop()
{
    // Read the voltage on the analog input.
    sensor_value = analogRead(sensor_pin);

    if(sensor_value > setpoint)
      digitalWrite(output_pin, HIGH);
    else
      digitalWrite(output_pin, LOW);
}
