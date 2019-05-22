#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
int incomingByte = 0;

void setup() {
    lcd.begin(16, 2);
    lcd.print("asdasd");
    Serial.begin(9600);
    // lcd.clear();
}

void loop() {
  if (Serial.available() > 0) {
        incomingByte = Serial.read();
        
        Serial.print("I received: ");
        Serial.println(incomingByte, DEC);
        lcd.print(incomingByte);
        delay(3000);
        lcd.clear();
    }

}
