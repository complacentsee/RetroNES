/*
* Wii RetroPad Adapter - Nintendo Wiimote adapter for retro-controllers!
* Copyright (c) 2011 Bruno Freitas - bootsector@ig.com.br
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "NESPad.h"
//#include "digitalWriteFast.h"
#include <avr/io.h>

void NESPad::init() {
/*
	pinModeFast(PD2, INPUT);
	pinModeFast(PD3, INPUT);
	pinModeFast(PD4, INPUT);
	pinModeFast(PD5, INPUT);
	pinModeFast(PD6, INPUT);
	pinModeFast(PD7, INPUT);
	pinModeFast(PB4, INPUT);
	pinModeFast(PB5, INPUT);
*/

	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);
	DDRD &= ~(1 << PD3);
	PORTD |= (1 << PD3);
	DDRD &= ~(1 << PD4);
	PORTD |= (1 << PD4);
	DDRD &= ~(1 << PD5);
	PORTD |= (1 << PD5);
	DDRD &= ~(1 << PD6);
	PORTD |= (1 << PD6);
	DDRD &= ~(1 << PD7);
	PORTD |= (1 << PD7);
	DDRB &= ~(1 << PB4);
	PORTB |= (1 << PB4);
	DDRB &= ~(1 << PB5);
	PORTB |= (1 << PB5);

}

int NESPad::read() {
	int state=0x0;

	if(!(PIND & (1 << PD2))){
		state = state + (1 << 7);
	}
	if(!(PIND & (1 << PD3))){
		state = state + (1 << 6);
	}
	if(!(PIND & (1 << PD4))){
		state = state + (1 << 5);
	}
	if(!(PIND & (1 << PD5))){
		state = state + (1 << 4);
	}
	if(!(PIND & (1 << PD6))){
		state = state + (1 << 3);
	}
	if(!(PIND & (1 << PD7))){
		state = state + (1 << 2);
	}
	if(!(PINB & (1 << PB4))){
		state = state + (1 << 1);
	}
	if(!(PINB & (1 << PB5))){
		state = state + 1;
	}
	return state;
}
