/*	Author: cdes002
 *  Partner(s) Name: myself
 *	Lab Section:022
 *	Assignment: Lab #3  Exercise #5
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

    //makes it possible to get input and output 
    DDRB = 0x01; PORTB = 0x00;
    DDRD = 0x00; PORTD = 0xFF;

    unsigned char weight = 0x00;
    unsigned char airBag = 0x00;

    unsigned char tmpD = 0x00;
    unsigned char tmpB = 0x00;

    while(1){

        tmpB = PINB;
	tmpD = PIND;

	// this shifts D to the left clearing D0 then is filled by B0
	weight = (tmpD << 1) | (tmpB & 0x1);
	airBag = 0x00;

	//value set like this due to shifted bits
	if(weight >= 0x0046){
	   airBag = 0x20;
	}

	else if(weight > 0x05){

	   airBag = 0x40;
	}

	else{
	   airBag = 0x00;
	}
	PINB = airBag;
}
    return 0;
}
