// inisialisasi pin, ditambahkan ketika ada pin input/output (IO) yang digunakan
int R1 = 2;
int R2 = 3;
int R3 = 4;
int R4 = 5;
int R5 = 6;
int R6 = 7;
int R7 = 8;
int R8 = 9;
int R9 = 10;
int R10 = 11;
int inputPin = 13;
int menu, kondisi = 0;

void setup() {
  Serial.begin(115200);
  menu = 0;
  //pinMode untuk input (push button, sensor, dll)
  //INPUT_PULLUP digunakan untuk tombol, dan beberapa sensor analog
  pinMode(inputPin, INPUT_PULLUP);
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  digitalWrite(6, HIGH);
  delay(4000);
  digitalWrite(7, LOW);
  delay(750);
  //pinMode untuk output (motor, relay, dll)
  for (int pin = 2; pin <= 5; pin++) {
    //    pinMode(pin, OUTPUT);
    delay(250);
    digitalWrite(pin, LOW);
    //    digitalWrite(pin, HIGH);
    Serial.println(pin);
  }
  delay(1000);
  digitalWrite(7, HIGH);
  //  for(int tes = 2; tes<=5; tes++){
  //    digitalWrite(tes, LOW);
  //  }
  //  delay(5000);
  //  for(int tes = 2; tes<=6; tes++){
  //    digitalWrite(tes, HIGH);
  //  }
  Serial.println("Starting");
}

void loop() {
  if (digitalRead(inputPin) == HIGH) {
    digitalWrite(6, LOW);
    delay(1000);
    for (int tes = 2; tes <= 5; tes++) {
      digitalWrite(tes, HIGH);
    }
  }
  //ketika tombol/sensor terdeteksi maka menu akan bertambah 1, menggunakan fungsi button debounce
  //  if (digitalRead(inputPin) == LOW && kondisi == 1) {
  //    menu++;
  //    //berfungsi untuk membatasi menu sehingga menu akan kembali ke 0
  //    if (menu >= 4) {
  //      menu = 0;
  //    }
  //    Serial.println(menu);
  //    Serial.println("HIGH");
  //    kondisi = 0;
  //    Serial.println("Delay");
  //    pneumatic();
  //    delay(1000);
  //  }
  //  if (digitalRead(inputPin) == HIGH && kondisi == 0) {
  //    Serial.println("LOW");
  //    kondisi = 1;
  //  }
}

void pneumatic() {
  //menu pada void loop akan dibaca sebagai switch case, sehingga ketika menu = 1 maka case = 1
  //pada bagian ini misal menu 1 menghidupkan relay 1, maka case 1 berisi digitalWrite(R1, LOW);
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
