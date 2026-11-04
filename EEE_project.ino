#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PZEM004Tv30.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

PZEM004Tv30 pzem(Serial2, 16, 17);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Power Detector");

  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  delay(2000);
  lcd.clear();
}

void loop() {

  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();

  lcd.clear();

  if (isnan(voltage)) {
    lcd.setCursor(0, 0);
    lcd.print("PZEM Error");
    lcd.setCursor(0, 1);
    lcd.print("Check connection");
  } 
  else {
    lcd.setCursor(0, 0);
    lcd.print("V:");
    lcd.print(voltage, 1);
    lcd.print(" I:");
    lcd.print(current, 2);

    lcd.setCursor(0, 1);
    lcd.print("P:");
    lcd.print(power, 1);
    lcd.print(" W");
  }

  delay(2000);
}		