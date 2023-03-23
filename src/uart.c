#include "uart.h"

// Enable the uart
void uart_init(void) {
    cli();
    PORTB.DIRSET = PIN2_bm;                        // Enable PB2 as output (USART0 TXD)
    USART0.BAUD = 1389;                            // 9600 baud @ 3.3 MHz
    USART0.CTRLB = USART_RXEN_bm | USART_TXEN_bm;  // Enable Tx/Rx
    sei();

    serial_state = START;
}

uint8_t uart_getc(void) {
    while (!(USART0.STATUS & USART_RXCIF_bm))
        ;  // Wait for data
    return USART0.RXDATAL;
}

void uart_putc(uint8_t c) {
    while (!(USART0.STATUS & USART_DREIF_bm))
        ;  // Wait for TXDATA empty
    USART0.TXDATAL = c;
}

void uart_puts(char* string) {
    while (*string != '\0') {
        uart_putc(*string++);
    }
}

// Return R_NACK to an invalid serial command
void R_NACK() {
    uart_putc(0x23);
    uart_putc(0x4e);
    uart_putc(0x41);
    uart_putc(0x43);
    uart_putc(0x4b);
    uart_putc(0x0a);
}

// Return R_ACK to a valid serial command
void R_ACK() {
    uart_putc(0x23);
    uart_putc(0x41);
    uart_putc(0x43);
    uart_putc(0x4b);
    uart_putc(0x0a);
}

char temp;

char validValues[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

// Handle the serial with a seperate state machine
void handle_serial() {
    if (USART0.STATUS & USART_RXCIF_bm) {
        uint8_t c = USART0.RXDATAL;
        switch (serial_state) {
            case START_SERIAL:
                if (c == 0x5c) {
                    serial_state = ESCAPE1;
                }
                break;
            case ESCAPE1:
                if (c == 0x5c) {
                    serial_state = COMMAND;
                } else {
                    serial_state = START_SERIAL;
                }
                break;
            case COMMAND:
                if (c == 0x73) {
                    if (state == SELECT) {
                        state = SEQUENCE_INIT;
                        serial_state = START_SERIAL;
                        R_ACK();
                    } else {
                        R_NACK();
                    }
                } else if (c == 0x69) {
                    serial_state = CMD_SEQIDX_1;
                } else {
                    R_NACK();
                    serial_state = START_SERIAL;
                }
                break;

            case CMD_SEQIDX_1:
                temp = c;
                serial_state = CMD_SEQIDX_2;
                break;

            case CMD_SEQIDX_2:
                if (state == SELECT) {
                    uint8_t n;
                    bool valid = false;
                    for (uint8_t i = 0; i < 16; i++) {
                        if (temp == validValues[i]) {
                            valid = true;
                            n = 16 * i;
                            break;
                        }
                    }
                    if (!valid) {
                        R_NACK();
                        serial_state = START_SERIAL;
                    } else {
                        bool valid2 = false;
                        for (uint8_t i = 0; i < 16; i++) {
                            if (c == validValues[i]) {
                                valid2 = true;
                                n += i;
                                break;
                            }
                        }
                        if (!valid2) {
                            R_NACK();
                            serial_state = START_SERIAL;
                        } else {
                            R_ACK();
                            serial_state = START_SERIAL;
                            sequence_index = n;
                        }
                    }
                }

            default:
                break;
        }
    }
}