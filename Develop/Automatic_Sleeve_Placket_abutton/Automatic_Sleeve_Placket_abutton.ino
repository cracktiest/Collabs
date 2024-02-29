#include <Servo.h>
int R1 = 2;
int R2 = 3;
int R3 = 4;
int R4 = 5;
int R5 = 6;
int R6 = 7;
int R7 = 8;
int R8 = 9;
//int R9 = 10;
//int R10 = 11;
int tombol = 12;
int inputPin = 13;
int inputSepatu = 11;
int menu, kondisi = 0;
Servo servoSepatu;

void setup() {
  servoSepatu.attach(10);
  servoSepatu.write(50);
  Serial.begin(115200);
  menu = 0;
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(inputSepatu, INPUT_PULLUP);
  pinMode(tombol, INPUT_PULLUP);
  for (int pin = 2; pin <= 9; pin++) {
    Serial.println("initialisation");
    Serial.println(pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  //  pinMode(7, OUTPUT);
  //  digitalWrite(7, LOW);
  Serial.println("Starting");
}

void loop() {
  if(menu >= 0 && menu <=3){
  //debounce function
  if (digitalRead(tombol) == HIGH && kondisi == 1 && (menu == 0 || menu == 1 || menu == 2)) {
  menu++;
  Serial.println("tombol high");
    Serial.println(menu);
    if (menu > 5) {
      menu = 0;
    }
    kondisi = 0;
    pneumatic();
    delay(1000);
  }
  }
  if (digitalRead(tombol) == LOW && kondisi == 0) {
  kondisi = 1;
  Serial.println("tombol low");
  }
  if (digitalRead(inputPin) == HIGH && menu == 2) {
  Serial.println("inputPin");
    delay(1500);
    //    menu++;
    menu = 3;
    pneumatic();
    //    delay(500);
    //    menu = 0;
  }
//  if(digitalRead(inputSepatu)== HIGH){
//    Serial.println("Sepatu high");
//  }
//  if(digitalRead(inputSepatu)== LOW){
//    Serial.println("Sepatu low");
//  }
  //  if (digitalRead(inputSepatu) == HIGH && menu == 3) {
  //    Serial.println("input sepatu HIGH, servo turun");
  //    //    delay(2500);
  //    menu = 4;
  //    pneumatic();
  //  }
  //  if (digitalRead(inputSepatu) == LOW && menu == 4 && digitalRead(inputPin) == LOW) {
  //    Serial.println("input all low, servi naik");
  //    menu = 5;
  //    pneumatic();
  //  }
}

void pneumatic() {
  switch (menu) {
    case 0:
    Serial.println("Case 0");
      for (int pin = 2; pin <= 9; pin++) {
        digitalWrite(pin, HIGH);
      }
      //      if (digitalRead(inputSepatu) == HIGH) {
      //        delay(500);
      //        servoSepatu.write(50);
      //      }
      //      digitalWrite(7,LOW);
      break;
    case 1:
    Serial.println("Case 1");
      digitalWrite(6, LOW);
      break;
    case 2:
    Serial.println("Case 2");
      digitalWrite(8, LOW);
      delay(800);
      //      digitalWrite(7, LOW);
      for (int pin = 2; pin <= 5; pin++) {
        delay(250);
        digitalWrite(pin, LOW);
      }
      delay(1000);
      digitalWrite(8, HIGH);
      menu=3;
      pneumatic();
      break;
    case 3:
    Serial.println("Case 3");
      for (int pin = 2; pin <= 5; pin++) {
        digitalWrite(pin, HIGH);
      }
      delay(500);
      digitalWrite(6, HIGH);
      //            digitalWrite(7, LOW);
      menu = 4;
      pneumatic();
      break;
    case 4:
    Serial.println("Case 4");
      while (digitalRead(inputSepatu) == LOW && digitalRead(inputPin) == LOW) {
        delay(2000);
        //      if (digitalRead(inputSepatu) == HIGH) {
        servoSepatu.write(175);
        menu = 5;
        pneumatic();
      }
      break;
    case 5:
    Serial.println("Case 5");
      while (digitalRead(inputSepatu) == HIGH && digitalRead(inputPin) == HIGH) {
        delay(1000);
        //      if (digitalRead(inputPin) == LOW && digitalRead(inputSepatu) == LOW) {
        servoSepatu.write(50);
        menu = 0;
        pneumatic();
      }
      break;
  }
}

//servo 90-175
