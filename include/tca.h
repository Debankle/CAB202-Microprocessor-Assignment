#include <avr/interrupt.h>
#include <avr/io.h>

#ifndef __ASSIGNMENT_TCA0_H
#define __ASSIGNMENT_TCA0_H

#include "program.h"

// Array of frequencies to calculate PER and CMP
uint32_t frequencies[12];

void tca_init();
void enable_tca();
void disable_tca();
void reset_tca();
void update_tca(sequence_command_t current_command);

#endif  // __ASSIGNMENT_TCA0_H