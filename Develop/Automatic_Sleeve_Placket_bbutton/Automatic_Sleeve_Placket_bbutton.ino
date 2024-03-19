#include <Servo.h>

int tombol = 12;
int inputPin = 13;
int inputSepatu = 11;
int amenu, menu, kondisi = 0;
Servo servoSepatu;


void setup() {
  servoSepatu.attach(10);
  servoSepatu.write(50);
  Serial.begin(115200);
  menu, amenu = 0;
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(inputSepatu, INPUT_PULLUP);
  pinMode(tombol, INPUT_PULLUP);
  Serial.println("Inisialisasi");
  for (int pin = 2; pin <= 9; pin++) {
    Serial.println(pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  Serial.println("Starting machine");
  // put your setup code here, to run once:

}

void loop() {
  if (menu <= 3) {
    if (digitalRead(tombol) == HIGH && kondisi == 1) {
      menu++;
      Serial.println("Tombol HIGH");
      if (menu > 2) {
        menu = 0;
        pneumatic();
      }
      kondisi = 0;
      pneumatic();
      delay(1000);
    }
    if (digitalRead(tombol) == LOW && kondisi == 0) {
      kondisi = 1;
    }
  }
  pneumatic();
}

void pneumatic() {
  switch (menu) {
    case 0:
      Serial.println("case 0");
      for (int pin = 2; pin <= 9; pin++) {
        digitalWrite(pin, HIGH);
      }
      amenu = 0;
      break;
    case 1:
      Serial.println("case 1");

      if (amenu == 0) {
        digitalWrite(6, LOW);
        delay(1000);
        digitalWrite(8, LOW);
        delay(800);
        amenu = 1;
      }
      for (int pin = 2; pin <= 5; pin++) {
        delay(100);
        digitalWrite(pin, LOW);
      }
      delay(200);
      digitalWrite(8, HIGH);
      //      menu=2;
      //      pneumatic();
      break;
    case 2:
      Serial.println("case 2");
      digitalWrite(7, LOW);
      digitalWrite(9, LOW);
      if (digitalRead(inputPin) == HIGH) {
        amenu = 0;
        Serial.println("inputPin High");
        //        delay(200);
        menu = 3;
        pneumatic();
      }
      break;
    case 3:
      Serial.println("case 3");
      for (int pin = 2; pin <= 5; pin++) {
        digitalWrite(pin, HIGH);
      }
      delay(500);
      digitalWrite(6, HIGH);
      if (digitalRead(inputSepatu) == HIGH && digitalRead(inputPin) == HIGH) {
        //        delay(2000);
        servoSepatu.write(165);
        menu = 4;
        pneumatic();
      }
      break;
    case 4:
      Serial.println("case 4");
      if (digitalRead(inputSepatu) == LOW && digitalRead(inputPin) == LOW) {
        //        delay(1000);
        servoSepatu.write(50);
        delay(500);
        digitalWrite(7, HIGH);
        digitalWrite(9, HIGH);
        menu = 0;
        pneumatic();
      }
      break;
    case 5:
      break;
  }
}
