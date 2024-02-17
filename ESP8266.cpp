#include <ESP8266WiFi.h>

// WiFi credentials
const char* ssid = "WIFI_SSID_(NAME)";
const char* password = "PASSWORD";

// Pin definitions for ultrasonic sensor
const int trigPin = 12; // GPIO 12 = D6
const int echoPin = 14; // GPIO 14 = D5

// Server configuration
const char* serverIP = "192.168.1.100"; // Adres IP of your pc
const int serverPort = 1234; // The port on which the Python server is listening.

// Minimum distance in centimetres to detect movement
const int detectionDistance = 50;

// Time between measurements
const int tick = 500;



WiFiClient client;

void setup() {
  Serial.begin(9600);
  
  // Initialize WiFi connection
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  WiFi.begin(ssid, password);

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  // Inform about successful WiFi connection
  Serial.println("Connected to WiFi");
}

void loop() {
  long duration, distance;
  
  // Trigger ultrasonic sensor to measure distance
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of ultrasonic pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = (duration / 2) / 29.1;
  
  // Check if motion is detected within specified distance
  if (distance < detectionDistance) {
    sendMovementData(); // If motion detected within detectionDistance cm, send data to server
  }
  
  delay(tick); // Wait before next measurement
}

// Function to send movement data to server
void sendMovementData() {
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Sending movement data...");
    client.print("Movement Detected");
    client.stop();
  } else {
    Serial.println("Failed to connect to server");
  }
}
