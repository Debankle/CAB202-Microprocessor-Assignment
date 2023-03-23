#include "adc.h"
#include "display.h"
#include "program.h"
#include "selector.h"
#include "sequence.h"
#include "sequencer.h"
#include "spi.h"
#include "tca.h"
#include "timer.h"
#include "uart.h"

int main(void) {

    // Initialise all processes
    adc_init();
    spi_init();
    tca_init();
    uart_init();
    timer_init();

    // Enable all four buttons to be used
    PORTA.PIN4CTRL = PORT_PULLUPEN_bm;
    PORTA.PIN5CTRL = PORT_PULLUPEN_bm;
    PORTA.PIN6CTRL = PORT_PULLUPEN_bm;
    PORTA.PIN7CTRL = PORT_PULLUPEN_bm;

    clear_display();

    state = START;

    // Handle the state machine in an infinite loop
    while (1) {
        switch (state) {
            case START:
                state = SELECT_INIT;
                break;

            case SELECT_INIT:
                // Disable the buzzer, set the brightness to max and reset the sequence index
                reset_tca();
                sequence_index = 0;
                display_hex(sequence_index);
                state = SELECT;
                break;

            case SELECT:
                select();
                break;

            case SEQUENCE_INIT:
                sequence();
                state = SEQUENCING;
                break;

            case SEQUENCING:
                sequencing();
                break;

            case PAUSED:
                paused();
                break;

            case TEST:
                break;
            default:
                break;
        }
    }

    return 0;
}