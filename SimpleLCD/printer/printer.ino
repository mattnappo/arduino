#include <LiquidCrystal.h>

// Initialize the LCD display
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup() {
  // Dimensions of the LCD display
  lcd.begin(16, 2);
    lcd.print("github.com/xoreo");
//    delay(3000);
    lcd.setCursor(0, 1);
    lcd.print("");
  //  return 0;
}

void loop() {
  // Print, starting at (0, 0)

  
  // Clear the display again
//  lcd.clear();


}
