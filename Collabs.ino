int R1 = D13;
int R2 = D12;
int R3 = D11;
int inputPin = D4;
int menu, kondisi = 0;

void setup() {
  Serial.begin(115200);
  menu = 0;
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  Serial.println("Starting");
}

void loop() {
  if (digitalRead(inputPin) == LOW && kondisi == 1) {
    menu++;
    if (menu >= 4) {
      menu = 0;
    }
    Serial.println(menu);
    Serial.println("HIGH");
    kondisi = 0;
    Serial.println("Delay");
    pneumatic();
    delay(1000);
  }
  if (digitalRead(inputPin) == HIGH && kondisi == 0) {
    Serial.println("LOW");
    kondisi = 1;
  }
}

void pneumatic(){
    switch (menu) {
      case 0:
        digitalWrite(R1, HIGH);
        digitalWrite(R2, HIGH);
        digitalWrite(R3, HIGH);
        break;
      case 1:
        digitalWrite(R1, LOW);
        break;
      case 2:
        digitalWrite(R1, HIGH);
        break;
      case 3:
        digitalWrite(R2, LOW);
        break;
    }
}
