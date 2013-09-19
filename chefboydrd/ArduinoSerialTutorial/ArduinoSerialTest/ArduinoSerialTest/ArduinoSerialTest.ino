void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
}

int i = 0;

void loop()                       // run over and over again
{
  delay(3000);
  Serial.println("Hey there Mr. Computer");
  
  while(1)
  {
    Serial.println(i);
    delay(100);
    i++;
  }
}
