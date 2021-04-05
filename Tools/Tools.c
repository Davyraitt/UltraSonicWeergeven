/*
 * Tools.c
 *
 * Created: 24-3-2021 09:37:11
 *  Author: Davy
 */ 

#include "Tools.h"
#include <util/delay.h>

void wait_us(unsigned int us)
{
	for(int i = 0; i < us; i++)
	{
		_delay_us(1);
	}
}

void wait_ms(unsigned int ms)
{
	
	for(int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

void configurePins(){
	DDRA = 0b11111111;	// All pins PORTA are set to output (displaying us values)
	DDRB = 0xFF; //	Put DDRB on output. Trigger is in B0 in our case.
	DDRD = 0x00; //	port D pin 0 on input. 0 is echo and also interrupt
	DDRG &= ~(1 << PING0); // Setting PING0 bit in data direction, also called input
}

