/*
  Blink
  Turn an LED "ON" for one second, "OFF" for one second,
  and repeat forever.

  This is a multi-line comment.
*/
void setup() {
  // initialize the digital pin as an output.
  // This is a single line comment
  pinMode(11, OUTPUT);
}
void loop() {
  digitalWrite(11, HIGH); // set the LED on
  delay(1000); // wait for one second
  digitalWrite(11, LOW); // set the LED off
  delay(1000); // wait for one second
}

