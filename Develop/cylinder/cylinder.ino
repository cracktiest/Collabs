void setup() {
  // put your setup code here, to run once:
  for(int a=50; a<=53; a++){
    pinMode(a, OUTPUT);
    digitalWrite(a, HIGH);
  }
  digitalWrite(52, LOW);
  delay(1000);
  digitalWrite(53,LOW);
  delay(1000);
  digitalWrite(53,HIGH);
  delay(200);
  digitalWrite(51, LOW);
  delay(200);
  digitalWrite(53,LOW);
  delay(1000);
  digitalWrite(53,HIGH);
  delay(1000);
  digitalWrite(52,HIGH);
//  digitalWrite(51,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
