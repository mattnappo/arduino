#include <Keypad.h>

const byte ROWS = 4; // Amount of rows on the keypad
const byte COLS = 4; // Amount of columns on the keypad

// The actual keys on the keypad
const keypadMap[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

// The pins for the rows (left 4 pins)
byte rowPins = {
    4, 5, 6, 7
};

// The pins for the cols (right 4 pins)
byte colPins = {
    0, 1, 2, 3
};

// Initialize the keypad obj
Keypad keypad = Keypad(
    makeKeymap(keypadMap),
    rowPins,
    colPins,
    ROWS,
    COLS,
);

void setup() {
    Serial.begin(9600); // Initialize the serial connection
}

void loop() {
    
}
