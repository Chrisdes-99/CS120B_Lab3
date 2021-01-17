/*	Author: cdes002
 *  Partner(s) Name: myself
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;


	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;


        // unable to bit manip through tmpC
        // due to the 1 in A6 being carried over to the other else if
	
    /* Insert your solution below */
    while (1){

	tmpA = PINA;
	
	// shifts PORTA 4 left times so that its lower nibble is mapped with PORTC's upper
	tmpC = (tmpA << 4) & 0xF0;
	//shifts PORTA 4 right times so that its upper maps to PORTC's lower
	tmpB = (tmpA >> 4) & 0x0F;

	PORTC = tmpC;
	PORTB = tmpB;
	
	}
    return 0;
}
