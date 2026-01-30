#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX

// pin modul motor drive
int IN1 = 7;
int IN2 = 8;
int IN3 = 4;
int IN4 = 2;
int ENA = 9;
int ENB = 6;

int led = 12; //lampu
int buz = 13; //klakson

// kecepatan putaran motor
int speedKiri = 255; 
int speedKanan = 255; 

void setup() {
  bluetooth.begin(9600); // fungsi bluetooth

  // inisialisasi pin
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);

  // panggil fungsi stop
  stopMotor();
}

void loop() {
  if (bluetooth.available()) {   // fungsi untuk mendeteksi data yang masuk
    char cmd = bluetooth.read();  // data karakter yang masuk di simpan ke type data bernama cmd

    switch(cmd) {

      case 'F': // maju
        maju(); // memanggil fungsi maju
        break;

      case 'B': // mundur
        mundur();  // memanggil fungsi mundur
        break;

      case 'L': // kiri
        kiri();  // memanggil fungsi kiri
        break;

      case 'R': // kanan
        kanan();  // memanggil fungsi kanan
        break;
    
      case 'X': // lampu menyala
        digitalWrite(led, HIGH);  // lampu menyala
        break;
      
      case 'x': // lampu mati
        digitalWrite(led, LOW);   // lampu mati
        break;

      case 'S': // berhenti
        stopMotor();  // memanggil fungsi motor berhenti
        break;
      
      case 'Y': // klakson
        digitalWrite(buz, HIGH);
        delay(200);
        digitalWrite(buz, LOW);
        delay(80);
        digitalWrite(buz, HIGH);
        delay(250);
        digitalWrite(buz, LOW);
        break;
    }
  }
}


void maju() {                   // fungsi maju
  analogWrite(ENA, speedKiri);
  analogWrite(ENB, speedKanan);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void mundur() {                 // fungsi mundur
  analogWrite(ENA, speedKiri);
  analogWrite(ENB, speedKanan);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void kiri() {                   // fungsi kiri
  analogWrite(ENA, speedKiri);
  analogWrite(ENB, speedKanan);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void kanan() {                  // fungsi kanan
  analogWrite(ENA, speedKiri);
  analogWrite(ENB, speedKanan);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotor() {              // fungsi motor berhenti
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}