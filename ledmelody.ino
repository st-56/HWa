
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988
#define NOTE_C6 1047


int melody[] = {
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_F5
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2
};

int ledPin[]={
  2,3,4,5,6,7,8,9
};

int tonePin=12;
int ledState;

void setup() {
for(int thisled=0;thisled<8;thisled++){
  pinMode(ledPin[thisled],OUTPUT);
}
}

void loop() {
  for(int thisNote=0;thisNote<sizeof(melody)/sizeof(melody[0]);thisNote++){
    int noteDuration=1000/noteDurations[thisNote];
    tone(tonePin,melody[thisNote],noteDuration);
if(melody[thisNote]== NOTE_C5){
digitalWrite(ledPin[0],HIGH);
ledState=ledPin[0];
}
else if(melody[thisNote]== NOTE_D5){
digitalWrite(ledPin[1],HIGH);
ledState=ledPin[1];
}
else if(melody[thisNote]== NOTE_E5){
digitalWrite(ledPin[2],HIGH);
ledState=ledPin[2];
}
else if(melody[thisNote]== NOTE_F5){
digitalWrite(ledPin[3],HIGH);
ledState=ledPin[3];
}
else if(melody[thisNote]== NOTE_G5){
digitalWrite(ledPin[4],HIGH);
ledState=ledPin[4];
}
else if(melody[thisNote]== NOTE_A5){
digitalWrite(ledPin[5],HIGH);
ledState=ledPin[5];
}
else if(melody[thisNote]== NOTE_B5){
digitalWrite(ledPin[6],HIGH);
ledState=ledPin[6];
}
else if(melody[thisNote]== NOTE_C6){
digitalWrite(ledPin[7],HIGH);
ledState=ledPin[7];
}
int pauseBetweenNotes=noteDuration*1.30;
delay(pauseBetweenNotes);

noTone(tonePin);
digitalWrite(ledState,LOW);
  }
  delay(200);
}

