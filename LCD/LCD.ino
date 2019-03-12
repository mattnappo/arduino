#include <LiquidCrystal.h>

// Initialize the LCD display
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup() {
  // Dimensions of the LCD display
  lcd.begin(16, 2);
  //  return 0;
}

void loop() {
  // Print, starting at (0, 0)
  lcd.print("Hello, world!");
  delay(3000);

  // Move cursor
  // Column, row. Starts from 0.
  lcd.setCursor(4, 1);
  lcd.print("YAY!");
  delay(5000);

  // Clear the display
  lcd.clear();

  // Make the cursor a blinking cursor
  lcd.blink();
  delay(4000);

  // Set the cursor position (still blinking)
  lcd.setCursor(7, 1);
  delay(2000);

  // Turn blinking off
  lcd.noBlink();

  // Set a different type of cursor (underscore, ...)
  lcd.cursor();
  delay(5000);

  // Turn off the underscore cursor
  lcd.noCursor();

  // Clear the display again
  lcd.clear();


}
