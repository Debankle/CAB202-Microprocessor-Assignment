#include "display.h"

extern uint8_t leftNum;
extern uint8_t rightNum;

// Return the binary output to write to spi based on the number and side to display on the QUTy
uint8_t create_display_bin(uint8_t digit, uint8_t side) {
    uint8_t display_bin;
    switch (digit) {
        case 0:
            display_bin = side | ZERO;
            break;
        case 1:
            display_bin = side | ONE;
            break;

        case 2:
            display_bin = side | TWO;
            break;

        case 3:
            display_bin = side | THREE;
            break;

        case 4:
            display_bin = side | FOUR;
            break;

        case 5:
            display_bin = side | FIVE;
            break;

        case 6:
            display_bin = side | SIX;
            break;

        case 7:
            display_bin = side | SEVEN;
            break;

        case 8:
            display_bin = side | EIGHT;
            break;

        case 9:
            display_bin = side | NINE;
            break;

        case 10:

            display_bin = side | A;
            break;

        case 11:
            display_bin = side | B;

            break;

        case 12:
            display_bin = side | C;

            break;

        case 13:
            display_bin = side | D;
            break;

        case 14:
            display_bin = side | E;
            break;

        case 15:
            display_bin = side | F;
            break;

        default:
            display_bin = side | CLEAR;
    }

    return display_bin;
}

// Clear the display and show nothing aka off
void clear_display() {
    leftNum = create_display_bin(16, LEFT);
    rightNum = create_display_bin(16, RIGHT);
}

// Set the left and right numbers of the display with the sequence index
void display_hex(uint8_t c) {
    leftNum = create_display_bin((c >> 4), LEFT);
    rightNum = create_display_bin((c & 0xf), RIGHT);
}