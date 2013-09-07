int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int relayPin = 12;
int lightValue = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT); 
}

void loop()
{
  lightLevel = analogRead(sensorPin);
  if(lightLevel > 500)
  {
   digitalWrite(ledPin, HIGH);
   digitalWrite(relayPin, HIGH); 
  }
  else
  {
   digitalWrite(ledPin, LOW);
   digitalWrite(relayPin, LOW); 
  }
}
