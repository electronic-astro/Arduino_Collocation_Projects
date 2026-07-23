// Define the analog pin connected to MQ-2
const int sensorPin = A0;

// Threshold value for gas detection (adjust based on testing)
const int threshold = 400;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Gas Detector Starting...");
  
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
  //Serial.print(sensorValue);
  
  // Check if gas concentration exceeds threshold
  if (sensorValue > threshold) {
    Serial.println("WARNING: High Gas Concentration Detected!");
  } else {
    Serial.println("Gas Levels Normal");
  }
  
  // Delay for readability
  delay(1000); // Wait 1 second before next reading
}