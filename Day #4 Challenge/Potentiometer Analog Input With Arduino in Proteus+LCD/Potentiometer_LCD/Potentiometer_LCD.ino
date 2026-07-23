#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); //کد هگز برای پروتئوس قسمت 27 باید 20 شود و برای اجرا در اردوینو باید 27 باشد

int sensorValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);

  // راه‌اندازی LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Potentiometer");
}

void loop()
{
  // خواندن مقدار پتانسیومتر
  sensorValue = analogRead(A0);

  // نمایش مقدار روی LCD
  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(sensorValue);
  lcd.print("    ");   // پاک کردن ارقام قبلی

  // محاسبه و نمایش ولتاژ
  float voltage = sensorValue * (5.0 / 1023.0);

  lcd.setCursor(0, 2);
  lcd.print("Voltage: ");
  lcd.print(voltage, 2);
  lcd.print(" V   ");

  // روشن کردن LED
  digitalWrite(13, HIGH);

  // تاخیر بر اساس مقدار پتانسیومتر
  delay(sensorValue);

  // خاموش کردن LED
  digitalWrite(13, LOW);

  // تاخیر بر اساس مقدار پتانسیومتر
  delay(sensorValue);
}