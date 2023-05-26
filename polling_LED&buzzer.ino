#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6
#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0
#define Button A5

const int row[] = {
ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};

const int col[] = {
COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};

byte smile[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,0,1,1,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,1,1,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}
};
byte cry[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,0,1,1,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,1,0,1,1,0,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}
};

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

byte previous=1,present=1,num=0;

void setup() {
  for (byte i = 0; i <= sizeof(row); i++) {pinMode(row[i], OUTPUT);}
  for (byte i = 0; i <= sizeof(col); i++) {pinMode(col[i], OUTPUT);}
  pinMode(Button, INPUT_PULLUP); 
  Serial.begin(9600);

}

void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], 1 - scan[i][j]);
      digitalWrite(col[j], 1 - matrix[i][j]);
      }
    for(byte j = 0; j < 8; j++){
    digitalWrite(row[j], HIGH);
    digitalWrite(col[j], LOW);
    }
  }
}

void loop() {
  present=digitalRead(Button);
  if(present == 1 && previous == 0){
    num++;
    if(num > 1){
      num = 0;  
    }
  }
  Serial.println(num);

  //可變電阻
  int resis = analogRead(2);
  Serial.println(resis);
  delay(1); 

 
  //蜂鳴器
  while(num==0 && present!=0) {
    for (int i = 0; i < 13; i++) {
      showPattern(smile);

      int duration = 900 / noteDurations1[i];
      tone(2, melody1[i], duration);

      for (int i=0;i<duration;i++) showPattern(smile);
      
      noTone(2);
      present=digitalRead(Button);if(present==0) break;
    }
    delay(500);
  }
  while(num==1 && present!=0) {
    for (int i = 0; i < 12; i++) {
      showPattern(cry); //LED

      int duration = 900 / noteDurations2[i];
      tone(2, melody2[i], duration);

      for (int i=0;i<duration;i++) showPattern(cry);

      noTone(2);
      present=digitalRead(Button);if(present==0) break;
    }
    delay(500);
  }
  previous=present;
}