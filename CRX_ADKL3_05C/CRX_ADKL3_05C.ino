/*
  MULTIPLE LEDs: Dimming the LEDs!
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

  sensorValue = analogRead(sensorPin);

  // analogRead return a value ranging 0-1023 but the function
  // analogWrite, which simulate an analog output signal from
  // 0-5V using a technique called PWM only accept 0-255 as
  // an argument, we will use the "map" function to convert
  // 0-1023 to 0-255

  sensorValue = map(sensorValue, 0, 1023, 0, 255);

  for(index = 0; index < 5; index++) {
    analogWrite(ledPins[index], sensorValue);            
  }                                  

}
