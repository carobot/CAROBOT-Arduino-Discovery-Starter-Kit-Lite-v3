/*
  SPINNING A MOTOR
  Use a transistor to spin a motor at different speeds.
*/

// This must be one of the PWM-capable pins.
const int motorPin = 9;

void setup()
{
  // Set up the motor pin to be an output:
  pinMode(motorPin, OUTPUT);

  // Set up the serial port:
  Serial.begin(9600);
}

void loop() {
  int speed;

  // This code will let you type a speed into the serial
  // monitor window. Open the serial monitor using the magnifying-
  // glass icon at the top right of the Arduino window. Then
  // type your desired speed into the small text entry bar at the
  // top of the window and click "Send" or press return. The motor
  // will then operate at that speed. The valid range is 0 to 255.
  
  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:

  while(true)  // "true" is always true, so this will loop forever.
  {
    // First we check to see if incoming data is available:
  
    while (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out any numbers:
      
      speed = Serial.parseInt();
  
      // Because analogWrite() only works with numbers from
      // 0 to 255, we'll be sure the input is in that range:
  
      speed = constrain(speed, 0, 255);
      
      // We'll print out a message to let you know that the
      // number was received:
      
      Serial.print("Setting speed to ");
      Serial.println(speed);
  
      // And finally, we'll set the speed of the motor!
      
      analogWrite(motorPin, speed);
    }
  }
}
