#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#ifndef __ASSIGNMENT_SPI_H
#define __ASSIGNMENT_SPI_H

void spi_init();
void spi_write(uint8_t b);

#endif  // __ASSIGNMENT_SPI_H