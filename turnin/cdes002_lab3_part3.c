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
	//DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;


	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;


        // unable to bit manip through tmpC
        // due to the 1 in A6 being carried over to the other else if
	unsigned char top_Lev = 0x60;
	unsigned char next_Lev = 0x70;
	unsigned char next_Lev2 = 0x38;
        unsigned char next_Lev3 = 0x3C;
	unsigned char next_Lev4 = 0x3E;
	unsigned char high_Lev = 0x3F;

	unsigned char seatBelt = 0x80;
    /* Insert your solution below */
    while (1) {

	tempA = PINA;

	if(tempA == 0x01 || tempA == 0x02){
	  //tempC = (tempC & 0x9F) | 0x60;
	  tempC = top_Lev;
	}

	else if(tempA == 0x03 || tempA == 0x04){
	  //tempC = (tempC & 0x8F) | 0x70;
	  tempC = next_Lev;
	}

	else if(tempA == 0x05 || tempA == 0x06){
	 // tempC = (tempC & 0xC7) | 0x38;
	 tempC = next_Lev2;	

	}

	else if(tempA == 0x07 || tempA == 0x08 || tempA == 0x09){
	 // tempC = (tempC & 0xC3) | 0x3C; 
	 tempC = next_Lev3;
	}

	else if(tempA == 0x0A || tempA == 0x0B || tempA == 0x0C){
	 // tempC = (tempC & 0xC1) | 0x3E;
	 tempC = next_Lev4;
	}

	else if(tempA == 0x0D || tempA == 0x0E || tempA == 0x0F){
	 // tempC = (tempC & 0xC0) | 0x3F;
	 tempC = high_Lev;
	}
 
	if(tempA == 0x30){
	 tempC = seatBelt;
	} 	
 
	PORTC = tempC;
}
    return 0;
}
