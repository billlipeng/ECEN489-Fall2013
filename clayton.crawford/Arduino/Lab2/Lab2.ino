int photoSensor = 0;

void setup()
{
  pinMode(2, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  // read in voltage divider data
  int dividerSensor = analogRead(A0);
  // convert data into a voltage in decimal notation  
  float dividerVoltage = dividerSensor * (5.0 / 1024.0);
  // output to the serial monitor this voltage
  Serial.print("\nVoltage @ photoresistor divider: ");    
  Serial.print(dividerVoltage);
  
  // if the photoresistor is covered, the swithcing circuit turns on
  photoSensor = analogRead(A0);
  if(photoSensor < 400)
   digitalWrite(2, HIGH); 
  else digitalWrite(2, LOW); 
}
