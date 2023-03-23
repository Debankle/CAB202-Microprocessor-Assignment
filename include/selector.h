#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef __ASSIGNMENT_SELECT_H
#define __ASSIGNMENT_SELECT_H

#include "display.h"
#include "program.h"
#include "uart.h"

// Global sequence_index used to determine the offset for running the sequence
uint8_t sequence_index;

bool button1Down;

// main select function to handle selecting the sequence index, handled on a infinite loop
void select();

#endif  // __ASSIGNMENT_SELECT_H