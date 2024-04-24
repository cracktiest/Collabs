#include <Servo.h>

int tombol = 12;
int inputPin = 13;
int inputSepatu = A1;//dari 11
int inputJoin = A2;
int amenu, menu, kondisi = 0;
Servo servoSepatu;
Servo servoBig;


void setup() {
  Serial.begin(115200);
  Serial.println("Inisialisasi");
  servoSepatu.attach(10);
  //  servoSepatu.write(50);
  //  delay(5000);
  //  servoSepatu.write(165);
  //  delay(5000);
  servoSepatu.write(50);
  servoBig.attach(11, 500, 2400);
  //  servoBig.write(35); delay(3000);
  servoBig.write(18);
  menu, amenu = 0;
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(inputSepatu, INPUT_PULLUP);
  pinMode(inputJoin, INPUT_PULLUP);
  pinMode(tombol, INPUT_PULLUP);
  for (int pin = 2; pin <= 8; pin++) {
    Serial.println(pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  Serial.println("Starting machine");
  // put your setup code here, to run once:

}

void loop() {
  if (menu <= 4) {
    if (digitalRead(tombol) == HIGH && kondisi == 1) {
      menu++;
      Serial.println("Tombol HIGH");
      if (menu > 4) { //interlock noise
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
      for (int pin = 2; pin <= 8; pin++) {
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
        for (int pin = 2; pin <= 5; pin++) {
          delay(100);
          digitalWrite(pin, LOW);
        }

        delay(200);
        digitalWrite(8, HIGH);
      }
      if (digitalRead(inputJoin) == LOW) {
        Serial.println("Input Join LOW");
        menu = 3;
        pneumatic();
      }
      //      menu=2;
      //      pneumatic();
      break;
    case 2:
      Serial.println("case 2");
      digitalWrite(7, LOW);
      //      menu = 3;
      //      pneumatic();
      //      digitalWrite(9, LOW);
      break;

    //case untuk penambahan servo
    case 3:
      Serial.println("case 3");
      servoBig.write(35);
      if (digitalRead(inputPin) == HIGH) {
        amenu = 0;
        Serial.println("inputPin High");
        //        delay(200);
        menu = 4;
        pneumatic();
      }
      break;
    case 4:
      Serial.println("case 4");
      for (int pin = 2; pin <= 5; pin++) {
        digitalWrite(pin, HIGH);
      }
      delay(500);
      digitalWrite(6, HIGH);
      if (digitalRead(inputSepatu) == HIGH && digitalRead(inputPin) == HIGH) {
        //        delay(2000);
        servoSepatu.write(163);//165
        menu = 5;
        pneumatic();
      }
      break;
    case 5:
      Serial.println("case 5");
      if (digitalRead(inputSepatu) == LOW && digitalRead(inputPin) == LOW) {
        //        delay(1000);
        servoSepatu.write(50);
        servoBig.write(18);
        delay(500);
        digitalWrite(7, HIGH);
        //        digitalWrite(9, HIGH);
        menu = 0;
        pneumatic();
      }
      break;
    case 6:
      break;
  }
}
