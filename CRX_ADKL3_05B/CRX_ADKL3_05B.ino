/*
  MULTIPLE LEDs: Bar Graph! Up, down, up, down!
*/

// use an "array" to keep track of all LED pins
int ledPins[] = {5,6,9,10,11};
int sensorPin = A0;

void setup() {

  int index; // a variable to keep track of the “for()” loop

  for(index = 0; index <= 4; index++) {
    pinMode(ledPins[index], OUTPUT);
    // ledPins[index] is replaced by the value in the array.
    // For example, ledPins[0] is 5
  }
}

void loop() {
  int index;
  int sensorValue;
  int numberOfLight;

  sensorValue = analogRead(sensorPin);

  // First, we need to convert the 0-1023 integer value into
  // a value that we can understand. 1023/5 = 205 so 0V-1V
  // correspond to a reading of 0-205, 1V-2V is 205-410, and
  // so on.
  if (sensorValue > 820) {
    numberOfLight = 5;
  } else if (sensorValue > 615) {
    numberOfLight = 4;
  } else if (sensorValue > 410) {
    numberOfLight = 3;
  } else if (sensorValue > 205) {
    numberOfLight = 2;
  } else {
    numberOfLight = 1;
  }

  // Turn only the defined number of light ON.
  // If numberOfLight is 1, the loop will only run through
  // once. If the numberOfLight is 3, the loop will run through
  // three times, turning led[0] to led[2] ON
  for(index = 0; index < numberOfLight; index++) {
    digitalWrite(ledPins[index], HIGH);
    delay(sensorValue);                
  }                                  

  // Same as above but light will be turned off instead.
  // Unlike previously, we'll start from the high index and
  // work the way down and turn OFF light that should not
  // be ON. Since index begin as 4, if numberOfLight is 5,
  // the loop will not execute. If numberOfLight is 4, the
  // loop will execute once.
  for(index = 4; index >= numberOfLight; index--) {
    digitalWrite(ledPins[index], LOW);
    delay(sensorValue);
  }
}
