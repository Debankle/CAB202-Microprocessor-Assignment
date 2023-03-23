#include "tca.h"

// Enable the TCA with the display on 100% brightness and the buzzer off
void tca_init() {
    PORTB.DIRSET = PIN1_bm;
    PORTB.DIRSET = PIN0_bm;

    cli();
    TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1_gc;
    TCA0.SINGLE.CTRLB = TCA_SINGLE_WGMODE_SINGLESLOPE_gc | TCA_SINGLE_CMP1EN_bm | TCA_SINGLE_CMP0EN_bm;
    TCA0.SINGLE.PER = 30000;
    TCA0.SINGLE.CMP1 = 30000;
    TCA0.SINGLE.CMP0 = 0;
    TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
    TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm;
    sei();
}

// Acknowledge the TCA interrupt
ISR(TCA0_OVF_vect) {
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}

// Reset the tca to brightness 100% and buzzer off
void reset_tca() {
    cli();
    TCA0.SINGLE.PERBUF = 30000;
    TCA0.SINGLE.CMP0BUF = 0;
    TCA0.SINGLE.CMP1BUF = 30000;
    sei();
}

uint32_t frequencies[] = {
    121212,
    114409,
    107988,
    101927,
    96206,
    90806,
    85710,
    80899,
    76359,
    72073,
    68029,
    64209};

// Calculate the frequency for the TCA in the new step
void update_tca(sequence_command_t current_command) {
    cli();
    uint32_t frequency = frequencies[current_command.note] >> current_command.octave;
    TCA0.SINGLE.PERBUF = frequency;
    TCA0.SINGLE.CMP0BUF = frequency >> 1;
    TCA0.SINGLE.CMP1BUF = ((frequency * current_command.brightness) >> 8);
    sei();
}
