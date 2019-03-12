#include <LiquidCrystal.h>

// Initialize the LCD display
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2); // Dimensions of the LCD display
}

int show(char *s, int ms) {
  lcd.print(s);
  delay(ms);
  return 0;
}

void loop() {
  show("Hello, world!\0", 2000);
  
  lcd.clear();
}
