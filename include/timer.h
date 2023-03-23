#include <avr/interrupt.h>
#include <avr/io.h>

#ifndef __ASSIGNMENT_TIMER_H
#define __ASSIGNMENT_TIMER_H

#include "program.h"
#include "sequencer.h"
#include "spi.h"
#include "tca.h"
#include "uart.h"

void timer_init();

volatile uint8_t durationTick;
volatile uint8_t count;

#endif  // __ASSIGNMENT_TIMER_H