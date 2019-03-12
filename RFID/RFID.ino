#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

// Initialize the RFID scanner
MFRC522 rfid(
    SS_PIN,
    RST_PIN
);

// Initialize the RFID key
MFRC522::MIFARE_Key key;

int codeRead = 0;
String uidString;

void setup() {
    Serial.begin(9600); // Init the serial bus
    SPI.begin(); // Init the SPI bus
    rfid.PCD_Init(); // Init the rfid sensor
}

void loop() {
    // Call the readRFID() func if a RFID card within range of the sensor (20 mm)
    if (rfid.PICC_IsNewCardPresent()) {
        readRFID();
    }
    delay(100); // Read every 100ms
}

void readRFID() {
    rfid.PICC_ReadCardSerial(); // Read the card
    Serial.print(F("\nPICC type: ")); // Print the PICC type (prefix)

    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak); // Get the picc type
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

    // Start reading the uid
    Serial.println("Scanned PICC UID: "); // Print the uid (prefix)
    //    Serial.println(rfid.uid.uidByte); // Print the uid
    
    // printDec(rfid.uid.uidByte, rfid.uid.size);

    // Set the uid string
    // uidString = String(
    //     rfid.uid.uidByte[0] + " " +
    //     rfid.uid.uidByte[1] + " " +
    //     rfid.uid.uidByte[2] + " " +
    //     rfid.uid.uidByte[3] + " "
    // );

    uidString = String(
        rfid.uid.uidByte[0] +
        rfid.uid.uidByte[1] +
        rfid.uid.uidByte[2] +
        rfid.uid.uidByte[3]
    );

    // printUID(); // Print the uid
    
    Serial.println("uid str: " + uidString); // Print the uid

    // Loop through all of the bytes of the uid (the RFID scan)
    int i = 0;
    boolean match = true;

    while (i < rfid.uid.size) {
        Serial.println(rfid.uid.uidByte[i]);
        // If one of any of the uid bytes don't match the valid uid
        if (!(rfid.uid.uidByte[i] == validKey[i])) {
            Serial.println(rfid.uid.uidByte[i]);
            match = false;
        }
        i++;
    }

    if (match) {
        Serial.println("Valid card detected!");
    }
    
    else {
        Serial.println("Invalid card detected!");
    }

    // Halt the RFID PICC
    rfid.PICC_HaltA();

    // Stop the PCD encryption
    rfid.PCD_StopCrypto1();

}
