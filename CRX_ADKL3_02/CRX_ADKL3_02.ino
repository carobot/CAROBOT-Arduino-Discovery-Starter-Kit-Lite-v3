/*
  Pushbutton
  Turn an LED "ON" and "OFF" when pressing a pushbutton.
*/
void setup() {
  // initialize the digital pin as an output.
  pinMode(11, OUTPUT); // LED as output
  pinMode(2, INPUT); // pushbutton as input
}
void loop() {

  // check if the pushbutton is pressed (HIGH).
  if (digitalRead(2) == HIGH) {
    // if it is, turn LED on (HIGH)
    digitalWrite(11, HIGH);
  } else {
    // if not, turn LED off
    digitalWrite(11, LOW);
  }
}

