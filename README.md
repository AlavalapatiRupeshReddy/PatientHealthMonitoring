# Heart Rate and Temperature Monitoring
This project demonstrates how to monitor heart rate and temperature using sensors and visualize the data in real-time using ThingSpeak. The project uses an Arduino and an ESP32 for data collection, transfer, and visualization.

# Components Used
Pulse Sensor
LM35 Temperature Sensor
LED with Resistor
16x2 LCD Display
Arduino Uno
ESP32 Development Board
# Project Overview
Pulse Sensor: Measures heart rate, connected to Arduino.
LM35 Sensor: Measures temperature, connected to Arduino.
LED: Visual indication based on heart rate, controlled by Arduino.
LCD Display: Shows heart rate and temperature, controlled by Arduino.
Arduino: Reads sensor data, calculates heart rate, sends data to ESP32.
ESP32: Receives data from Arduino, uploads data to ThingSpeak.
ThingSpeak: Online platform for real-time data visualization.
# Setup Steps
Arduino:
Connect Pulse Sensor and LM35 to Arduino.
Wire LED and LCD display as per the provided connections.
Upload Arduino code to read sensors and send data to ESP32.
ESP32:
Connect ESP32 to receive data from Arduino.
Upload ESP32 code to display data on LCD and upload to ThingSpeak.
ThingSpeak:
Create a ThingSpeak account and a new Channel.
Obtain API key and configure ESP32 code with it.
Set up ThingSpeak visualization for heart rate and temperature.
Usage
Power on the setup.
Arduino collects data, controls LED and LCD.
ESP32 receives data, displays on LCD, and uploads to ThingSpeak.
Monitor heart rate and temperature locally on LCD.
Access real-time charts on ThingSpeak.
 

