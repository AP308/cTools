

#pragma once

#include "Drawing.h"
#include "Util.h"



long segData[95] = {
	//	0000		0000			00				000000			0000			0000			0000			0000
	//	^cross		^top/bottom dot ^horizBars (6)	^sidebarsR(4)	^sidebarsM(4)	^sidebarsL(4)	^topCircle(4)	^bottomCircle(4)
	// 128 asci codes, #32-126 are valid =
	// 95 symbols in total
	0x00000000,	// spc	0000 00 000000 0000 0000 0000 0000 0000
	0x0400c000,	// !	0000 01 000000 0000 1100 0000 0000 0000
	0x00008800,	// "	0000 00 000000 0000 1000 1000 0000 0000
	0x00f77000,	// #	0000 00 001111 0111 0111 00000000 0000	//~!
	0x0000f07d,	// $	0000 00 000000 0000 1111 0000 0111 1101
	0x30000028,	// %	0011 00 000000 0000 0000 0000 0010 1000	//~!
	0xc00000eb,	// &	1100 00 000000 0000 0000 0000 1110 1011	//~!
	0x00008000,	// '	0000 00 000000 0000 1000 0000 0000 0000
	0x00000621,	// (	0000 00 000000 0000 0000 0110 0010 0001
	0x00060048,	// )	0000 00 000000 0110 0000 0000 0100 1000
	0xf0c0f000,	// *	1111 00 001100 0000 1111 0000 0000 0000
	0x00c06000,	// +	0000 00 001100 0000 0110 0000 0000 0000
	0x00001000,	// ,	0000 00 000000 0000 0001 0000 0000 0000
	0x00c00000,	// -	0000 00 001100 0000 0000 0000 0000 0000
	0x04000000,	// .	0000 01 000000 0000 0000 0000 0000 0000
	0x30000000,	// /	0011 00 000000 0000 0000 0000 0000 0000
	0x00060669,	// 0	0000 00 000000 0110 0000 0110 0110 1001
	0x0130f000,	// 1	0000 00 010011 0000 1111 0000 0000 0000
	0x32300020,	// 2	0011 00 100011 0000 0000 0000 0010 0000
	0x015000cc,	// 3	0000 00 010101 0000 0000 0000 1100 1100
	0x00cf0c00,	// 4	0000 00 001100 1111 0000 1100 0000 0000
	0x03500c0c,	// 5	0000 00 110101 0000 0000 1100 0000 1100
	0x0000066f,	// 6	0011 00 000000 0000 0000 0110 0110 1111
	0x33000000,	// 7	0011 00 110000 0000 0000 0000 0000 0000
	0x000000ff,	// 8	0000 00 000000 0000 0000 0000 1111 1111
	0x000600f9,	// 9	0000 00 000000 0110 0000 0000 1111 1001
	0x0c000000,	// :	0000 11 000000 0000 0000 0000 0000 0000
	0x08001000,	// ;	0000 10 000000 0000 0001 0000 0000 0000
	0xa0000000,	// <	1010 00 000000 0000 0000 0000 0000 0000
	0x00f00000,	// =	0000 00 001111 0000 0000 0000 0000 0000
	0x50000000,	// >	0101 00 000000 0000 0000 0000 0000 0000
	0x040000e0,	// ?	0000 01 000000 0000 0000 0000 1110 0000	//~!
	0x0007046f,	// a	0000 00 000000 0111 0000 0100 0110 1111	//~!
	0x00c70760,	// A	0000 00 001100 0111 0000 0111 0110 0000
	0x01500fcc,	// B	0000 00 010101 0000 0000 1111 1100 1100
	0x02200621,	// C	0000 00 100010 0000 0000 0110 0010 0001
	0x01160f48,	// D	0000 00 010001 0110 0000 1111 0100 1000
	0x03f00f00,	// E	0000 00 111111 0000 0000 1111 0000 0000
	0x03c00f00,	// F	0000 00 111100 0000 0000 1111 0000 0000
	0x00820669,	// G	0000 00 001000 0010 0000 0110 0110 1001
	0x00cf0f00,	// H	0000 00 001100 1111 0000 1111 0000 0000
	0x0330f000,	// I	0000 00 110011 0000 1111 0000 0000 0000
	0x030e0009,	// J	0000 00 110000 1110 0000 0000 0000 1001
	0x00490f84,	// K	0000 00 000100 1001 0000 1111 1000 0100
	0x00300f00,	// L	0000 00 000011 0000 0000 1111 0000 0000
	0x600f0f00,	// M	0110 00 000000 1111 0000 1111 0000 0000
	0xc00f0f00,	// N	1100 00 000000 1111 0000 1111 0000 0000
	0x00060669,	// O	0000 00 000000 0110 0000 0110 0110 1001
	0x01400fc0,	// P	0000 00 010100 0000 0000 1111 1100 0000
	0x80060669,	// Q	1000 00 000000 0110 0000 0110 0110 1001
	0x81400fc0,	// R	1000 00 010100 0000 0000 1111 1100 0000
	0x0000007d,	// S	0000 00 000000 0000 0000 0000 0111 1101
	0x0300f000,	// T	0000 00 110000 0000 1111 0000 0000 0000
	0x000e0e09,	// U	0000 00 000000 1110 0000 1110 0000 1001
	0x30000f00,	// V	0011 00 000000 0000 0000 1111 0000 0000	//~!
	0x900f0f00,	// W	1001 00 000000 1111 0000 1111 0000 0000
	0xf0000000,	// X	1111 00 000000 0000 0000 0000 0000 0000
	0x60003000,	// Y	0110 00 000000 0000 0011 0000 0000 0000
	0x33300000,	// Z	0011 00 110011 0000 0000 0000 0000 0000
	0x01100f00,	// [	0000 00 010001 0000 0000 1111 0000 0000
	0xc0000000,	// \	1100 00 000000 0000 0000 0000 0000 0000
	0x022f0000,	// ]	0000 00 100010 1111 0000 0000 0000 0000
	0x00000060,	// ^	0000 00 000000 0000 0000 0000 0110 0000	//~!
	0x00300000,	// _	0000 00 000011 0000 0000 0000 0000 0000
	0x40000000,	// `	0100 00 000000 0000 0000 0000 0000 0000	//~!
	0x0003000f,	// a	0000 00 000000 0011 0000 0000 0000 1111
	0x00000f0f,	// b	0000 00 000000 0000 0000 1111 0000 1111
	0x00a00003,	// c	0000 00 001010 0000 0000 0000 0000 0011
	0x000f000f,	// d	0000 00 000000 1111 0000 0000 0000 1111
	0x00200007,	// e	0000 01 000010 0000 0000 0000 0000 0111
	0x00c0f040,	// f	0000 00 001100 0000 1111 0000 0100 0000
	0x000e00f9,	// g	0000 00 000000 1110 0000 0000 1111 1001
	0x00010f06,	// h	0000 00 000000 0001 0000 1111 0000 0110
	0x08003000,	// i	0000 10 000000 0000 0011 0000 0000 0000
	0x08003001,	// j	0000 10 000000 0000 0011 0000 0000 0001
	0xa0400f00,	// k	1010 00 000100 0000 0000 1111 0000 0000	//~!
	0x00100700,	// l	0000 00 000001 0000 0000 1111 0000 0000
	0x00c33300,	// m	0000 00 001100 0011 0011 0011 0000 0000	//~!
	0x00010306,	// n	0000 00 000000 0001 0000 0011 0000 0110
	0x0000000f,	// o	0000 00 000000 0000 0000 0000 0000 1111
	0x00000ff0,	// p	0000 00 000000 0000 0000 1111 1111 0000
	0x000f00f0,	// q	0000 00 000000 0000 1111 0000 1111 0000
	0x00000306,	// r	0000 00 000000 0000 0000 0011 0000 0110
	0x80a00000,	// s	1000 00 001010 0000 0000 0000 0000 0000	//~!
	0x00c0f000,	// t	0000 00 001100 0000 1111 0000 0000 0000
	0x00020209,	// u	0000 00 000000 0010 0000 0010 0000 1001
	0x10000300,	// v	0011 00 000000 0000 0000 0011 0000 0000	//~~!
	0x90030300,	// w	1001 00 000000 0011 0000 0011 0000 0000	//~!
	0xf0000000,	// x	1111 00 000000 0000 0000 0000 0000 0000	//!
	0x70000000,	// y	0111 00 000000 0000 0000 0000 0000 0000
	0x10500000,	// z	0001 00 000101 0000 0000 0000 0000 0000
	0x00400033,	// {	0000 00 000100 0000 0000 0000 0011 0011	//~!
	0x0000f000,	// |	0000 00 000000 0000 1111 0000 0000 0000
	0x008000cc,	// }	0000 00 001000 0000 0000 0000 1100 1100	//~!
	0x00060614	// ~	0000 00 000000 0110 0000 0110 0001 0100	//~!
};


void frame_DrawText(struct frameStruct* frame, int x1, int y1, char text[], int text_radius, int text_spacing, float text_thickness, short text_structure, int text_color) {

	if (!text_thickness) {
		return;
	};
	if (!text_radius) {
		return;
	};

	if (text_radius < 0) {
		text_radius = 10;
	};

	if (text_spacing < 0) {
		text_spacing = 5;
	};

	if (text_thickness < 0) {
		text_thickness = .3;
	};

	if (1.0 * text_thickness * text_radius < 1) {
		text_thickness = .2;
	};

	if (text_color < 0) {
		text_color = 0xffffff;
	};

	int iEnd = 0;
	for (int i = 0; i < string_maxLength; i++) {
		if (!text[i]) {
			iEnd = i;
			break;
		};
	};

	int charsPerLine = (int)(1.0 * (frame->width - x1) / (text_radius * 2 + text_spacing) + .5);

	if (text_structure == TEXT_CLIP) {
		iEnd = charsPerLine;
	};
	
	for (int i = 0; i < iEnd; i++) {

		int anchor1_x = x1 + (i % charsPerLine) * (text_radius * 2 + text_spacing);
		int anchor1_y = y1 - (i / charsPerLine) * (text_radius * 4 + text_spacing);

		int anchor2_x = anchor1_x + text_radius;
		int anchor2_y = anchor1_y + text_radius;
		int anchor3_y = anchor1_y + (text_radius * (3 - text_thickness));

		long segsWanted = segData[text[i] - 32];

		for (int x = anchor2_x - text_radius; x < anchor2_x + text_radius; x++) {

			if (x < 0 || x >= frame->width) {
				continue;
			};

			for (int y = anchor2_y - text_radius; y < anchor2_y + text_radius; y++) {

				if ((y < 0) || (y >= frame->height)) {
					continue;
				};

				short chunk = 0;

				if (x <= anchor2_x && y <= anchor2_y) {
					chunk = (1 << 0);
				};
				if (x <= anchor2_x && y > anchor2_y) {
					chunk = (1 << 1);
				};
				if (x > anchor2_x && y > anchor2_y) {
					chunk = (1 << 2);
				}
				if (x > anchor2_x && y <= anchor2_y) {
					chunk = (1 << 3);
				};

				if (!(chunk & segsWanted)) {	// check if currently drawing a wanted chunk
					continue;
				};
				
				// (y-h)^2 + (x-h)^2 = r^2
				if (sqrt((x - anchor2_x) * (x - anchor2_x) + (y - anchor2_y) * (y - anchor2_y)) > text_radius) {
					continue;
				};

				if (sqrt((x - anchor2_x) * (x - anchor2_x) + (y - anchor2_y) * (y - anchor2_y)) < ( text_radius - (text_thickness * text_radius) )) {
					continue;
				};

				frame->pixels[y * frame->width + x] = text_color;

			};

		};
		


		for (int x = anchor2_x - text_radius; x < anchor2_x + text_radius; x++) {

			if (x < 0 || x >= frame->width) {
				continue;
			};

			for (int y = anchor3_y - text_radius; y < anchor3_y + text_radius; y++) {

				if ((y < 0) || (y >= frame->height)) {
					continue;
				};

				short chunk = 0;

				if (x <= anchor2_x && y <= anchor3_y) {
					chunk = (1 << 0);
				};
				if (x <= anchor2_x && y > anchor3_y) {
					chunk = (1 << 1);
				};
				if (x > anchor2_x && y > anchor3_y) {
					chunk = (1 << 2);
				}
				if (x > anchor2_x && y <= anchor3_y) {
					chunk = (1 << 3);
				};

				if (!(segsWanted & (chunk << 4))) {	// check if currently drawing a wanted chunk
					continue;
				};

				// (y-h)^2 + (x-h)^2 = r^2
				if (sqrt((x - anchor2_x) * (x - anchor2_x) + (y - anchor3_y) * (y - anchor3_y)) > text_radius) {
					continue;
				};

				if (sqrt((x - anchor2_x) * (x - anchor2_x) + (y - anchor3_y) * (y - anchor3_y)) < (text_radius - (text_thickness * text_radius))) {
					continue;
				};

				frame->pixels[y * frame->width + x] = text_color;

			};

		};


		if (segsWanted & (1 << 8)) {	// l1
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y, anchor1_x + (text_radius * text_thickness), anchor1_y + text_radius, text_color, 0);
		};
		if (segsWanted & (1 << 9)) {	// l2
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y + text_radius, anchor1_x + (text_radius * text_thickness), anchor1_y + (text_radius * 2), text_color, 0);
		};
		if (segsWanted & (1 << 10)) {	// l3
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y + (text_radius * (2 - text_thickness)), anchor1_x + (text_radius * text_thickness), anchor1_y + (text_radius * (3 - text_thickness)) + 1, text_color, 0);
		};
		if (segsWanted & (1 << 11)) {	// l4
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y + (text_radius * (3 - text_thickness)), anchor1_x + (text_radius * text_thickness), anchor1_y + (text_radius * (4 - text_thickness)), text_color, 0);
		};
		
		if (segsWanted & (1 << 12)) {	// m1
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * (1 - (text_thickness / 2))), anchor1_y, anchor1_x + (text_radius * (1 + (text_thickness / 2))), anchor1_y + text_radius, text_color, 0);
		};
		if (segsWanted & (1 << 13)) {	// m2
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * (1 - (text_thickness / 2))), anchor1_y + text_radius, anchor1_x + (text_radius * (1 + (text_thickness / 2))), anchor1_y + (text_radius * 2), text_color, 0);
		};
		if (segsWanted & (1 << 14)) {	// m3
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * (1 - (text_thickness / 2))), anchor1_y + (text_radius * (2 - text_thickness)), anchor1_x + (text_radius * (1 + (text_thickness / 2))), anchor1_y + (text_radius * (3 - text_thickness)), text_color, 0);
		};
		if (segsWanted & (1 << 15)) {	// m4
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * (1 - (text_thickness / 2))), anchor1_y + (text_radius * (3 - text_thickness)), anchor1_x + (text_radius * (1 + (text_thickness / 2))), anchor1_y + (text_radius * (4 - text_thickness)), text_color, 0);
		};

		if (segsWanted & (1 << 16)) {	// r1
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * 2) - (text_radius * text_thickness), anchor1_y, anchor1_x + (text_radius * 2), anchor1_y + text_radius + 1, text_color, 0);
		};
		if (segsWanted & (1 << 17)) {	// r2
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * 2) - (text_radius * text_thickness), anchor1_y + text_radius, anchor1_x + (text_radius * 2), anchor1_y + (text_radius * 2), text_color, 0);
		};
		if (segsWanted & (1 << 18)) {	// r3
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * 2) - (text_radius * text_thickness), anchor1_y + (text_radius * (2 - text_thickness)), anchor1_x + (text_radius * 2), anchor1_y + (text_radius * (3 - text_thickness)) + 1, text_color, 0);
		};
		if (segsWanted & (1 << 19)) {	// r4
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * 2) - (text_radius * text_thickness), anchor1_y + (text_radius * (3 - text_thickness)), anchor1_x + (text_radius * 2), anchor1_y + (text_radius * (4 - text_thickness)), text_color, 0);
		};
		
		if (segsWanted & (1 << 20)) {	// hL1
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y, anchor1_x + text_radius + 1, anchor1_y + (text_radius * text_thickness), text_color, 0);
		};
		if (segsWanted & (1 << 21)) {	// hR1
			frame_DrawRectFilled(frame, anchor1_x + text_radius, anchor1_y, anchor1_x + (text_radius * 2), anchor1_y + (text_radius * text_thickness), text_color, 0);
		};

		if (segsWanted & (1 << 22)) {	// hL2
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y + (text_radius * (2 - text_thickness)), anchor1_x + text_radius + 1, anchor1_y + (text_radius * 2), text_color, 0);
		};
		if (segsWanted & (1 << 23)) {	// hR2
			frame_DrawRectFilled(frame, anchor1_x + text_radius, anchor1_y + (text_radius * (2 - text_thickness)), anchor1_x + (text_radius * 2), anchor1_y + (text_radius * 2), text_color, 0);
		};

		if (segsWanted & (1 << 24)) {	// hL3
			frame_DrawRectFilled(frame, anchor1_x, anchor1_y + (text_radius * (4 - (text_thickness * 2))), anchor1_x + text_radius + 1, anchor1_y + (text_radius * (4 - text_thickness)), text_color, 0);
		};
		if (segsWanted & (1 << 25)) {	// hR3
			frame_DrawRectFilled(frame, anchor1_x + text_radius, anchor1_y + (text_radius * (4 - (text_thickness * 2))), anchor1_x + (text_radius * 2), anchor1_y + (text_radius * (4 - text_thickness)), text_color, 0);
		};

		if (segsWanted & (1 << 26)) {	// bottomDot
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * (1 - (text_thickness / 2))), anchor1_y + (text_radius / 2), anchor1_x + (text_radius * (1 + (text_thickness / 2))), anchor1_y + text_radius, text_color, 0);
		};

		if (segsWanted & (1 << 27)) {	// topDot
			frame_DrawRectFilled(frame, anchor1_x + (text_radius * (1 - (text_thickness / 2))), anchor1_y + (text_radius * (3 - text_thickness)), anchor1_x + (text_radius * (1 + (text_thickness / 2))), anchor1_y + (text_radius * (4 - text_thickness)) - (text_radius / 2), text_color, 0);
		};



		for (int i = 1; i < text_radius * 2 - 1; i++) {

			short chunk = 
					(i < text_radius) * 0x1
				+	(i >= text_radius) * 0x2;

			float dY = (text_radius * (4 - text_thickness)) / (text_radius * 2);

			for (int iY = 0; iY < (int)(text_radius * text_thickness * 2); iY++) {

				if (!(segsWanted & (chunk << 28))) {
					break;
				};

				int x = anchor1_x + i;
				int y = (anchor1_y + (text_radius * text_thickness) + i * dY) - iY;

				if (x < 0) {
					continue;
				};
				if (x >= frame->width) {
					continue;
				};
				if (y < 0) {
					continue;
				};
				if (y >= frame->height) {
					continue;
				};
				
				frame->pixels[y * frame->width + x] = text_color;
			};
			
			chunk =
				(i < text_radius) * 0x4
				+ (i >= text_radius) * 0x8;

			for (int iY = 0; iY < (int)(text_radius * text_thickness * 2); iY++) {
				
				if (!(segsWanted & (chunk << 28))) {
					break;
				};

				int x = anchor1_x + i;
				int y = (anchor1_y + (text_radius * (4 - text_thickness)) - i * dY) - iY;

				if (x < 0) {
					continue;
				};
				if (x >= frame->width) {
					continue;
				};
				if (y < 0) {
					continue;
				};
				if (y >= frame->height) {
					continue;
				};

				frame->pixels[y * frame->width + x] = text_color;

			};

		};


	};


	return;
};


void frame_DrawLine(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	if ((deltaX == 0) && (deltaY == 0)) { //if given a point
		return;
	};

	double tIncrement = 1.0 / sqrt((deltaX * deltaX) + (deltaY * deltaY));

	//t goes from 0 - 1; 1 is endpoint
	for (double t = 0; t <= 1; t += tIncrement) {

		int x = (int)(x1 + deltaX * t);
		int y = (int)(y1 + deltaY * t);

		if ((x <= 0) || (x >= frame->width)) {
			continue;
		};

		if ((y <= 0) || (y >= frame->height)) {
			continue;
		};

		frame->pixels[y * frame->width + x] = color;

	};

	return;
}


// draw a line, but looped back if passes boundary
void frame_DrawLineModulus(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	if ((deltaX == 0) && (deltaY == 0)) { //if given a point
		return;
	};

	double tIncrement = 1.0 / sqrt((deltaX * deltaX) + (deltaY * deltaY));

	//t goes from 0 - 1; 1 is endpoint
	for (double t = 0; t <= 1; t += tIncrement) {

		int x = (int)(x1 + deltaX * t);
		int y = (int)(y1 + deltaY * t);

		if (x < 0) {
			x += frame->width;
		};

		if (y < 0) {
			y += frame->height;
		};

		frame->pixels[(y % frame->height) * frame->width + (x % frame->width)] = color;

	};

	return;
}


void frame_DrawLineA(struct frameStruct* frame, int x1, int y1, int dist, double angle, int color) {

	int deltaX = dist * cos(angle * 3.14 / 180);
	int deltaY = dist * sin(angle * 3.14 / 180);

	frame_DrawLine(frame, x1, y1, x1 + deltaX, y1 + deltaY, color);

	return;
}


void frame_DrawRect(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color) {

	frame_DrawLine(frame, x1, y1, x2, y1, color);
	frame_DrawLine(frame, x2, y1, x2, y2, color);
	frame_DrawLine(frame, x2, y2, x1, y2, color);
	frame_DrawLine(frame, x1, y1, x1, y2, color);

	return;
}


void frame_DrawRectFilled(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color, float transparency) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	if (x1 > x2) {
		int temp = x1;
		x1 = x2;
		x2 = temp;
	};

	if (y1 > y2) {
		int temp = y1;
		y1 = y2;
		y2 = temp;
	};

	for (int x = x1; x < x2; x++) {

		if (x < 0 || x >= frame->width) {
			continue;
		};

		for (int y = y1; y < y2; y++) {

			if (y < 0 || y >= frame->height) {
				continue;
			};

			frame->pixels[y * frame->width + x] = (RGB_BLEND(color, frame->pixels[y * frame->width + x], (int)((1 - transparency) * 100)));

		};

	};

	return;
};


void frame_DrawRectA(struct frameStruct* frame, int xAnchor, int yAnchor, int horizontalShift, int verticalShift, double angle, int width, int height, int color) {

	int x1 = xAnchor + horizontalShift * cos((angle - 90) * 3.14 / 180) + verticalShift * cos(angle * 3.14 / 180);
	int y1 = yAnchor + horizontalShift * sin((angle - 90) * 3.14 / 180) + verticalShift * sin(angle * 3.14 / 180);

	int x2 = x1 + height * cos(angle * 3.14 / 180);
	int y2 = y1 + height * sin(angle * 3.14 / 180);

	int x4 = x1 + width * cos((angle - 90) * 3.14 / 180);
	int y4 = y1 + width * sin((angle - 90) * 3.14 / 180);

	int x3 = x1 + height * cos(angle * 3.14 / 180) + width * cos((angle - 90) * 3.14 / 180);
	int y3 = y1 + height * sin(angle * 3.14 / 180) + width * sin((angle - 90) * 3.14 / 180);

	frame_DrawLine(&frame, x1, y1, x2, y2, color);
	frame_DrawLine(&frame, x2, y2, x3, y3, color);
	frame_DrawLine(&frame, x3, y3, x4, y4, color);
	frame_DrawLine(&frame, x4, y4, x1, y1, color);

	return;
};


void frame_DrawRectAFilled(struct frameStruct* frame, int xAnchor, int yAnchor, int horizontalShift, int verticalShift, int angle, int width, int height, int color) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	if (angle == 90) {
		frame_DrawRectFilled(frame, xAnchor + horizontalShift, yAnchor + verticalShift, xAnchor + width + horizontalShift, yAnchor + height + verticalShift, color, 0);
		return;
	};

	if (angle == 270) {
		frame_DrawRectFilled(frame, xAnchor - horizontalShift, yAnchor - verticalShift, xAnchor - width - horizontalShift, yAnchor - height - verticalShift, color, 0);
		return;
	};

	int x1 = xAnchor + horizontalShift * cos((angle - 90) * 3.14 / 180) + verticalShift * cos(angle * 3.14 / 180);
	int y1 = yAnchor + horizontalShift * sin((angle - 90) * 3.14 / 180) + verticalShift * sin(angle * 3.14 / 180);

	int x3 = x1 + height * cos(angle * 3.14 / 180) + width * cos((angle - 90) * 3.14 / 180);
	int y3 = y1 + height * sin(angle * 3.14 / 180) + width * sin((angle - 90) * 3.14 / 180);

	int angle1 = NormalizeAngle(angle);
	int angle2 = NormalizeAngle(angle - 90);

	int angle3 = NormalizeAngle(angle + 180);
	int angle4 = NormalizeAngle(angle + 90);

	int longestSide = height;
	if (width > height) {
		longestSide = width;
	};

	for (int x = x1 - longestSide * 1.5; x < x1 + longestSide * 1.5; x++) {

		if (x < 0 || x >= frame->width) {
			continue;
		};

		for (int y = y1 - longestSide * 1.5; y < y1 + longestSide * 1.5; y++) {

			if (y < 0 || y >= frame->height) {
				continue;
			};

			int fill = 1;
			int pointAngle = NormalizeAngle(DeltasToDegrees(x - x1, y - y1));

			if (pointAngle < angle1 != pointAngle < angle2) {
				fill = -1;
			};

			if (NormalizeAngle(angle) >= 90) {
				fill *= -1;
			};

			if (fill == -1) {
				continue;
			};

			fill = 1;
			pointAngle = NormalizeAngle(DeltasToDegrees(x - x3, y - y3));

			if (pointAngle <= angle3 == pointAngle <= angle4) {
				fill = -1;
			};

			if (NormalizeAngle(angle3) < 90) {
				fill *= -1;
			};

			if (fill == -1) {
				continue;
			};

			frame->pixels[y * frame->width + x] = color;

		};

	};

	return;
};


void frame_DrawCircleFilled(struct frameStruct* frame, int x1, int y1, int radius, int color) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	for (int x = x1 - radius; x < x1 + radius; x++) {

		if (x < 0 || x >= frame->width) {
			continue;
		};

		for (int y = y1 - radius; y < y1 + radius; y++) {

			if ((y < 0) || (y >= frame->height)) {
				continue;
			};

			// (y-h)^2 + (x-h)^2 = r^2
			if (sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) > radius) {
				continue;
			};

			frame->pixels[y * frame->width + x] = color;

		};

	};

	return;
}


void frame_DrawSemiCircleFilled(struct frameStruct* frame, int x1, int y1, int radius, int sliceAngle, int angle, int color, float transparency) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	sliceAngle /= 2;
	int angle1 = angle - sliceAngle;
	int angle2 = angle + sliceAngle;

	angle1 = NormalizeAngle(angle1);
	angle2 = NormalizeAngle(angle2);

	int flip = 0;
	if (angle2 < sliceAngle * 2) {
		flip = 1;
	};

	for (int x = x1 - radius; x < x1 + radius; x++) {

		if (x < 0 || x >= frame->width) {
			continue;
		};

		for (int y = y1 - radius; y < y1 + radius; y++) {

			if ((y < 0) || (y >= frame->height)) {
				continue;
			};

			// (y-h)^2 + (x-h)^2 = r^2
			if (sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) > radius) {
				continue;
			};

			int ang = DeltasToDegrees(x - x1, y - y1);
			ang = NormalizeAngle(ang);

			if (flip && !((ang < angle1) == (ang < angle2))) {
				continue;
			};

			if (!flip && (ang < angle1) == (ang < angle2)) {
				continue;
			};

			frame->pixels[y * frame->width + x] = (RGB_BLEND(color, frame->pixels[y * frame->width + x], (int)((1 - transparency) * 100)));

		};

	};

	return;
};


void frame_DrawTriangleFilled(struct frameStruct* frame, int x1, int y1, int x2, int y2, int x3, int y3, int color) {

	if (color < 0) {
		color = 0x00FFFFFF;
	};

	/*
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x3 < 0 || y3 < 0) {		// if out of bounds
		return;
	};
	if (x1 >= frame->width || y1 >= frame->height || x2 >= frame->width || y2 >= frame->height || x3 >= frame->width || y3 >= frame->height) {
		return;
	};*/

	if (y1 == y2 || y1 == y3 || y2 == y3) {	// smooth out straight lines
		y1++;
	};
	if (x1 == x2 || x1 == x3 || x2 == x3) {
		x1++;
	};

	int startX = x1;
	if (x2 < startX) {
		startX = x2;
	};
	if (x3 < startX) {
		startX = x3;
	};

	int endX = x1;
	if (x2 > endX) {
		endX = x2;
	};
	if (x3 > endX) {
		endX = x3;
	};

	int startY = y1;
	if (y2 < startY) {
		startY = y2;
	};
	if (y3 < startY) {
		startY = y3;
	};

	int endY = y1;
	if (y2 > endY) {
		endY = y2;
	};
	if (y3 > endY) {
		endY = y3;
	};

	float angle1 = DeltasToDegrees(x2 - x1, y2 - y1);
	float angle2 = DeltasToDegrees(x3 - x1, y3 - y1);

	angle1 = NormalizeAngle(angle1);
	angle2 = NormalizeAngle(angle2);

	int flip1 = 0;
	if (abs(angle2 - angle1) > 180) {
		flip1++;
	};

	float angle3 = DeltasToDegrees(x1 - x2, y1 - y2);
	float angle4 = DeltasToDegrees(x3 - x2, y3 - y2);

	angle3 = NormalizeAngle(angle3);
	angle4 = NormalizeAngle(angle4);

	int flip2 = 0;
	if (abs(angle4 - angle3) > 180) {
		flip2++;
	};

	for (int x = startX; x < endX; x++) {

		if (x < 0 || x >= frame->width) {
			continue;
		};

		for (int y = startY; y < endY; y++) {

			if (y < 0 || y >= frame->height) {
				continue;
			};

			float angle = DeltasToDegrees(x - x1, y - y1);
			angle = NormalizeAngle(angle);

			if (flip1 && !((angle < angle1) == (angle < angle2))) {
				continue;
			};
			if (!flip1 && (angle < angle1) == (angle < angle2)) {
				continue;
			};

			angle = DeltasToDegrees(x - x2, y - y2);
			angle = NormalizeAngle(angle);

			if (flip2 && !((angle < angle3) == (angle < angle4))) {
				continue;
			};
			if (!flip2 && (angle < angle3) == (angle < angle4)) {
				continue;
			};

			frame->pixels[y * frame->width + x] = color;

		};

	};

	return;

};
