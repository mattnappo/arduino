#ifndef PINS_H
#define PINS_H

// The valid pins
extern "C" {
    // Some random pin
    const char pin0[] = {
        0x31, // 1
        0x32, // 2
        0x41, // A
        0x42, // B
    };

    // Another random pin
    const char pin1[] = {
        'A',
        'D',
        '*',
        '#',
    };

    // An array of the valid pins
    const char *validPins[] = {
        pin0,
        pin1,
    };
}

#endif
