//27 servo
//29 kiri
// 26 top

void setup() {
  // put your setup code here, to run once:

  for (int pin = 22; pin <= 29; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  digitalWrite(29,LOW);
  delay(500);
  digitalWrite(26,LOW);
  delay(500);
  // for(int on = 22; on <= 24; on++){
  //   digitalWrite(on,LOW);
  //   delay(200);

  // }
  digitalWrite(24,LOW);
  delay(200);
  digitalWrite(28,LOW);
  delay(200);
  digitalWrite(23,LOW);
  delay(200);
  digitalWrite(22,LOW);
  delay(200);
  delay(5000);
  digitalWrite(26,HIGH);
  delay(1000);
  digitalWrite(29,HIGH);
  delay(1000);
  digitalWrite(27,LOW);
  delay(3000);
  // for(int on = 22; on <= 24; on++){
  //   digitalWrite(on,HIGH);
  //   delay(50);
  // }
  // digitalWrite(23,LOW);
  // delay(50);
  // digitalWrite(24,LOW);
  // delay(50);
  // digitalWrite(22,LOW);
  // delay(50);
  // digitalWrite(23,LOW);
  // delay(50)
  digitalWrite(24,HIGH);
  delay(50);
  digitalWrite(28,HIGH);
  delay(50);
  digitalWrite(22,HIGH);
  delay(50);
  digitalWrite(23,HIGH);
  delay(50);
  delay(200);
  delay(3000);
  digitalWrite(27,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
