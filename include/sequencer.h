#ifndef __ASSIGNMENT_SEQUENCER_H
#define __ASSIGNMENT_SEQUENCER_H

#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdint.h>

#include "program.h"
#include "selector.h"
#include "spi.h"
#include "tca.h"
#include "timer.h"
#include "uart.h"

// Sequence array given to be used
extern char const SEQUENCE[];

// Encoding table used to decode the Base64 encoding
static const char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                      'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                      'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                      'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                      'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                      'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                      '4', '5', '6', '7', '8', '9', '+', '/'};

// Two steps used to manage the sequence, the one running, and the one being calculated
// during the previous step
sequence_command_t current_step;
sequence_command_t next_step;

// Variables used for decoding and descrambling
const uint32_t mask;
uint32_t state_lfsr;

volatile bool calculate_step;
uint16_t step_num;
uint8_t n;

// Functions for calculating the offset and each step of the sequence
void sequence();
void sequencing();
void paused();
void sync_state();
sequence_command_t calculate_next_step();
void step();

#endif  // __ASSIGNMENT_SEQUENCER_H