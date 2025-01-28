#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup(){

    lcd.begin(20, 4); // initialize the lcd for 20 chars 4 lines and turn on backlight

    // NOTE: Cursor Position: (CHAR, LINE) start at 0
    lcd.setCursor(0, 0);
    lcd.print("Hello, world!");
    delay(1000);

}

void loop(){
    // Do nothing here...
}