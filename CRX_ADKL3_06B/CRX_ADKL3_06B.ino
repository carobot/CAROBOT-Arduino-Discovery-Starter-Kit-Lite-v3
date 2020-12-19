/*
  RGB LED
  Make an RGB LED display a rainbow of colours!
*/

// we'll define the pins by name to make the sketch easier to follow.
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

int sensorPin = 0;

void setup() {

  //configure the Arduino pins we're using
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {

  int sensorValue;
  int colour;
  
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  sensorValue = analogRead(sensorPin);

  // Because sensorValue is an integer between 0 and 1023 but we
  // want a range from 0 to 767, we’ll have to convert the range.
  // To do so, we’ll multiply sensorValue by a factor of 767
  // then divide it by a factor of 1023. But since colour is a
  // variable of ‘int’ type, it can only hold a value between
  // -32,768 to 32,767 so we need force the calculation to take
  // place using variable type of ‘long’ (which can hold a value
  // between -2,147,483,648 to 2,147,483,647 then stored back
  // to a ‘int’ variable.

  colour = (int) (sensorValue * (long)767 / (long)1023);

  // Here we'll use an "if / else" statement to determine which
  // of the three (R,G,B) zones colour falls into. Each of these
  // zones spans 255 because analogWrite() wants a number from
  // 0 to 255.

  // In each of these zones, we'll calculate the brightness
  // for each of the red, green, and blue LEDs within the RGB LED.

  if (colour <= 255)          // zone 1
  {
    redIntensity = 255 - colour;    // red goes from on to off
    greenIntensity = colour;        // green goes from off to on
    blueIntensity = 0;             // blue is always off
  }
  else if (colour <= 511)     // zone 2
  {
    redIntensity = 0;                     // red is always off
    greenIntensity = 255 - (colour - 256); // green on to off
    blueIntensity = (colour - 256);        // blue off to on
  }
  else // colour >= 512       // zone 3
  {
    redIntensity = (colour - 512);         // red off to on
    greenIntensity = 0;                   // green is always off
    blueIntensity = 255 - (colour - 512);  // blue on to off
  }

  // Now that the brightness values have been set, command the LED
  // to those values

  analogWrite(RED_PIN, redIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
  analogWrite(GREEN_PIN, greenIntensity);  
}
