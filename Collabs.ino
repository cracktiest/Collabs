// inisialisasi pin, ditambahkan ketika ada pin input/output (IO) yang digunakan
int R1 = D13;
int R2 = D12;
int R3 = D11;
int inputPin = D4;
int menu, kondisi = 0;

void setup() {
  Serial.begin(115200);
  menu = 0;
  //pinMode untuk input (push button, sensor, dll)
  //INPUT_PULLUP digunakan untuk tombol, dan beberapa sensor analog
  pinMode(inputPin, INPUT_PULLUP);
  //pinMode untuk output (motor, relay, dll)
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);

  //relay harus keadaan high terlebih dahulu sebelum ke void loop
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  Serial.println("Starting");
}

void loop() {
  //ketika tombol/sensor terdeteksi maka menu akan bertambah 1, menggunakan fungsi button debounce
  if (digitalRead(inputPin) == LOW && kondisi == 1) {
    menu++;
    //berfungsi untuk membatasi menu sehingga menu akan kembali ke 0 
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
