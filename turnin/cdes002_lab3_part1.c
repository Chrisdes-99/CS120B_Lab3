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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;


	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	//unsigned char tmpC = 0x00;
	
	unsigned char count;

   
	
    /* Insert your solution below */
    while (1){

	tmpA = PINA;
	tmpB = PINB;
	count = 0x00;
	
	int i;

	for(i =0;i<8;i++){
	  if(tmpA >> i & 0x01){
	  ++count;
	}

	if(tmpB >> i & 0x01){
	 ++count;
	}
	}
	
	PORTC = count;
	}
    return 0;
}
