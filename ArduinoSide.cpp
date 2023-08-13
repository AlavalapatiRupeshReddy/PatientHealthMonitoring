#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pulsePin = A0; // Pulse Sensor pin
int fadePin = 13;  // LED for heartbeat visualization
int fadeRate = 0;
boolean Pulse = false;
boolean QS = false;
int BPM;
unsigned long sampleCounter = 0;
unsigned long lastBeatTime = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(fadePin, OUTPUT);
  // Other setup configurations
}

void loop() {
  // Collect and process pulse data
  if (QS == true) {
    fadeRate = 255;
    QS = false;
  }
  ledFadeToBeat();
  delay(20);

  // Read temperature and update LCD
  float temp = readTemp();
  updateLCD(BPM, temp);

  // Send data to ESP32
  sendDataToESP32(BPM, temp);
}

void ledFadeToBeat() {
  // LED fading effect
}

float readTemp() {
  // Read temperature and return the value
}

void updateLCD(int bpm, float temp) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  lcd.print(bpm);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
}

void sendDataToESP32(int bpm, float temp) {
  // Send data to ESP32 via Serial communication
  Serial.print("BPM:");
  Serial.println(bpm);
  Serial.print("Temp:");
  Serial.println(temp);
  delay(1000); // Adjust delay based on ESP32 read rate
}
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pulsePin = A0; // Pulse Sensor pin
int fadePin = 13;  // LED for heartbeat visualization
int fadeRate = 0;
boolean Pulse = false;
boolean QS = false;
int BPM;
unsigned long sampleCounter = 0;
unsigned long lastBeatTime = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(fadePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Collect and process pulse data
  if (QS == true) {
    fadeRate = 255;
    QS = false;
  }
  ledFadeToBeat();
  delay(20);

  // Read temperature and update LCD
  float temp = readTemp();
  updateLCD(BPM, temp);

  // Send data to ESP32
  sendDataToESP32(BPM, temp);
}

void ledFadeToBeat() {
  // LED fading effect
  fadeRate -= 15;
  fadeRate = constrain(fadeRate, 0, 255);
  analogWrite(fadePin, fadeRate);
}

float readTemp() {
  int temp_val = analogRead(A1);
  float mv = (temp_val / 1024.0) * 5000;
  float cel = mv / 10;
  return (cel * 9) / 5 + 32;
}

void updateLCD(int bpm, float temp) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  lcd.print(bpm);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" F");
}

void sendDataToESP32(int bpm, float temp) {
  Serial.print("BPM:");
  Serial.println(bpm);
  Serial.print("Temp:");
  Serial.println(temp);
  delay(1000); // Adjust delay based on ESP32 read rate
}
