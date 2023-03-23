#include "selector.h"

bool button1Down = false;

void select() {
    uint8_t pb_state_r = pb_state;
    pb_state = VPORTA.IN;

    uint8_t pb_changed = pb_state ^ pb_state_r;
    uint8_t pb_falling = pb_changed & ~pb_state;
    uint8_t pb_rising = pb_changed & pb_state;

    if (pb_falling & PIN4_bm) {
        button1Down = true;
    }

    if (pb_rising & PIN4_bm) {
        sequence_index = ADC0.RESULT0;
        button1Down = false;
    }

    if (pb_falling & PIN5_bm) {
        if (sequence_index > 0) sequence_index--;
    }

    if (pb_falling & PIN6_bm) {
        if (sequence_index < 255) sequence_index++;
    }

    if (pb_falling & PIN7_bm) {
        button1Down = false;
        state = SEQUENCE_INIT;
    }

    if (button1Down) {
        display_hex(ADC0.RESULT0);
    } else {
        display_hex(sequence_index);
    }

    handle_serial();
}