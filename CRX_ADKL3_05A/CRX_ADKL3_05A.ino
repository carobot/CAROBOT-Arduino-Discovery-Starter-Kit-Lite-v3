/*
  MULTIPLE LEDs: Make five LEDs dance. Dance LEDs, dance!
*/

// use an "array" to keep track of all LED pins
int ledPins[] = {5,6,9,10,11};
int sensorPin = A0;

void setup() {

  int index; // a variable to keep track of the “for()” loop

  for(index = 0; index <= 4; index++) {
    pinMode(ledPins[index], OUTPUT);
    // ledPins[index] is replaced by the value in the array.
    // For example, ledPins[0] is 9
  }
}

void loop() {
  int index;
  int sensorValue;

  sensorValue = analogRead(sensorPin);

  // Turn all the LEDs on:
  // This for() loop will step index from 0 to 4
  // (putting "++" after a variable means add one to it)
  // and will then use digitalWrite() to turn that LED on.
  // Timing between the on/off of each LED depends on sensorValue
  
  for(index = 0; index <= 4; index++) {
    digitalWrite(ledPins[index], HIGH);
    delay(sensorValue);                
  }                                  

  // Turn all the LEDs off:
  // This for() loop will step index from 4 to 0
  // (putting "--" after a variable means subtract one from it)
  // and will then use digitalWrite() to turn that LED off.
 
  for(index = 4; index >= 0; index--) {
    digitalWrite(ledPins[index], LOW);
    delay(sensorValue);
  }
}
