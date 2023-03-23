#include "spi.h"

// Initialise the spi
void spi_init() {
    cli();

    PORTMUX.SPIROUTEA = PORTMUX_SPI0_ALT1_gc;
    PORTC.DIR |= (PIN0_bm | PIN2_bm);
    PORTB.OUT |= PIN1_bm;
    PORTB.DIR |= PIN1_bm;
    PORTA.DIR |= PIN1_bm;

    SPI0.CTRLA = SPI_MASTER_bm | SPI_PRESC_DIV4_gc;
    SPI0.CTRLB = SPI_SSD_bm;
    SPI0.INTCTRL = SPI_IE_bm;

    SPI0.CTRLA |= SPI_ENABLE_bm;

    sei();
}

// Write bytes to the display through the spi to display values
void spi_write(uint8_t b) {
    SPI0.DATA = b;
}

// Open and close the SPI trap to update the display
ISR(SPI0_INT_vect) {
    PORTA.OUTCLR = PIN1_bm;
    PORTA.OUTSET = PIN1_bm;
    SPI0.INTFLAGS &= SPI_IE_bm;
}