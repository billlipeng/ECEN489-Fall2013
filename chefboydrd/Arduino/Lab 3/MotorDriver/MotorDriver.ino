int motorCtl_1 = 9;
int motorCtl_2 = 10;
int voltageLevel = 0;
int fadeAmount = 5;  

void setup()  { 
  pinMode(motorCtl_1, OUTPUT);
  pinMode(motorCtl_2, OUTPUT);
} 

void testMotor(int pin, int count);

void loop()  { 
  digitalWrite(motorCtl_2, LOW);
  testMotor(motorCtl_1, 1);
  delay(1000); 
  digitalWrite(motorCtl_1, LOW);
  testMotor(motorCtl_2, 1); 
  delay(1000);
}

void testMotor(int pin, int count)
{
  for(int i = 0; i < count; i++)
  {
    voltageLevel = 5;
    delay(30);
    
    while(voltageLevel)
    {
      analogWrite(pin, voltageLevel);    

      voltageLevel = voltageLevel + fadeAmount;
 
      if (voltageLevel == 0 || voltageLevel == 255) {
        fadeAmount = -fadeAmount ; 
      }     
      delay(30);
    }
  }
}
