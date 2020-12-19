/*
  PHOTO RESISTOR
  Use a photoresistor (light sensor) to control the brightness
  of a LED.
*/

const int sensorPin = A0;
const int ledPin = 11;

int lightLevel;
// new global variables to remember the high and low light level
int high = 0, low = 1023;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  lightLevel = analogRead(sensorPin);

  // The light-sensing circuit we built actually doesn't have
  // a range all the way from 0 to 1023. It will likely be
  // 300 (dark) to 800 (light). As a result, we'll use two
  // variable to record our highest reading and a variable
  // to record our lowest reading and adjust our output
  // accordingly.

  // Using the high and low variable, the Arduino will keep
  // track of the highest and lowest values that we're reading
  // from analogRead().

  // We've initialized "low" to be 1023 so the Arduino will save
  // anything that's lower than that:
  if (lightLevel < low) {
    low = lightLevel;
  }

  // We also initialized "high" to be 0 so the Arduino will save
  // anything that's higher than that:
  if (lightLevel > high) {
    high = lightLevel;
  }

  // Once we have the highest and lowest values, we can stick them
  // directly into the map() function with a small offset to low
  // and high to ensure that the LED is fully-off and fully-on at
  // the limits

  lightLevel = map(lightLevel, low+30, high-30, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);

  analogWrite(ledPin, lightLevel);

}
