/*
  Buzzer
  Play a tune.
*/

int numOfNotes = 8; // keep track of the number of notes

// an array to store the melody
int melody[] = {262, 196, 196, 220, 196, 0, 247, 26};

// an array to store the duration of each note
// note durations: 4 = quarter note, 8 = eighth note, etc.
int durations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  // initialize the digital pin as an output.
  pinMode(11, OUTPUT); // LED
  pinMode(8, OUTPUT); // Buzzer
  pinMode(2, INPUT); // Button
}

void loop() {
  // play note when button's pressed
  if (digitalRead(2) == HIGH) {
    digitalWrite(11, HIGH);
    // loop over the notes of the melody:
    for (int i = 0; i < numOfNotes; i++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int duration = 1000 / durations[i];
      tone(8, melody[i], duration);
      
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pause = duration * 1.30;
      delay(pause);
      
      // stop the tone playing:
      noTone(8);
    }
  } else {
    digitalWrite(11, LOW);
  }
}
