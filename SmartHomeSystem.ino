// Project: IoT Smart Home Automation System
// Description: A system to control home appliances and monitor temperature using IoT
// Author: [Your Name]

#include <LiquidCrystal.h>

// Define pins for sensors and actuators
const int tempSensorPin = A0; // LM35 Temperature Sensor
const int relayPin = 13;      // Relay module for Light Control
const int pirSensorPin = 2;   // PIR Motion Sensor

// Initialize variables
int tempValue = 0;
float voltage = 0;
float temperatureC = 0;
int motionState = 0;

void setup() {
  // Begin Serial Communication for IoT Monitoring
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(relayPin, OUTPUT);
  pinMode(pirSensorPin, INPUT);
  
  Serial.println("System Initializing...");
  delay(1000);
  Serial.println("Smart Home System Active.");
}

void loop() {
  // --- Task 1: Temperature Monitoring ---
  tempValue = analogRead(tempSensorPin);
  voltage = tempValue * (5.0 / 1023.0);
  temperatureC = voltage * 100; // Convert to Celsius

  Serial.print("Current Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // --- Task 2: Automatic Light Control (Motion Based) ---
  motionState = digitalRead(pirSensorPin);
  
  if (motionState == HIGH) {
    digitalWrite(relayPin, HIGH); // Turn ON Light
    Serial.println("Motion Detected: Light ON");
  } else {
    digitalWrite(relayPin, LOW);  // Turn OFF Light
    Serial.println("No Motion: Light OFF");
  }

  // Delay before next update
  delay(2000);
}