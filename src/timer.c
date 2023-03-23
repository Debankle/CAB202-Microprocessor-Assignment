#include "timer.h"

// Enable the 1.31ms timer for the program
void timer_init() {
    cli();
    TCB0.CTRLB = TCB_CNTMODE_INT_gc;  // Configure TCB0 in periodic interrupt mode
    TCB0.CCMP = 4369;                 // Set interval for 1.31ms (3333 clocks @ 3.3 MHz)
    TCB0.INTCTRL = TCB_CAPT_bm;       // CAPT interrupt enable
    TCB0.CTRLA = TCB_ENABLE_bm;       // Enable
    sei();
}

// increments needed for the timer
volatile int leftSide = 0;
extern uint8_t leftNum;
extern uint8_t rightNum;
volatile uint8_t durationTick = 0;
volatile uint8_t count = 0;

ISR(TCB0_INT_vect) {
    switch (state) {
        case SEQUENCING:
            if (count++ >= 10) {
                count = 0;
                // 13.1ms interval done
                if (durationTick++ >= current_step.duration) {
                    // one step is done, move onto the next
                    durationTick = 0;
                    step();
                }
            }
            break;
        
        // Switch between left and right to display two digits on the display with spi
        case SELECT_INIT:
            if (leftSide) {
                leftSide = 0;
                spi_write(rightNum);
            } else {
                leftSide = 1;
                spi_write(leftNum);
            }
            break;
        case SELECT:
            if (leftSide) {
                leftSide = 0;
                spi_write(rightNum);
            } else {
                leftSide = 1;
                spi_write(leftNum);
            }
            break;
        default:
            break;
    }

    TCB0.INTFLAGS = TCB_CAPT_bm;  // Acknowledge interrupt
}
