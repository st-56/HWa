/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988

#include "pitches.h"

int melody1[] = {
  NOTE_E5, NOTE_CS5, NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_E5
};

int melody2[] = {
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_F5
};

int noteDurations1[] = {
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4
};

int noteDurations2[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2
};

int num=0;
byte previous=1,present=1;

void setup() {
pinMode(9,INPUT_PULLUP);
}

void loop() {
  if(num==0)
  {
  for (int thisNote = 0; thisNote < 13; thisNote++) {
    int noteDuration = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    present=digitalRead(9);
    if(present==0&&previous==1)
    {
      num++;
      thisNote=13; 
    }
    previous=present;    
  }
  delay(200);
  }
  if(num==1)  
  for (int thisNote = 0; thisNote < 13; thisNote++) {
    int noteDuration = 1000 / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    present=digitalRead(9);
    if(present==0&&previous==1)
    {
      num--;
      thisNote=13; 
    }
    previous=present;    
  }
  delay(200);
}


