#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "YourWiFiSSID";
const char *password = "YourWiFiPassword";
const char *api_key = "YourThingSpeakAPIKey";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void loop() {
  // Listen for data from Arduino
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    int bpm = parseBPM(data);
    float temp = parseTemp(data);

    // Send data to ThingSpeak
    sendDataToThingSpeak(bpm, temp);
  }
}

int parseBPM(String data) {
  int index = data.indexOf("BPM:") + 4;
  String bpmStr = data.substring(index);
  return bpmStr.toInt();
}

float parseTemp(String data) {
  int index = data.indexOf("Temp:") + 5;
  String tempStr = data.substring(index);
  return tempStr.toFloat();
}

void sendDataToThingSpeak(int bpm, float temp) {
  HTTPClient http;
  String url = "http://api.thingspeak.com/update?api_key=";
  url += api_key;
  url += "&field1=" + String(bpm);
  url += "&field2=" + String(temp);

  http.begin(url);
  int httpCode = http.GET();
  http.end();

  Serial.println("Data sent to ThingSpeak");
  delay(15000); // Adjust delay based on ThingSpeak update rate
}
