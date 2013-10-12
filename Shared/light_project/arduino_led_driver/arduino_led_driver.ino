int ledPin = 11;    // select the input pin for the potentiometer
int lightLevel = 0;
 
double readFromSerial() {
  char buffer[] = {' ',' ',' '};
  while(!Serial.available());
  Serial.readBytesUntil('n',buffer,3);
  return atof(buffer);
}
 
void setup() {
  // Initialize serial port
  Serial.begin(9600);
  
  // Set ledPin as output
  pinMode(ledPin, OUTPUT);
}
 
void loop() {
  double val = readFromSerial();
  int map_val = map(int(val), -10, 110, 255, 0);
  Serial.println(map_val);
  analogWrite(ledPin, map_val);
}