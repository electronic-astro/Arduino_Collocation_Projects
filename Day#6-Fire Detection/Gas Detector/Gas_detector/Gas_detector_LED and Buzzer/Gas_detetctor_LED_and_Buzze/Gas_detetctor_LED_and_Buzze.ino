// Define pins
const int sensorPin = A0;  // MQ-2 analog output pin
const int ledPin = 13;     // LED pin (optional)
const int buzzerPin = 9;   // Buzzer pin (optional)
const int threshold = 300; // Adjust this threshold based on your calibration

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.println("Gas Detector Starting...");
  delay(20000); // Allow sensor to warm up for 20 seconds
}

void loop() {
  // Read the analog sensor value
  int sensorValue = analogRead(sensorPin);
  
  // Print the value to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  // Check if gas level exceeds threshold
  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);   // Turn on LED
    tone(buzzerPin, 1000);        // Activate buzzer at 1000 Hz
    Serial.println("Gas Detected!");
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED
    noTone(buzzerPin);            // Turn off buzzer
    Serial.println("No Gas Detected");
  }
  
  delay(1000); // Wait 1 second before next reading
}