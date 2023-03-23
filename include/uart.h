#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

#ifndef __ASSIGNMENT_UART_H
#define __ASSIGNMENT_UART_H

#include "program.h"
#include "selector.h"

typedef enum {
    START_SERIAL,
    ESCAPE1,
    COMMAND,
    CMD_SEQIDX_1,
    CMD_SEQIDX_2
} serial_state_t;

serial_state_t serial_state;

void R_NACK();
void R_ACK();

void uart_init(void);
uint8_t uart_getc(void);
void uart_putc(uint8_t c);
void uart_puts(char* string);
void handle_serial();

#endif  // __ASSIGNMENT_UART_H