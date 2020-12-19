/*
  Potentiometer
  Measure the position of a potentiometer and use it to
  control the blink rate of an LED. Turn the knob to make
  it blink faster or slower!
*/

int sensorPin = A0; // The potentiometer is connected to
                   // analog pin 0                      
int ledPin = 11;   // The LED is connected to digital pin 11

void setup() {
 
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  // The above line is the same as "pinMode(11, OUTPUT);"
}

void loop() {
  // declare an integer variable to store the value of
  // the potentiometer. The 
  int sensorValue;

  // analogRead() returns an integer number that ranges
  // from 0 (0 Volts) to 1023 (5 Volts)
  sensorValue = analogRead(sensorPin);    

  // blink the LED by using the sensorValue variable to
  // change the blink speed

  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(sensorValue);         // Pause for sensorValue
                              // milliseconds
  
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(sensorValue);         // Pause for sensorValue
                              // milliseconds
  
  // the loop() repeats forever
}
