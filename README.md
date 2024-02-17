# Auto-Alt-Tab with ESP8266
[![python](https://img.shields.io/badge/Python-3.9-3776AB.svg?style=flat&logo=python&logoColor=white)](https://www.python.org) [![C++](https://img.shields.io/badge/C++-Compatible-blue?logo=c%2B%2B)](https://www.cplusplus.com/) ![ESP8266](https://img.shields.io/badge/ESP8266-Compatible-blue) 

A simple project for alt-tabbing when the sensor detects movement (e.g. opening a door ;) )

This project contains scripts for ESP8266 (using Arduino IDE) and Python, allowing for motion detection using an ultrasonic sensor and sending motion information via Wi-Fi to a computer.

## Features

- Motion detection using an ultrasonic sensor on the ESP8266 board.
- Sending motion data over Wi-Fi to a computer.
- Handling received data in Python script.

## Requirements

- ESP8266 board (e.g., NodeMCU)
- Ultrasonic sensor
- Computer with Python installed
- `pyautogui` library (install via `pip install pyautogui`)

## Instructions

1. **Connect the ultrasonic sensor to the ESP8266 board according to the image below.**

     ![scetch3231](https://github.com/kolinov2/Auto-Alt-Tab/assets/94188817/4b4277ef-358f-4299-9147-2c4cbe8aa97b)


2. Upload the script to the ESP8266 board using Arduino IDE.
3. Run the Python script on the computer, which will listen for data from the ESP8266.
4. When motion is detected, the ESP8266 will send information to the computer.
5. the Python script, upon receiving the information, executes alt+tab on the current window

## Configuration

### ESP8266

- Modify `ssid` and `password` in the Arduino script to the appropriate values for your Wi-Fi network.
- Adjust `serverIP` in the Arduino script to the IP address of your computer.
- Adjust `detectionDistance` in the Arduino script to your liking.
- Adjust `tick` in the Arduino script to your liking.
  
### Python

- Make sure the Python script is running on a computer on the local network.
- Don't forget to modify the `PORT` in the Python script if you're using a port other than 1234.

### Photos 

![IMG_2137](https://github.com/kolinov2/Auto-Alt-Tab/assets/94188817/b5507fb7-4871-4287-a662-e1b3ea3b9a15)

## Author

This project was created by kolino_v.

## Inspiration
I saw the video on instagram:
https://www.instagram.com/p/C199uQ4RNNo/
in which the author made the project too complicated by using 2 arduino and a separate program for keyboard shortcuts etc. and I thought I could do it better and cheaper :)

