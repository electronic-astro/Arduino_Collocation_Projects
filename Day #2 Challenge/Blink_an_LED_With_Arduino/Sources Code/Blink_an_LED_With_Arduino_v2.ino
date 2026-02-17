// C++ code
//
/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // helpful single-line comment here
  digitalWrite(13, HIGH);
  delay(200); // Wait for 1000 millisecond(s)
  // helpful single-line comment here
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  // helpful single-line comment here
  digitalWrite(12, HIGH);
  delay(50); // Wait for 1000 millisecond(s)
  // helpful single-line comment here
  digitalWrite(12, LOW);
  delay(50); // Wait for 1000 millisecond(s)
}