#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

#include "key.h"

#define SS_PIN 10
#define RST_PIN 9

// getLen - Get the amount of elements in an integer array
int getLen(int *arr[]) {
    int n = sizeof(*arr);
    return n / sizeof(int);
}

// Initialize the RFID scanner
MFRC522 rfid(
    SS_PIN,
    RST_PIN
);

void setup() {
    Serial.begin(9600); // Init the serial bus
    SPI.begin(); // Init the SPI bus
    rfid.PCD_Init(); // Init the rfid sensor
}

void loop() {
    // Call the readRFID() func if a RFID card within range of the sensor (20 mm)
    if (rfid.PICC_IsNewCardPresent()) {
        readRFID(); // Read the card
    }
    delay(100); // Read every 100ms
}

// readRFID - Read an RFID card
void readRFID() {
    rfid.PICC_ReadCardSerial(); // Read the card

    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak); // Get the picc type

    Serial.print(F("\nPICC type: ")); // Print the PICC type (prefix)
    Serial.println(rfid.PICC_GetTypeName(piccType)); // Print the actual PICC type (human-readable text)

    // Check if the PICC is a Classic MIFARE
    if (
        piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K
    ) {
        Serial.println(F("Non-MIFARE Classic tag detected")); // Tell the user that their tag is invalid (for this program)
        return;
    }
    
    // Loop through all of the keys
    int match = 0;
    for (int j = 0; j < getLen(validKeys) + 1; j++) {
        int tempUID[rfid.uid.size];
        // Loop through all of the bytes of the uid (the RFID scan)
        for (int i = 0; i < rfid.uid.size; i++) {
            Serial.println(rfid.uid.uidByte[i]);
            tempUID[i] = rfid.uid.uidByte[i]; // Set the value to a temporary int array for comparison later
        }

        // Compare the two integer (uid) arrays
        for (int k = 0; k < getLen(&validKeys[j]); k++) {
            if (validKeys[j][k] == tempUID[k]) {
                match++;
            }
        }
    }

    // See if there is a match
    if (match > 0) {
        Serial.println("Valid card detected!");
    }
    
    else {
        Serial.println("Invalid card detected!");
    }

    rfid.PICC_HaltA(); // Halt the RFID PICC
    rfid.PCD_StopCrypto1(); // Stop the PCD encryption

}