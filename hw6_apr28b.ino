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

byte circle[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,0,1,1,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,1,1,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}
};
byte M[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,0}
};
byte H[8][8] = {
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0}
};


byte incomingbyte;

void setup() {
  Serial.begin(9600);
for (byte i = 0; i <= sizeof(row); i++) {
pinMode(row[i], OUTPUT);
}
for (byte i = 0; i <= sizeof(col); i++) {
pinMode(col[i], OUTPUT);
}
pinMode(2, INPUT_PULLUP);
}

void loop() {
  if(Serial.available()>0){
    incomingbyte=Serial.read();
  }


  if(incomingbyte=='c'){
    showPattern(circle);
  }
  else if(incomingbyte=='h'){
    showPattern(H);
  }
  else if(incomingbyte=='m'){
    showPattern(M);
  }
  delay(2);
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
