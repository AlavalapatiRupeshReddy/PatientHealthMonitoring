#include <LiquidCrystal.h>
#include <WiFi.h>
#include <HTTPClient.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float pulse = 0;
float temp = 0;
const char *ssid = "YourWiFiSSID";
const char *password = "YourWiFiPassword";
String apiKey = "OO707TGA1BLUNN12";

int pulsePin = A0;
int blinkPin = 7;
int fadePin = 13;
int fadeRate = 0;

volatile int BPM;
volatile int Signal;
volatile int IBI = 600;
volatile boolean Pulse = false;
volatile boolean QS = false;

static boolean serialVisual = true;
volatile int rate[10];
volatile unsigned long sampleCounter = 0;
volatile unsigned long lastBeatTime = 0;
volatile int P = 512;
volatile int T = 512;
volatile int thresh = 525;
volatile int amp = 100;
volatile boolean firstBeat = true;
volatile boolean secondBeat = false;

void setup()
{
  lcd.begin(16, 2);
  pinMode(blinkPin, OUTPUT);
  pinMode(fadePin, OUTPUT);
  Serial.begin(115200);
  interruptSetup();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Patient Health");
  lcd.setCursor(0, 1);
  lcd.print(" Monitoring ");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initializing....");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Getting Data....");
}

void loop()
{
  serialOutput();
  if (QS == true)
  {
    fadeRate = 255;
    serialOutputWhenBeatHappens();
    QS = false;
  }
  ledFadeToBeat();
  delay(20);
  read_temp();
  esp_32();
}

void ledFadeToBeat()
{
  fadeRate -= 15;
  fadeRate = constrain(fadeRate, 0, 255);
  analogWrite(fadePin, fadeRate);
}

void interruptSetup()
{
  // Initializes Timer2 to throw an interrupt every 2mS.
  TCCR2A = 0x02;
  TCCR2B = 0x06;
  OCR2A = 0X7C;
  TIMSK2 = 0x02;
  sei();
}

// Rest of the functions remain unchanged...

void esp_32()
{
  String url = "http://api.thingspeak.com/update";
  HTTPClient http;

  String payload = "api_key=" + apiKey +
                   "&field1=" + String(temp) +
                   "&field2=" + String(pulse);

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(payload);
  if (httpCode > 0)
  {
    String response = http.getString();
    Serial.println(response);
  }
  else
  {
    Serial.println("HTTP POST request failed");
  }

  http.end();
}

void read_temp()
{
  int temp_val = analogRead(A1);
  float mv = (temp_val / 1024.0) * 5000;
  float cel = mv / 10;
  temp = (cel * 9) / 5 + 32;
  Serial.print("Temperature:");
  Serial.println(temp);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BPM :");
  lcd.setCursor(7, 0);
  lcd.print(BPM);
  lcd.setCursor(0, 1);
  lcd.print("Temp.:");
  lcd.setCursor(7, 1);
  lcd.print(temp);
  lcd.setCursor(13, 1);
  lcd.print("F");
}

void serialOutput() { /* Rest of the function remains unchanged */ }

void serialOutputWhenBeatHappens() { /* Rest of the function remains unchanged */ }

void arduinoSerialMonitorVisual(char symbol, int data) { /* Rest of the function remains unchanged */ }

void sendDataToSerial(char symbol, int data) { /* Rest of the function remains unchanged */ }

ISR(TIMER2_COMPA_vect) { /* Rest of the function remains unchanged */ }
