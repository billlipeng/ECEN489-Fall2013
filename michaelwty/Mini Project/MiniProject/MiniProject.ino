/*
  Sample sketch communicating over Serial using JSON

  This sketch communicates over serial link with a computer, sending
  JSON-encoded state of its analog pints every second and accepting
  per-line JSON messages with desired values of PWM pins on input.

  Circuit:
  * (Optional) Analog sensors attached to analog pin.
  * (Optional) LEDs attached to PWM pins 9 and 8.

  created 1 November 2012
  by Petr Baudis

  https://github.com/interactive-matter/ajson
  This code is in the public domain.
 */

#include <aJSON.h>

const int analogPin = A0;

unsigned long last_print = 0;
aJsonStream serial_stream(&Serial);

void setup()
{
  Serial.begin(9600);
}

/* Generate message like: { "analog": [0, 200, 400, 600, 800, 1000] } */
aJsonObject *createMessage()
{
  aJsonObject *msg = aJson.createObject(); // create a Json object
  aJsonObject *id  = aJson.createItem("1"); // id is 1
  aJsonObject *sensor_value = aJson.createItem(analogRead(analogPin));

  aJson.addItemToObject(msg, "sensor_value", sensor_value);// add key 'sensor_value' and its value to a JSON object msg
  aJson.addItemToObject(msg, "id", id); // add key 'id' and its value to a JSON object msg
  return msg;
}



void loop()
{
  if (millis() - last_print > 1000) {
    /* One second elapsed, send message. */
    aJsonObject *msg = createMessage();
    aJson.print(msg, &serial_stream);
    Serial.println(); /* Add newline. */
    aJson.deleteItem(msg);
    last_print = millis();
  }

}
