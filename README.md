
# Heart Rate and Temperature Monitoring**

This project demonstrates how to monitor heart rate and temperature using sensors and visualize the data in real-time using ThingSpeak. The project uses an Arduino and an ESP32 for data collection, transfer, and visualization.

# Components Used:

1. Pulse Sensor
2. LM35 Temperature Sensor
3. LED with Resistor
4. 16x2 LCD Display
5. Arduino Uno
6. ESP32 Development Board

# Project Overview:

1. Pulse Sensor: Measures heart rate, connected to Arduino.
2. LM35 Sensor: Measures temperature, connected to Arduino.
3. LED: Visual indication based on heart rate, controlled by Arduino.
4. LCD Display: Shows heart rate and temperature, controlled by Arduino.
5. Arduino: Reads sensor data, calculates heart rate, sends data to ESP32.
6. ESP32: Receives data from Arduino, uploads data to ThingSpeak.
7. ThingSpeak: Online platform for real-time data visualization.

# Setup Steps:

Step-1--> Arduino

1. Connect the Pulse Sensor and LM35 to the Arduino.
2. Wire the LED and the LCD display according to the provided connections.
3. Upload the Arduino code to read sensors, send data to ESP32, and display data on the LCD.

Step-2-->ESP32

1. Connect the ESP32 to receive data from the Arduino.
2. Upload the ESP32 code to visualize the collected data in ThingSpeak.

Step-3-->ThingSpeak

1. Create a ThingSpeak account and set up a new Channel.
2. Obtain the API key from ThingSpeak and configure the ESP32 code with it.
3. Set up ThingSpeak visualization to display heart rate and temperature data.

