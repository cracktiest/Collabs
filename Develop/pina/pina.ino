void setup() {
  // 22 1
  // 23 2
  // 24 3
  //25
  // 28 4
  // 26 5
  // 27 6
  // 29 7
  // put your setup code here, to run once:
  //22-29 map 1-8, but only used 1-7
  for (int pin = 22; pin <= 29; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  digitalWrite(28, LOW);
  delay(1000);
  digitalWrite(28, HIGH);
  delay(500);
  digitalWrite(26, LOW);
  for (int on = 22; on <= 25; on++) {
    digitalWrite(on, LOW);
    delay(170);
  }
  for (int on = 22; on <= 25; on++) {
    digitalWrite(on, HIGH);
    delay(50); 
  }
  digitalWrite(26, HIGH);
  delay(500);
  digitalWrite(27, LOW);
  delay(3000);
  digitalWrite(27, HIGH);
}

void loop() {

  // put your main code here, to run repeatedly:
}
