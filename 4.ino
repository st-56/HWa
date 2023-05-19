// 需要包含以下程式庫
#include <Arduino.h>
void showPattern(byte matrix[8][8]);
// 定義任務執行的時間間隔（毫秒）
#define TASK1_INTERVAL 1000
#define TASK2_INTERVAL 500

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
#define Button 2

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
byte heart[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,0,0,1,1,0,0,1},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,0,0,1,1,1}
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

int num=0;

byte previous=1,present=1;

// 記錄任務執行的時間
unsigned long task1Time = 0;
unsigned long task2Time = 0;

// 定義任務1的函式
void task1()
{
  if(num==0)
  {
  for (int thisNote = 0; thisNote < 13; thisNote++) {
    int noteDuration = 1000 / noteDurations1[thisNote];
    tone(2, melody1[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(2);
    present=digitalRead(A5);
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
    tone(2, melody2[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(2);
    present=digitalRead(A5);
    if(present==0&&previous==1)
    {
      num--;
      thisNote=13; 
    }
    previous=present;    
  }
  delay(200);// 在這裡編寫任務1的程式碼
  Serial.println("Running Task 1");
}

// 定義任務2的函式
void task2()
{
  present=digitalRead(A5);
  if(present==0 && previous==1){
    num++;
    if(num>2){
    num=0; 
    }
    Serial.print(Button);
  }  
  if(num==1){
    showPattern(smile);
    }
  else if(num==0){
    showPattern(heart);    
  }
else if(num==2){
   showPattern(cry); 
}
delay(2);  
previous=present;
}
// 在這裡編寫任務2的程式碼


// 設定 Arduino 開始時的初始設定
void setup()
{
  // 初始化序列埠
  Serial.begin(9600);
  pinMode(A5,INPUT_PULLUP);
for (byte i = 0; i <= sizeof(row); i++) {
pinMode(row[i], OUTPUT);
}
for (byte i = 0; i <= sizeof(col); i++) {
pinMode(col[i], OUTPUT);
}
}

// 主迴圈
void loop()
{
  // 取得目前的時間
  unsigned long currentTime = millis();

  // 檢查任務1是否需要執行
  if (currentTime - task1Time >= TASK1_INTERVAL)
  {
    task1(); // 執行任務1
    task1Time = currentTime; // 更新任務1的執行時間
  }

  // 檢查任務2是否需要執行
  if (currentTime - task2Time >= TASK2_INTERVAL)
  {
    task2(); // 執行任務2
    task2Time = currentTime; // 更新任務2的執行時間
  }
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