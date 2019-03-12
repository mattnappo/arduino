#include <Keypad.h>
#include <string.h>

#include "pins.h"

const byte ROWS     = 4; // Amount of rows on the keypad
const byte COLS     = 4; // Amount of columns on the keypad
const int  PIN_SIZE = 4;

// The actual keys on the keypad
const char keypadMap[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

// The pins for the rows (left 4 pins)
const byte rowPins[ROWS] = {
    0x09, 0x08, 0x07, 0x06
};

// The pins for the cols (right 4 pins)
const byte colPins[COLS] = {
    0x05, 0x04, 0x03, 0x02
};

// Initialize the keypad obj
Keypad keypad = Keypad(
    makeKeymap(keypadMap),
    rowPins,
    colPins,
    ROWS,
    COLS
);

// getLen - Get the amount of elements in a char array
int getLen(char *arr) {
    int n = sizeof(*arr);
    return n / sizeof(char);
}

void setup() {
    Serial.begin(9600); // Initialize the serial connection
}

int counter = 0;    // The temporary pin counter
char pin[PIN_SIZE]; // The temporary pin

void loop() {
    char readKey = keypad.getKey(); // Read a key

    if (readKey) { // If the key is not null
        if (counter == (PIN_SIZE - 1)) {
            checkPin(pin); // Check if the pin is valid
            
            // Reset the pin and counter
            free(pin);
            counter = 0;
        }
        else {
            // Increment the counter and set the temp pin accordingly
            pin[counter] = readKey;
            counter++;

            Serial.println(readKey);
        }
    }
}

// checkPin - Check if a pin is valid
void checkPin(char *pin) {
    int match = 0;

    // Loop through all of the valid pins
    for (int j = 0; j < getLen(*validPins) + 1; j++) {
        
        // Compare the two char arrays
        for (int k = 0; k < PIN_SIZE; k++) {
            Serial.print("         pin k: ");
            Serial.println(pin[k]);

            Serial.print("valid pins j k: ");
            Serial.println(validPins[j][k]);

            Serial.println("");

            if (validPins[j][k] == pin[k]) {
                match++;
            }
        }
    }

    // See if there is a match
    if (match == PIN_SIZE) {
        Serial.println("Valid card detected!");
    }
    
    else {
        Serial.println("Invalid card detected!");
    }
}
