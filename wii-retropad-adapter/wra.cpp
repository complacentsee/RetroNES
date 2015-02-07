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

#include <WProgram.h>
#include <avr/io.h>
#include "WMExtension.h"
#include "NESPad.h"


// Classic Controller Buttons
int bdl = 0; // D-Pad Left state
int bdr = 0; // D-Pad Right state
int bdu = 0; // D-Pad Up state
int bdd = 0; // D-Pad Down state
int ba = 0; // A button state
int bb = 0; // B button state
int bx = 0; // X button state
int by = 0; // Y button state
int bl = 0; // L button state
int br = 0; // R button state
int bm = 0; // MINUS button state
int bp = 0; // PLUS button state
int bhome = 0; // HOME button state
int bzl = 0; // ZL button state
int bzr = 0; // ZR button state
int lt = 0; // L analog value
int rt = 0; // R analog value

// Analog Buttons
byte lx = WMExtension::get_calibration_byte(2)>>2;
byte ly = WMExtension::get_calibration_byte(5)>>2;
byte rx = WMExtension::get_calibration_byte(8)>>3;
byte ry = WMExtension::get_calibration_byte(11)>>3;

// Analog stick neutral radius
#define ANALOG_NEUTRAL_RADIUS 10

// NES pad loop
void nes_loop() {
	int button_data;

	NESPad::init();

	for (;;) {


		button_data = NESPad::read();

		ba = button_data & (1 << 0);
		bb = button_data & (1 << 1);
		bm = button_data & (1 << 2);
		bp = button_data & (1 << 3);
		bdu = button_data & (1 << 4);
		bdd = button_data & (1 << 5);
		bdr = button_data & (1 << 7);
		bdl = button_data & (1 << 6);
		bhome = (bm && bp); // SELECT + START == HOME

		WMExtension::set_button_data(bdl, bdr, bdu, bdd, ba, bb, bx, by, bl, br,
				bm, bp, bhome, lx, ly, rx, ry, bzl, bzr, lt, rt);
	}
}

void setup() {
	// Prepare wiimote communications
	WMExtension::init();
}

void loop() {
		nes_loop();
}
