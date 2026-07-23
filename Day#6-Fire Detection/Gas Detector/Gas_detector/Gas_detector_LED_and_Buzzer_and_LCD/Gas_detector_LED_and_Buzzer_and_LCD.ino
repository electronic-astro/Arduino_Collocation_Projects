#include <Wire.h>              // Library for I2C communication @elec_astro
#include <LiquidCrystal_I2C.h> // Library for I2C LCD

// Define pins
const int sensorPin = A0;  // MQ-2 analog output pin
const int ledPin = 13;     // LED pin
const int buzzerPin = 9;   // Buzzer pin
const int threshold = 300; // Adjust this threshold based on calibration

// Initialize LCD (address 0x27 is common, but check yours with an I2C scanner if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication (optional, for debugging)
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight(); // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Gas Detector");
  lcd.setCursor(0, 1);
  lcd.print("Warming Up...");
  
  Serial.println("Gas Detector Starting...");
  delay(20000); // Allow sensor to warm up for 20 seconds
  
  lcd.clear(); // Clear the "Warming Up" message
}

void loop() {
  // Read the analog sensor value
  int sensorValue = analogRead(sensorPin);
  
  // Display on LCD
  lcd.setCursor(0, 0); // First line
  lcd.print("Value: ");
  lcd.print(sensorValue);
  lcd.print("    "); // Clear extra characters
  
  lcd.setCursor(0, 1); // Second line
  if (sensorValue > threshold) {
    lcd.print("Gas Detected!  ");
    digitalWrite(ledPin, HIGH);   // Turn on LED
    tone(buzzerPin, 1000);        // Activate buzzer
  } else {
    lcd.print("No Gas         ");
    digitalWrite(ledPin, LOW);    // Turn off LED
    noTone(buzzerPin);            // Turn off buzzer
  }
  
  // Optional: Print to Serial Monitor for debugging
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  delay(1000); // Update every 1 second
}