/*
  Mission Impossible tune for horn

 Plug the piezo buzzer on pin 8 

 Original code by Tom Igoe - http://www.arduino.cc/en/Tutorial/Tone

 */
#define NOTE_F  349
#define NOTE_G  415  //Actually G sharp
#define NOTE_A  466  //Actually A sharp
#define NOTE_Eb  311
#define NOTE_E  330 


// notes in the melody:
int melody[] = {
  NOTE_F, NOTE_F, NOTE_G, NOTE_A, NOTE_G, NOTE_F, NOTE_F, NOTE_Eb, NOTE_E
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 6, 8, 4, 4, 4, 6, 6
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 9; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(9);
  }
}

void loop() {
  // Press horn once to make the horn play the melody. The horn would be programmed on the bluetooth controller

