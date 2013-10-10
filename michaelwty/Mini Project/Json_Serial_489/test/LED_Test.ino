#include <aJSON.h>

unsigned long last_print = 0;
aJsonStream serial_stream(&Serial);
int analogPin =0;
int led = 12;
int incomingbyte;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{    
    /*
    aJsonObject *msg = aJson.createObject();
    aJsonObject *data = aJson.createItem(Serial.read());
    aJson.addItemToObject(msg, "data", data);
    aJson.print(msg, &serial_stream);
    */
    if(Serial.available()>0){
      incomingbyte=Serial.read();
  }
      if(incomingbyte == 'O'){
        digitalWrite(led, HIGH);
  }
      if(incomingbyte == 'F'){
        digitalWrite(led,LOW);
  }
}
