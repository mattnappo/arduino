#ifndef KEY_H
#define KEY_H

// Make some other C file with an array of int arrays,
// each int array being one valid RFID card
extern "C" {
    // The uid of my white rfid key card
    int whiteKeycard[] = {
        177,
        197,
        57,
        49
    };

    // The uid of my blue rfid keychain
    int blueKeychain[] = {
        105,
        81,
        79,
        211
    };

    // An array of valid keys
    int *validKeys[] = {
        whiteKeycard,
        blueKeychain  
    };
}

#endif
