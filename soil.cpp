// Include the necessary libraries
//#include <Arduino.h>

// Constants
const int soilSensorPin = A0; // Analog input pin for the soil sensor
const int ledPin = 9;         // Digital output pin for the LED
const int motorPin = 10;      // Digital output pin for the DC motor

// Variables
int sensorValue = 0;        // Variable to store the sensor reading
int thresholdValue = 500;   // Set your Adesired initial threshold value here (adjust based on your sensor)

void setup() {
  // Initialize serial communication (for debugging)
  Serial.begin(9600);

  // Set the LED pin and motor pin as OUTPUT
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Read the sensor value
  sensorValue = analogRead(soilSensorPin);

  // Print the sensor value to the serial monitor (optional)
  Serial.print("Soil Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the sensor value is below the threshold
  if (sensorValue < thresholdValue) {
    // If the soil is too dry (below threshold), turn on the LED and motor
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
  } else {
    // If the soil is moist enough (above threshold), turn off the LED and motor
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
  }

  // Increase the thresholdValue based on the sensorValue
  // This will make the LED and motor respond accordingly
  thresholdValue = map(sensorValue, 0, 1023, 0, 1023); // Adjust the mapping range as needed

  // Add a delay to avoid excessive readings
  delay(1000); // Adjust the delay time (in milliseconds) as needed
}
