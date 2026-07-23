// C++ code
//
int sensorValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  // Read the value from the sensor
  sensorValue = analogRead(A0);
  // Turn the LED on
  digitalWrite(13, HIGH);
  // Pause the program for <sensorValue> miliseconds
  delay(sensorValue); // Wait for sensorValue millisecond(s)
  // Turn the LED off
  digitalWrite(13, LOW);
  // Pause the program for <sensorValue> miliseconds
  delay(sensorValue); // Wait for sensorValue millisecond(s)
}