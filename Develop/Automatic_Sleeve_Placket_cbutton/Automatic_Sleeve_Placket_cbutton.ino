#include <Servo.h>

int tombol = 12;
int inputPin = 13;
int inputSepatu = A1;  //dari 11
int inputJoin = A2;
int amenu, menu, kondisi = 0;
int hitung = 0;
int kondisi2 = 0;
Servo servoSepatu;
//Servo servoBig;


void setup() {
  Serial.begin(115200);
  Serial.println("Inisialisasi");
  servoSepatu.attach(10);
  //  servoSepatu.write(50);
  //  delay(5000);
  //  servoSepatu.write(165);
  //  delay(5000);
  servoSepatu.write(150);
  //  servoBig.attach(11, 500, 2400);
  //  servoBig.write(35); delay(3000);
  //  servoBig.write(10);
  menu, amenu = 0;
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(inputSepatu, INPUT_PULLUP);
  pinMode(inputJoin, INPUT_PULLUP);
  pinMode(tombol, INPUT_PULLUP);
  for (int pin = 22; pin <= 29; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  } for (int a = 50; a <= 53; a++) {
    pinMode(a, OUTPUT);
    digitalWrite(a, HIGH);
  }
  //  Serial.println("Starting machine");
  // put your setup code here, to run once:
}

void loop() {
  if (menu <= 3) {
    if (digitalRead(tombol) == HIGH && kondisi == 1) {
      menu++;
      Serial.println("Tombol HIGH");
      if (menu > 5) {  //interlock noise
        menu = 0;
        pneumatic();
      }
      kondisi = 0;
      kondisi2 = 0;
      pneumatic();
      delay(1000);
    }
    if (digitalRead(tombol) == LOW && kondisi == 0) {
      kondisi = 1;
    }
  }
  pneumatic();
}

//void pick(String

void pneumatic() {
  switch (menu) {
    case 0:
      hitung = 0;
      Serial.println("case 0");
      for (int pin = 22; pin <= 29; pin++) {
        digitalWrite(pin, HIGH);
      }
      amenu = 0;
      break;
    case 1:
      Serial.println("case 1");

      if (amenu == 0) {
        digitalWrite(29, LOW);
        delay(1000);
        digitalWrite(26, LOW);
        delay(800);
        amenu = 1;
        //        for (int pin = 22; pin <= 24; pin++) {
        //          digitalWrite(pin, LOW);
        //          delay(170);
        //        }
        //        digitalWrite(28, LOW);
        //        delay(170);
        //for
        digitalWrite(24, LOW);
        delay(200);
        digitalWrite(28, LOW);
        delay(200);
        digitalWrite(23, LOW);
        delay(200);
        digitalWrite(22, LOW);
        delay(200);
        delay(200);
        digitalWrite(26, HIGH);
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
      // digitalWrite(7, LOW);
      menu = 3;
      pneumatic();
      //      digitalWrite(9, LOW);
      break;

    //case untuk penambahan servo
    case 3: //cylinder program on
      Serial.println("case 3");
      digitalWrite(27, LOW);
      delay(1000);
      //      digitalWrite(52, LOW);
      //      delay(1000);
      //      digitalWrite(53, LOW);
      // digitalWrite(9, LOW);
      //      servoBig.write(45);//35
      if (digitalRead(inputPin) == HIGH) {
        amenu = 0;
        Serial.println("inputPin High");
        //        delay(200);
        menu = 4;
        pneumatic();
      }
      break;
    case 4: //cylinder program off
      Serial.println("case 4");
      // for (int pin = 2; pin <= 5; pin++) {
      //   digitalWrite(pin, HIGH);
      // }
      //lepas kain
      //      for (int on = 22; on <= 25; on++) {
      //        digitalWrite(on, HIGH);
      //        delay(50);
      //      }
      //for
      digitalWrite(24, HIGH);
      delay(50);
      digitalWrite(28, HIGH);
      delay(50);
      digitalWrite(22, HIGH);
      delay(50);
      digitalWrite(23, HIGH);
      delay(50);
      digitalWrite(29, HIGH);
      digitalWrite(26, HIGH);
      delay(500);
      //      digitalWrite(27, HIGH);
      //      if (digitalRead(inputSepatu) == HIGH && digitalRead(inputPin) == HIGH) {
      if (digitalRead(tombol) == HIGH && digitalRead(inputPin) == HIGH) {
        //        delay(2000);
        digitalWrite(53, HIGH);
        delay(200);
        digitalWrite(51, LOW);
        delay(200);
        digitalWrite(53, LOW);
        menu = 5;
        pneumatic();
      }
      break;
    case 5:
//      if (digitalRead(inputSepatu) == HIGH) {
//        Serial.println("Sepatu high");
//      }
//      Serial.println("case 5");
//      if (digitalRead(inputSepatu) == HIGH && kondisi2 == 0) {
//        hitung++;
//        Serial.println(kondisi2);
//        kondisi2 = 1;
//      }
//      else if (digitalRead(inputSepatu) == LOW) {
//        kondisi2 = 0;
//      }
      if (digitalRead(inputSepatu) == HIGH && digitalRead(inputPin) == HIGH ) {
        Serial.println("Servo Turun");
        servoSepatu.write(20);  //165
      }
      if (digitalRead(inputSepatu) == LOW && digitalRead(inputPin) == LOW) {
        Serial.println("CASE 5 urgent");
        //        delay(1000);
//        delay(800);
        digitalWrite(53, HIGH);
        delay(200);
        digitalWrite(51, HIGH);
        delay(200);
        digitalWrite(53, HIGH);
        servoSepatu.write(150);
        delay(100); //500
        digitalWrite(29, HIGH);
        digitalWrite(27, HIGH);
        //        servoBig.write(15);
        delay(500);
        // digitalWrite(7, HIGH);
        //        digitalWrite(9, HIGH);
        menu = 0;
        pneumatic();
      }
      break;
    case 6:
      break;
  }
}
