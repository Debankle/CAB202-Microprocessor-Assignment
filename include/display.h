#include <stdint.h>

#ifndef __ASSIGNMENT_DISPLAY_H
#define __ASSIGNMENT_DISPLAY_H

// Defined binary values for each hex representation
#define ZERO 0b0001000
#define ONE 0b1101011
#define TWO 0b1000100
#define THREE 0b1000001
#define FOUR 0b0100011
#define FIVE 0b0010001
#define SIX 0b0010000
#define SEVEN 0b1001011
#define EIGHT 0b0000000
#define NINE 0b0000001
#define A 0b0000010
#define B 0b0110000
#define C 0b0011100
#define D 0b1100000
#define E 0b0010100
#define F 0b0010110
#define CLEAR 0b1111111

// Left and right defines to specify the side of the display
#define LEFT (1 << 7)
#define RIGHT (0 << 7)

uint8_t leftNum;
uint8_t rightNum;

uint8_t create_display_bin(uint8_t digit, uint8_t side);
void clear_display();
void display_hex(uint8_t c);

#endif  // __ASSIGNMENT_DISPLAY_H