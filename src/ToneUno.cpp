#include "Arduino.h"
#include "pitches.h"
#include "ToneUno.h"

int melody2[] = {
  NOTE_F4, NOTE_AS4, NOTE_C5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_F5,
  NOTE_AS5, NOTE_GS5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  4, 8, 8, 3, 8, 8, 8, 8, 8, 4, 4, 1
};

playUno::playUno(bool test){

}
void playUno::playMelody(){
    for (int thisNote = 0; thisNote < 12; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration2 = 1000 / noteDurations2[thisNote];
    #if !defined(__SAM3X8E__)
    tone(8, melody2[thisNote], noteDuration2);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration2 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    #endif
  }
}
