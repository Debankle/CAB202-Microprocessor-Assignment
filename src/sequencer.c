#include "sequencer.h"

const uint32_t mask = 0xb4bcd35c;
uint32_t state_lfsr = 0x11028891;

// Initialise all variables needed for the sequence to run
void sequence() {
    step_num = sequence_index * 32;
    calculate_step = false;
    sync_state();
    next_step = calculate_next_step();
    spi_write(create_display_bin(8, LEFT));
    durationTick = 0;
    count = 0;
    step();
}

// Sync the state_lfsr in case an offset greater than zero is being used
void sync_state() {
    state_lfsr = 0x11028891;
    for (uint16_t i = 0; i < ((step_num * 3) >> 2); i++) {
        uint8_t bit = (state_lfsr & 0x1);
        state_lfsr = state_lfsr >> 1;
        if (bit == 1) state_lfsr = (state_lfsr ^ mask);
    }
}

// Move onto the next step and update the tca to play the next step
void step() {
    current_step = next_step;
    if (current_step.duration == 0x00) {
        state = SELECT_INIT;
    } else {
        update_tca(current_step);
    }
    calculate_step = true;
}

sequence_command_t calculate_next_step() {
    // decode the next four bytes in the sequence
    char temp[4];
    temp[0] = pgm_read_byte(SEQUENCE + step_num++);
    temp[1] = pgm_read_byte(SEQUENCE + step_num++);
    temp[2] = pgm_read_byte(SEQUENCE + step_num++);
    temp[3] = pgm_read_byte(SEQUENCE + step_num++);

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 64; j++) {
            if (encoding_table[j] == temp[i]) {
                temp[i] = j & 0x3f;
                break;
            }
        }
    }

    // seperate the decoded bytes into three bytes
    char decoded_temp[3];
    decoded_temp[0] = (temp[0] << 2) + (temp[1] >> 4);
    decoded_temp[1] = ((temp[1] & 0xf) << 4) + (temp[2] >> 2);
    decoded_temp[2] = ((temp[2] & 0x3) << 6) + temp[3];

    // descramble the three bytes into the next step of the sequence
    char descrambled_temp[3];
    for (uint8_t i = 0; i < 3; i++) {
        descrambled_temp[i] = (state_lfsr & 0xff) ^ (decoded_temp[i]);
        uint8_t bit = (state_lfsr & 0x1);
        state_lfsr = state_lfsr >> 1;
        if (bit == 1) state_lfsr = (state_lfsr ^ mask);
    }

    // organise the descrambled bytes into useable data
    sequence_command_t next_command;
    next_command.duration = descrambled_temp[0];
    next_command.brightness = descrambled_temp[1];
    next_command.octave = descrambled_temp[2] >> 4;
    next_command.note = descrambled_temp[2] & 0x0f;

    return next_command;
}

// Handle the sequencing mode, with button checks and calculate the next step when needed
void sequencing() {
    if (calculate_step) {
        calculate_step = false;
        next_step = calculate_next_step();
    }

    uint8_t pb_state_r = pb_state;
    pb_state = VPORTA.IN;

    uint8_t pb_changed = pb_state ^ pb_state_r;
    uint8_t pb_falling = pb_changed & ~pb_state;

    if (pb_falling & PIN7_bm) {
        state = PAUSED;
    }

    if (current_step.duration == 0x00) {
        state = SELECT_INIT;
    }

    handle_serial();
}

// Handle the paused mode, with buttons to step forward or quit or resume
void paused() {
    if (calculate_step) {
        calculate_step = false;
        next_step = calculate_next_step();
    }

    uint8_t pb_state_r = pb_state;
    pb_state = VPORTA.IN;

    uint8_t pb_changed = pb_state ^ pb_state_r;
    uint8_t pb_falling = pb_changed & ~pb_state;

    if (pb_falling & PIN5_bm) {
        state = SELECT_INIT;
    }

    if (pb_falling & PIN6_bm) {
        step();
    }

    if (pb_falling & PIN7_bm) {
        state = SEQUENCING;
        step();
    }

    handle_serial();
}