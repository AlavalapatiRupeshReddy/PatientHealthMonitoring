# Heart Rate and Temperature Monitoring
This project demonstrates how to monitor heart rate and temperature using sensors and visualize the data in real-time using ThingSpeak. The project uses an Arduino and an ESP32 for data collection, transfer, and visualization.

# Components Used
1)Pulse Sensor
2)LM35 Temperature Sensor
3)LED with Resistor
4)16x2 LCD Display
5)Arduino Uno
6)ESP32 Development Board
# Project Overview
1)Pulse Sensor: Measures heart rate, connected to Arduino.
2)LM35 Sensor: Measures temperature, connected to Arduino.
3)LED: Visual indication based on heart rate, controlled by Arduino.
4)LCD Display: Shows heart rate and temperature, controlled by Arduino.
5)Arduino: Reads sensor data, calculates heart rate, sends data to ESP32.
6)ESP32: Receives data from Arduino, uploads data to ThingSpeak.
6)ThingSpeak: Online platform for real-time data visualization.
# Setup Steps
Step-1-->Arduino:
Connect Pulse Sensor and LM35 to Arduino.
Wire LED and LCD display as per the provided connections.
Upload Arduino code to read sensors and send data to ESP32.
Step-2-->ESP32:
Connect ESP32 to receive data from Arduino.
Upload ESP32 code to display data on LCD and upload to ThingSpeak.
Step-3-->ThingSpeak:
Create a ThingSpeak account and a new Channel.
Obtain API key and configure ESP32 code with it.
Set up ThingSpeak visualization for heart rate and temperature.
 

