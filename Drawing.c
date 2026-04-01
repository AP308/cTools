
#pragma once

#include "Drawing.h"
#include "Util.h"

#define nChars 128
long long char_bitmaps[nChars] = {
	0xf913a64d9b367cd8, // NUL
	0xf913a64d9b367cd8, // SOH
	0xf913a64d9b367cd8, // STX
	0xf913a64d9b367cd8, // ETX
	0xf913a64d9b367cd8, // EOT
	0xf913a64d9b367cd8, // ENQ
	0xf913a64d9b367cd8, // ACK
	0xf913a64d9b367cd8, // BEL
	0xf913a64d9b367cd8, // BS
	0xf913a64d9b367cd8, // TAB
	0xf913a64d9b367cd8, // LF (linefeed, newline)
	0xf913a64d9b367cd8, // VT
	0xf913a64d9b367cd8, // FF
	0xf913a64d9b367cd8, // CR
	0xf913a64d9b367cd8, // SO
	0xf913a64d9b367cd8, // SI
	0xf913a64d9b367cd8, // DLE
	0xf913a64d9b367cd8, // DC1
	0xf913a64d9b367cd8, // DC2
	0xf913a64d9b367cd8, // DC3
	0xf913a64d9b367cd8, // DC4
	0xf913a64d9b367cd8, // NAK
	0xf913a64d9b367cd8, // SYN
	0xf913a64d9b367cd8, // ETB
	0xf913a64d9b367cd8, // CAN
	0xf913a64d9b367cd8, // EM
	0xf913a64d9b367cd8, // SUB
	0xf913a64d9b367cd8, // ESC
	0xf913a64d9b367cd8, // FS
	0xf913a64d9b367cd8, // GS
	0xf913a64d9b367cd8, // RS
	0xf913a64d9b367cd8, // US
	0x0000000000000000, // space
	0x0102040810200080, // !
	0xa140000000000000, // "
	0x0000028f8a3e2800, // #
	0x20f28507050a7820, // $
	0x00010d2482092584, // %
	0x3091218491214570, // &
	0x8100000000000000, // '
	0x4102040810204040, // (
	0x8081020408102080, // )
	0x0001410f84140000, // *
	0x0000810f84080000, // +
	0x0000000000102080, // ,
	0x0000000f80000000, // -
	0x0000000000000080, // .
	0x0810408204102080, // /
	0x711224ca99224470, // 0
	0x41810204081020e0, // 1
	0x71102041041040f8, // 2
	0x7110204701024470, // 3
	0x8912244f81020408, // 4
	0xf902040f01024470, // 5
	0x7112040f11224470, // 6
	0xf810208104082040, // 7
	0x7112244711224470, // 8
	0x7112244781024470, // 9
	0x0000040000200000, // :
	0x0000020000102080, // ;
	0x0000820808080000, // <
	0x000007c01f000000, // =
	0x0002020208200000, // >
	0xf020438408100040, // ?
	0x6122458b16204070, // @
	0x7112244f91224488,	// A
	0xf112244f112244f0, // B
	0x7112040810204470, // C
	0xf1122448912244f0, // D
	0xf902040f902040f8, // E
	0xf902040f90204080, // F
	0x7902040b91224470, // G
	0x8912244f91224488, // H
	0xf8408102040810f8, // I
	0xf020408102044870, // J
	0x8912248e12224488, // K
	0x81020408102040f8, // L
	0x838eac983060c182, // M
	0x8993254a95264c88, // N
	0x7112244891224470, // O
	0xf112244f10204080, // P
	0x7112244891224868, // Q
	0xf112244f11224488, // R
	0x79020407010204f0, // S
	0xf840810204081020, // T
	0x8912244891224470, // U
	0x83060C14488A1410, // V
	0x83060c18326ae382, // W
	0x8289114105112282, // X
	0x8305122282040810, // Y
	0xf8102082082040f8, // Z
	0xc1020408102040c0, // [
	0x8101020204040808, // backslash
	0xc0810204081020c0, // ]
	0x4142800000000000, // ^
	0x00000000000000f8, // _
	0x8080000000000000, // `
	0x0000000693224478, // a
	0x8102040b19224470, // b
	0x0000000710204070, // c
	0x0810204693224470, // d
	0x00000007112c4070, // e
	0x00e2040e10204080, // f
	0x00000007111e0470, // g
	0x8102040f11224488, // h
	0x0000040010204080, // i
	0x00000100040850e0, // j
	0x8102040914305090, // k
	0x0102040810204080, // l
	0x00000006d260c182, // m
	0x0000000b19224488, // n
	0x0000000711224470, // o
	0x0000000711325880, // p
	0x0000000791263408, // q
	0x0000000610204080, // r
	0x00000007101808e0, // s
	0x0081070408102040, // t
	0x0000000891224470, // u
	0x0000000891142820, // v
	0x0000000891225450, // w
	0x000000088a082888, // x
	0x000000088a082080, // y
	0x0000000f820820f8, // z
	0x2081020808102020, // {
	0x8102040810204080, // |
	0x8081020208102080, // }
	0x0000000653000000, // ~
	0xf913a64d9b367cd8, // DEL
};

short char_sizes[nChars] = {
	(5 << 8) + (9 << 0), // NUL
	(5 << 8) + (9 << 0), // SOH
	(5 << 8) + (9 << 0), // STX
	(5 << 8) + (9 << 0), // ETX
	(5 << 8) + (9 << 0), // EOT
	(5 << 8) + (9 << 0), // ENQ
	(5 << 8) + (9 << 0), // ACK
	(5 << 8) + (9 << 0), // BEL
	(5 << 8) + (9 << 0), // BS
	(5 << 8) + (9 << 0), // TAB
	(5 << 8) + (9 << 0), // LF
	(5 << 8) + (9 << 0), // VT
	(5 << 8) + (9 << 0), // FF
	(5 << 8) + (9 << 0), // CR
	(5 << 8) + (9 << 0), // SO
	(5 << 8) + (9 << 0), // SI
	(5 << 8) + (9 << 0), // DLE
	(5 << 8) + (9 << 0), // DC1
	(5 << 8) + (9 << 0), // DC2
	(5 << 8) + (9 << 0), // DC3
	(5 << 8) + (9 << 0), // DC4
	(5 << 8) + (9 << 0), // NAK
	(5 << 8) + (9 << 0), // SYN
	(5 << 8) + (9 << 0), // ETB
	(5 << 8) + (9 << 0), // CAN
	(5 << 8) + (9 << 0), // EM
	(5 << 8) + (9 << 0), // SUB
	(5 << 8) + (9 << 0), // ESC
	(5 << 8) + (9 << 0), // FS
	(5 << 8) + (9 << 0), // GS
	(5 << 8) + (9 << 0), // RS
	(5 << 8) + (9 << 0), // US
	(1 << 8) + (1 << 0), // space
	(1 << 8) + (8 << 0), // !
	(3 << 8) + (9 << 0), // "
	(5 << 8) + (6 << 0), // #
	(5 << 8) + (9 << 0), // $
	(7 << 8) + (7 << 0), // %
	(7 << 8) + (9 << 0), // &
	(1 << 8) + (9 << 0), // '
	(2 << 8) + (9 << 0), // (
	(2 << 8) + (9 << 0), // )
	(5 << 8) + (7 << 0), // *
	(5 << 8) + (7 << 0), // +
	(2 << 8) + (3 << 0), // ,
	(5 << 8) + (6 << 0), // -
	(1 << 8) + (1 << 0), // .
	(5 << 8) + (9 << 0), // /
	(5 << 8) + (9 << 0), // 0
	(3 << 8) + (9 << 0), // 1
	(5 << 8) + (9 << 0), // 2
	(5 << 8) + (9 << 0), // 3
	(5 << 8) + (9 << 0), // 4
	(5 << 8) + (9 << 0), // 5
	(5 << 8) + (9 << 0), // 6
	(5 << 8) + (9 << 0), // 7
	(5 << 8) + (9 << 0), // 8
	(5 << 8) + (9 << 0), // 9
	(1 << 8) + (7 << 0), // :
	(2 << 8) + (7 << 0), // ;
	(3 << 8) + (7 << 0), // <
	(5 << 8) + (6 << 0), // =
	(3 << 8) + (7 << 0), // >
	(4 << 8) + (9 << 0), // ?
	(4 << 8) + (9 << 0), // @
	(5 << 8) + (9 << 0), // A
	(5 << 8) + (9 << 0), // B
	(5 << 8) + (9 << 0), // C
	(5 << 8) + (9 << 0), // D
	(5 << 8) + (9 << 0), // E
	(5 << 8) + (9 << 0), // F
	(5 << 8) + (9 << 0), // G
	(5 << 8) + (9 << 0), // H
	(5 << 8) + (9 << 0), // I
	(4 << 8) + (9 << 0), // J
	(5 << 8) + (9 << 0), // K
	(5 << 8) + (9 << 0), // L
	(7 << 8) + (9 << 0), // M
	(5 << 8) + (9 << 0), // N
	(5 << 8) + (9 << 0), // O
	(5 << 8) + (9 << 0), // P
	(5 << 8) + (9 << 0), // Q
	(5 << 8) + (9 << 0), // R
	(5 << 8) + (9 << 0), // S
	(5 << 8) + (9 << 0), // T
	(5 << 8) + (9 << 0), // U
	(7 << 8) + (9 << 0), // V
	(7 << 8) + (9 << 0), // W
	(7 << 8) + (9 << 0), // X
	(7 << 8) + (9 << 0), // Y
	(5 << 8) + (9 << 0), // Z
	(2 << 8) + (9 << 0), // [
	(5 << 8) + (9 << 0), // backslash
	(2 << 8) + (9 << 0), // ]
	(3 << 8) + (9 << 0), // ^
	(5 << 8) + (1 << 0), // _
	(2 << 8) + (9 << 0), // `
	(5 << 8) + (6 << 0), // a
	(5 << 8) + (9 << 0), // b
	(4 << 8) + (6 << 0), // c
	(5 << 8) + (9 << 0), // d
	(5 << 8) + (6 << 0), // e
	(4 << 8) + (8 << 0), // f
	(5 << 8) + (6 << 0), // g
	(5 << 8) + (9 << 0), // h
	(1 << 8) + (6 << 0), // i
	(3 << 8) + (6 << 0), // j
	(5 << 8) + (8 << 0), // k
	(1 << 8) + (8 << 0), // l
	(7 << 8) + (6 << 0), // m
	(5 << 8) + (6 << 0), // n
	(5 << 8) + (6 << 0), // o
	(5 << 8) + (6 << 0), // p
	(5 << 8) + (6 << 0), // q
	(3 << 8) + (6 << 0), // r
	(4 << 8) + (6 << 0), // s
	(3 << 8) + (8 << 0), // t
	(5 << 8) + (6 << 0), // u
	(5 << 8) + (6 << 0), // v
	(5 << 8) + (6 << 0), // w
	(5 << 8) + (6 << 0), // x
	(5 << 8) + (6 << 0), // y
	(5 << 8) + (6 << 0), // z
	(3 << 8) + (9 << 0), // {
	(1 << 8) + (9 << 0), // |
	(3 << 8) + (9 << 0), // }
	(6 << 8) + (5 << 0), // ~
	(5 << 8) + (9 << 0), // DEL
};

#define char_baseCX 7
#define char_baseCY 9

void frame_DrawChar(
	struct frameStruct* frame,
	char character,
	int x1, int y1, int scale,
	int* pEndX, int* pEndY,
	int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	if (scale <= 0) {
		scale = 1;
	};

	if (character < 0) {
		character = 0;
	};

	if (character > nChars) {
		character = 0;
	};

	int char_cx = util_HIWORD(char_sizes[character]);
	int char_cy = util_LOWORD(char_sizes[character]);

	long long char_bitmap = char_bitmaps[character];

	for (int y = 0; y < char_cy; y++) {

	for (int x = 0; x < char_cx; x++) {

		int index = (y * char_baseCX + (char_baseCX - x - 1)) + 1;

		if (!((char_bitmap >> index) & 0x1)) {
			continue;
		};
				
		int startX = x1 + x * scale;
		int startY = y1 + y * scale;

		for (int ix = startX; ix < startX + scale; ix++) {

		if (ix < 0) {
			continue;
		};

		if (ix >= frame->width) {
			continue;
		};

		for (int iy = startY; iy < startY + scale; iy++) {

			if (iy < 0) {
				continue;
			};

			if (iy >= frame->height) {
				continue;
			};

			frame->pixels[iy * frame->width + ix] = color;

		};

		};

	};

	};

	if (pEndX && pEndY) {
		*pEndX = x1 + (char_cx + 1) * scale;
		*pEndY = y1;
	};

	return;
};

void frame_DrawTextRect(
	struct frameStruct* frame,
	char text[], int text_nChars,
	int x1, int y1, int x2, int y2,
	int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	if (y2 < y1) {
		int temp = y1;
		y1 = y2;
		y2 = temp;
	};

	//frame_DrawRectFilled(frame, x1, y1, x2, y2, 0x222222);

	int scale = 2;

	int endX = x1;
	int endY = y2 - (char_baseCY * scale);

	int iLine = 0;

	for (int i = 0; i < text_nChars; i++) {

		if (endX > x2 - (char_baseCX * scale)) {
			endX = x1;
			endY -= (char_baseCY + 3) * scale;
		};

		if (endY < y1) {
			break;
		};

		frame_DrawChar(
			frame, text[i],
			endX, endY, scale,
			&endX, &endY,
			color);

	};

	return;

};

void frame_DrawLine(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	if (!deltaX && !deltaY) {
		return;
	};

	double tIncrement = 1.0 / sqrt((deltaX * deltaX) + (deltaY * deltaY));

	for (double t = 0; t <= 1; t += tIncrement) {

		int x = x1 + deltaX * t;
		int y = y1 + deltaY * t;

		if (!deltaX) {
			x = x1;
		};
		if (!deltaY) {
			y = y1;
		};

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


void frame_DrawRectFilled(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color) {

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

			frame->pixels[y * frame->width + x] = color;

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
		frame_DrawRectFilled(frame, xAnchor + horizontalShift, yAnchor + verticalShift, xAnchor + width + horizontalShift, yAnchor + height + verticalShift, color);
		return;
	};

	if (angle == 270) {
		frame_DrawRectFilled(frame, xAnchor - horizontalShift, yAnchor - verticalShift, xAnchor - width - horizontalShift, yAnchor - height - verticalShift, color);
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


void frame_DrawCircle(struct frameStruct* frame, int x1, int y1, int radius, int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	for (float x = x1 - radius; x < x1 + radius; x += .1) {

		if (x < 0) {
			continue;
		};
		if (x >= frame->width) {
			continue;
		};

		int y = sqrt(radius * radius - (x - x1) * (x - x1)) + y1 - 1;

		if (y >= 0 && y < frame->height) {
			frame->pixels[(int)(y * frame->width + x)] = color;
		};

		y = -sqrt(radius * radius - (x - x1) * (x - x1)) + y1 + 1;

		if (y < 0) {
			continue;
		};
		if (y >= frame->height) {
			continue;
		};

		frame->pixels[(int)(y * frame->width + x)] = color;

	};

	return;
};


void frame_DrawCircleFilled(struct frameStruct* frame, int x1, int y1, int radius, int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	for (int x = x1 - radius; x < x1 + radius; x++) {

		if (x < 0) {
			continue;
		};
		if (x >= frame->width) {
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

void frame_DrawButton(
	struct framestruct* frame,
	int x1, int y1, int x2, int y2,
	int roundingRadius,
	int colorFill, int colorOutline
	) {

	int circleX1 = x1 + roundingRadius;
	int circleY1 = y1 - roundingRadius;

	int circleX2 = x2 - roundingRadius;
	int circleY2 = y1 - roundingRadius;

	int circleX3 = x2 - roundingRadius;
	int circleY3 = y2 + roundingRadius;

	int circleX4 = x1 + roundingRadius;
	int circleY4 = y2 + roundingRadius;

	frame_DrawCircleFilled(frame, circleX1, circleY1, roundingRadius, colorFill);
	frame_DrawCircleFilled(frame, circleX2, circleY2, roundingRadius, colorFill);
	frame_DrawCircleFilled(frame, circleX3, circleY3, roundingRadius, colorFill);
	frame_DrawCircleFilled(frame, circleX4, circleY4, roundingRadius, colorFill);

	frame_DrawCircle(frame, circleX1, circleY1, roundingRadius, colorOutline);
	frame_DrawCircle(frame, circleX2, circleY2, roundingRadius, colorOutline);
	frame_DrawCircle(frame, circleX3, circleY3, roundingRadius, colorOutline);
	frame_DrawCircle(frame, circleX4, circleY4, roundingRadius, colorOutline);

	frame_DrawRectFilled(frame, x1, circleY1, x2, circleY3, colorFill);
	frame_DrawRectFilled(frame, circleX1, y1, circleX2, circleY1, colorFill);
	frame_DrawRectFilled(frame, circleX1, circleY3, circleX2, y2, colorFill);

	frame_DrawLine(frame, circleX1, y1 - 1, circleX2, y1 - 1, colorOutline);
	frame_DrawLine(frame, circleX1, y2, circleX2, y2, colorOutline);
	frame_DrawLine(frame, x1, circleY3, x1, circleY1, colorOutline);
	frame_DrawLine(frame, x2 - 1, circleY3, x2 - 1, circleY1, colorOutline);

	return;
};

/*
#define segData_offset -32
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
*/
