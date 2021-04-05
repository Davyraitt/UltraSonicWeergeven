#define F_CPU 20e6

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Tools/Tools.h"
#include "Tools/LCD.h"

enum interrupt_status {INTERRUPT_FALLING, INTERRUPT_RISING};
enum display_status {CENTIMETER, MILLIMETER, INCHES, RICEGRAIN};
int displaycounter = 0;
int displaycounterMax = 3;
	
float distanceInCM = 0;
uint16_t distance = 0;
uint16_t timer_dist = 125; // time measured by timer;
	
static enum interrupt_status interrupt_state = INTERRUPT_RISING; // starting the interrupt status at rising
enum display_status display_state = CENTIMETER; // starting the display in CM


void sendUSPulse()
{
	PORTB = 0x00; // 10 us low pulse
	wait_us(10);
	PORTB = 0x01;
}

void setDisplayState()
{
	switch (displaycounter)
	{
		case 0:
		display_state = CENTIMETER;
		break;
		case 1:
		display_state = MILLIMETER;
		break;
		case 2:
		display_state = INCHES;
		break;
		case 3:
		display_state = RICEGRAIN;
		break;
	}
}

void writeDistanceToLEDS()
{
	if (distanceInCM <= 10){
		PORTA = 0b00000001;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	if (distanceInCM <= 20 && distanceInCM >= 10){
		PORTA = 0b00000011;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	if (distanceInCM <= 30 && distanceInCM >= 20){
		PORTA = 0b00000111;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	if (distanceInCM <= 40 && distanceInCM >= 30){
		PORTA = 0b00001111;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	if (distanceInCM <= 50 && distanceInCM >= 40){
		PORTA = 0b00011111;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	if (distanceInCM <= 60 && distanceInCM >= 50){
		PORTA = 0b00111111;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	if (distanceInCM <= 70 && distanceInCM >= 60){
		PORTA = 0b01111111;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
	
	
	if (distanceInCM >= 79){
		PORTA = 0b11111111;			// Write 10101010b PORTD
		wait_ms( 100 );
	}
}

void writeDistanceToLCD()
{
	char str[10];
	lcd_clear();
	wait_ms(200);
	
	
	if (display_state == CENTIMETER){
		int distanceincmint = (int)distanceInCM; // convert distance float to distance int
		sprintf(str, "%d", distanceincmint);  // converting the distance in cm integer to a string
		strcat(str, " CM"); // adding text after the string
		lcd_write_string(str);  // finally writing it...
	}
	
	if (display_state == MILLIMETER){
		int distanceInMM = (distance / 29.7); // Calculating to MM instead of CM
		int distanceInMMInt = (int)distanceInMM; // convert distance float to distance int
		sprintf(str, "%d", distanceInMMInt); // converting the distance in cm integer to a string
		strcat(str, " MM"); // adding text after the string
		lcd_write_string(str); // finally writing it...
	}
	
	if (display_state == INCHES){
		int distanceInInches = round(distanceInCM * 0.3937);
		int distanceInInchesInt = (int)distanceInInches; // convert distance float to distance int
		sprintf(str, "%d", distanceInInchesInt); // converting the distance in cm integer to a string
		strcat(str, " INCHES"); // adding text after the string
		lcd_write_string(str); // finally writing it...
	}
	
	if (display_state == RICEGRAIN){
		int distanceInGR = ((distance / 29.7) / 5); // Calculating to MM instead of CM, 1 grain of rice is 5mm so /5
		int distanceInGRInt = (int)distanceInGR; // convert distance float to distance int
		sprintf(str, "%d", distanceInGRInt); // converting the distance in cm integer to a string
		strcat(str, " Grains"); // adding text after the string
		lcd_write_string(str); // finally writing it...
	}
	
	wait_ms(5000);
}

ISR(INT0_vect) 
{
		// INTERRUPT OP PD0 AANGEROEPEN
		if (interrupt_state == INTERRUPT_RISING) // ALS DE INTERRUPT GEGENEREERD WERD DOOR EEN RISING EDGE
		{
		EICRA = 0x02; // DAN WILLEN WE NU DAT ER EEN INTERRUPT GEGENEREERD WORDT BIJ EEN FALLING EDGE (PD0)
		TCNT1 = 0x00; // RESET DE TIJD VAN TIMER1
		interrupt_state = INTERRUPT_FALLING; // INTERRUPT STATUS WORDT DUS FALLING, DOOR EICRA = 0x02; 
		} 
		
		
		else // ALS DE INTERRUPT NIET GEGENEREERD WERD DOOR EEN RISING, WAS HET WEL EEN FALLING EDGE (HET EINDE VAN DE ECHO DUS)
		{
		EICRA = 0x03; // NU WILLEN WE WEER DAT DE INTERRUPT GEGENEREERD WORDT BIJ EEN RISING EDGE (PD0)
		timer_dist = TCNT1; // TIJD INLEZEN NAAR VARIABEL timer_dist
		interrupt_state = INTERRUPT_RISING; // INTERRUPT STATUS WORDT DUS RISING, DOOR EICRA = 0x03; 
		}
}



int main( void )
{
	configurePins();
	
	EICRA = 0x03; // interrupt PORTD on pin 0, rising edge
	EIMSK |= 0x01; // enable interrupt on pin 0 (INT0) , When set to '1' then the External Interrupt feature is enabled.
	TCCR1A = 0b00000000; // initialize timer1, prescaler=256
	TCCR1B = 0b00001100; // CTC compare A, RUN
	//TCCR1A and TCCR1B are different registers, but they work on the same timer, timer1. 
	//They configure different behavior and are located in separate registers, simply because all the bits don't fit in a single byte.
	sei(); // sei sets the bit and switches interrupts on
	
	
	init_4bits_mode(); // LCD Init 4 bit mode
	lcd_write_string("Starting US....");
	wait_ms (3000);
	
	
	
	while (1)
	{
		sendUSPulse();
		distance = timer_dist * (340 / 2 );
		
		//my measurements: 18cm is 5400, 8 cm is 2380
		//which means 1cm is around 297, so we divide by it
		
		distanceInCM = round(distance / 297);
		if (distance > 0) {		
			writeDistanceToLCD();
			writeDistanceToLEDS();
		}
		
		if ( (PING & (1 << PING0)) == (1 << PING0) ) { // IF PING0 is pressed.
			// pin is high
			displaycounter = displaycounter + 1;
			if ( displaycounter > displaycounterMax ) {
				displaycounter = 0;
			}
			
			} else {
			// pin is low
		}
		setDisplayState();
		

	}
	
}
