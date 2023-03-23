#ifndef __ASSIGNMENT_PROGRAM_H
#define __ASSIGNMENT_PROGRAM_H

// State machine typedef
typedef enum {
    START,
    SELECT_INIT,
    SELECT,
    SEQUENCE_INIT,
    SEQUENCING,
    PAUSED,
    TEST
} state_t;

// Typedef of each sequence structure for ease of use
typedef struct sequence_command {
    uint8_t duration : 8;
    uint8_t brightness : 8;
    uint8_t octave : 4;
    uint8_t note : 4;
} sequence_command_t;

// State object
volatile state_t state;

// Pushbutton state storage
uint8_t pb_state;

#endif  // __ASSIGNMENT_PROGRAM_H