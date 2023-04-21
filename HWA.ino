byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 }, // = 0
{ 1,0,0,1,1,1,1 }, // = 1
{ 0,0,1,0,0,1,0 }, // = 2
{ 0,0,0,0,1,1,0 }, // = 3
{ 1,0,0,1,1,0,0 }, // = 4
{ 0,1,0,0,1,0,0 }, // = 5
{ 0,1,0,0,0,0,0 }, // = 6
{ 0,0,0,1,1,1,1 }, // = 7
{ 0,0,0,0,0,0,0 }, // = 8
{ 0,0,0,1,1,0,0 } // = 9
};
const int buttonPin = 10;
int buttonState = 0;
int num = 0;
void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
digitalWrite(9, 1); // 關閉小數點
pinMode(buttonPin,INPUT_PULLUP);
Serial.begin(19200);
}
void sevenSegWrite(byte digit) {
byte pin = 2;
for (byte seg = 0; seg < 7; ++seg) {
digitalWrite(pin,
seven_seg_digits[digit][seg]);
pin++;
}
}
void loop() {
buttonState = digitalRead(buttonPin);
if(buttonState == LOW){
num ++;
if(num > 9){
num = 0;
}
delay(1000);
}
sevenSegWrite(num);
Serial.println(num);
}