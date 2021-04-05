/*
 * Tools.h
 *
 * Created: 24-3-2021 09:36:48
 *  Author: Davy
 */ 

#ifndef TOOLS_H
#define TOOLS_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include <avr/io.h>

void wait_us(unsigned int us);
void wait_ms(unsigned int ms);
void configurePins();

#endif
