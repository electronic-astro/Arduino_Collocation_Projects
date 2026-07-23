// Define the analog pin connected to MQ-2
const int sensorPin = A0;
// Define the LED pin
const int ledPin = 2; // Pin D2 for the LED

// Threshold value for gas detection (adjust based on testing)
const int threshold = 400;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Gas Detector Starting...");
  
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED initially off
  
  // Allow sensor to warm up (MQ-2 needs ~20-30 seconds)
  delay(20000); // 20 seconds warm-up time
  Serial.println("Sensor Ready!");
}

void loop() {
  // Read the analog value from the sensor
  int sensorValue = analogRead(sensorPin);
  
  // Print the sensor value to Serial Monitor
  Serial.print("Gas Sensor Value: ");
  Serial.println(sensorValue);
  
  // Check if gas concentration exceeds threshold
  if (sensorValue > threshold) {
    Serial.println("WARNING: High Gas Concentration Detected!");
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    Serial.println("Gas Levels Normal");
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
  
  // Delay for readability
  delay(1000); // Wait 1 second before next reading
}