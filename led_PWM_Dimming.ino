
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorRead=analogRead(A0);
  Serial.println(sensorRead);
  if (sensorRead<220)sensorRead=220;
  else if (sensorRead>740)sensorRead=740;
  int ledblink=map(sensorRead,220,740,0,255);
  analogWrite(9,sensorRead);
  delay(1);
}
