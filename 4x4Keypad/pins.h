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

    // Another random pin
    const char pin2[] = {
        '1',
        '9',
        '4',
        '2',
    };

    // Another random pin
    const char pin3[] = {
        '5',
        '4',
        '5',
        '1',
    };

    // Another random pin
    const char pin4[] = {
        '1',
        '2',
        '3',
        '4',
    };

    const int VALID_PIN_COUNT = 5;

    // An array of the valid pins
    const char *validPins[] = {
        pin0,
        pin1,
        pin2,
        pin3,
        pin4,
    };
}

#endif