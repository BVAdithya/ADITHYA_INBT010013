## READ ME


This repository contains three IoT projects . Each project demonstrates the integration of various sensors and microcontrollers to achieve specific monitoring and control objectives. Below are summaries of the three projects:

## 1. Arduino Smoke Sensor System
Objective: Detect smoke and alert via LED and buzzer.

## Description:
This project utilizes an Arduino board connected to a smoke sensor (MQ2), LED, and buzzer. The system reads the smoke sensor data and, if smoke is detected, it activates the LED and buzzer while printing "SMOKE DETECTED" to the console. If no smoke is detected, the LED and buzzer are turned off, and "SMOKE NOT DETECTED" is printed.

## Key Components:
Arduino Board
MQ2 Smoke Sensor
LED
Buzzer

## Key Functions:
Real-time smoke detection
Visual and auditory alerts

## 2. Automated Climate Control System with Manual Override
Objective: Monitor and control temperature and humidity automatically, with a manual override option via the Blynk app.

## Description:
This project uses an ESP32 microcontroller connected to a DHT22 sensor for temperature and humidity readings, a motor, and an LED. The system operates in two modes:

Automatic Mode: Activates the motor and LED based on temperature and humidity thresholds.
Manual Mode: Allows manual control of the motor and LED via the Blynk app.

## Key Components:
ESP32 Microcontroller
DHT22 Temperature and Humidity Sensor
Motor
LED
Blynk App for Manual Control

## Key Functions:
Automatic environmental control based on sensor data
Manual override via mobile app

## 3. IoT-Based Smart Environment Monitoring System
Objective: Monitor temperature, humidity, and light levels, and send alerts for critical conditions.

## Description:
This project involves an ESP8266 microcontroller connected to a DHT22 sensor and a photoresistor (LDR). Sensor data is uploaded to Thingspeak every 20 seconds and visualized in real-time. An IFTTT integration is set up to send email alerts if the temperature exceeds 65°C.

## Key Components:
ESP8266 Microcontroller
DHT22 Temperature and Humidity Sensor
Photoresistor (LDR)
Thingspeak for Data Visualization
IFTTT for Alert Notifications

## Key Functions:
Real-time environmental monitoring
Automated email alerts for critical conditions

These projects collectively demonstrate the application of IoT technologies for environmental monitoring and control, showcasing the capabilities of Arduino and ESP microcontrollers in creating smart, responsive systems.
