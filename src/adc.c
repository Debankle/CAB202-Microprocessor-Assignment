#include "adc.h"

// Initialise the ADC to read from the potentiometer according to the specifications
void adc_init(void) {
    cli();
    ADC0.CTRLA = ADC_ENABLE_bm | ADC_LOWLAT_bm;
    ADC0.CTRLB = ADC_PRESC_DIV2_gc;
    ADC0.CTRLC = ADC_TIMEBASE0_bm | ADC_REFSEL_VDD_gc;
    ADC0.CTRLF = ADC_FREERUN_bm;
    ADC0.MUXPOS = ADC_MUXPOS_AIN2_gc;
    ADC0.COMMAND = ADC_MODE_SINGLE_8BIT_gc | ADC_START_IMMEDIATE_gc;
    sei();
}