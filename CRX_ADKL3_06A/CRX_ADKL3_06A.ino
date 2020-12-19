/*
  RGB LED
  Make an RGB LED display a rainbow of colours!
*/

// we'll define the pins by name to make the sketch easier to follow.
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

// a variable controls how fast we loop through the colours
int DISPLAY_TIME = 1000;  // In milliseconds

void setup() {

  //configure the Arduino pins we're using
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  
  // Off (all LEDs off):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(DISPLAY_TIME);

  // Red (turn just the red LED on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(DISPLAY_TIME);

  // Green (turn just the green LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(DISPLAY_TIME);

  // Blue (turn just the blue LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DISPLAY_TIME);

  // Yellow (turn red and green on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(DISPLAY_TIME);

  // Cyan (turn green and blue on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DISPLAY_TIME);

  // Purple (turn red and blue on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DISPLAY_TIME);

  // White (turn all the LEDs on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DISPLAY_TIME);
  
}
