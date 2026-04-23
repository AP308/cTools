
#ifndef DRAWING_C
#define DRAWING_C

#include "Drawing.h"

#include <math.h>

#include "Util.h"

#define char_baseCX 7
#define char_baseCY 9

#define bitmap_nChars 128
long long char_bitmaps[bitmap_nChars] = {
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

short char_sizes[bitmap_nChars] = {
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
	(5 << 8) + (9 << 0), // LFd
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

void Draw_Char(
	int* pPixels, int cx, int cy,
	char character,
	int x1, int y1, int scale,
	int* pEndX, int* pEndY,
	int color
) {

	if (color < 0) {
		color = 0xffffff;
	};

	if (scale <= 0) {
		scale = 1;
	};

	if (character < 0) {
		character = 0;
	};

	if (character > bitmap_nChars) {
		character = 0;
	};

	int char_cx = util_HIWORD(char_sizes[character]);
	int char_cy = util_LOWORD(char_sizes[character]);

	long long char_bitmap = char_bitmaps[character];

	for (int y = 0; y < char_cy; y++) {

		for (int x = 0; x < char_cx; x++) {

			int iPixel = (y * char_baseCX + (char_baseCX - x - 1)) + 1;

			if (!((char_bitmap >> iPixel) & 0x1)) {
				continue;
			};

			int startX = x1 + x * scale;
			int startY = y1 + y * scale;

			for (int ix = startX; ix < startX + scale; ix++) {

				if (ix < 0) {
					continue;
				};

				if (ix >= cx) {
					continue;
				};

				for (int iy = startY; iy < startY + scale; iy++) {

					if (iy < 0) {
						continue;
					};

					if (iy >= cy) {
						continue;
					};

					pPixels[iy * cx + ix] = color;

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

void Draw_TextRect(
	int* pPixels, int cx, int cy,
	char* pString, int string_cBuffer,
	int x1, int y1, int x2, int y2,
	int color
) {

	if (color < 0) {
		color = 0xffffff;
	};

	if (y2 < y1) {
		int temp = y1;
		y1 = y2;
		y2 = temp;
	};

	int scale = 2;

	int endX = x1;
	int endY = y2 - (char_baseCY * scale);

	int iLine = 0;

	int nChars = text_GetLen(pString, string_cBuffer);
	for (int i = 0; i < nChars; i++) {

		if (endX > x2 - (char_baseCX * scale)) {
			endX = x1;
			endY -= (char_baseCY + 3) * scale;
		};

		if (endY < y1) {
			break;
		};

		Draw_Char(
			pPixels, cx, cy,
			pString[i],
			endX, endY, scale,
			&endX, &endY,
			color
		);

	};

	return;

};

void Draw_Line(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
) {

	if (color <= 0) {
		color = 0xffffff;
	};

	int dx = x2 - x1;
	int dy = y2 - y1;

	int len = abs(dx);

	if (abs(dy) > abs(dx)) {
		len = abs(dy);
	};

	for (int i = 0; i < len; i++) {

		double t = 1.0 * i / len;

		int x = x1 + dx * t;
		int y = y1 + dy * t;

		if (x < 0) {
			continue;
		};
		if (x >= cx) {
			continue;
		};
		if (y < 0) {
			continue;
		};
		if (y >= cy) {
			continue;
		};

		pPixels[y * cx + x] = color;

	};


	return;
}

void Draw_LineDouble(
	int* pPixels, int cx, int cy,
	double x1, double y1, double x2, double y2,
	int color
) {

	if (color <= 0) {
		color = 0xffffff;
	};

	double dx = x2 - x1;
	double dy = y2 - y1;

	int len = abs(dx);

	if (abs(dy) > abs(dx)) {
		len = abs(dy);
	};

	len = 1000;

	for (int i = 0; i < len; i++) {

		double t = 1.0 * i / len;

		int x = (int)(x1 + dx * t + .5);
		int y = (int)(y1 + dy * t + .5);

		if (x < 0) {
			continue;
		};
		if (x >= cx) {
			continue;
		};
		if (y < 0) {
			continue;
		};
		if (y >= cy) {
			continue;
		};

		pPixels[y * cx + x] = color;

	};


	return;
}

void Draw_LineA(int* pixels, int pixWidth, int pixHeight, int x1, int y1, int dist, double angle, int color) {

	int deltaX = dist * cos(angle * 3.14 / 180);
	int deltaY = dist * sin(angle * 3.14 / 180);

	Draw_Line(pixels, pixWidth, pixHeight, x1, y1, x1 + deltaX, y1 + deltaY, color);

	return;
}


void Draw_Rect(int* pixels, int pixWidth, int pixHeight, int x1, int y1, int x2, int y2, int color) {

	Draw_Line(pixels, pixWidth, pixHeight, x1, y1, x2, y1, color);
	Draw_Line(pixels, pixWidth, pixHeight, x2, y1, x2, y2, color);
	Draw_Line(pixels, pixWidth, pixHeight, x2, y2, x1, y2, color);
	Draw_Line(pixels, pixWidth, pixHeight, x1, y1, x1, y2, color);

	return;
}


void Draw_RectFilled(int* pixels, int pixWidth, int pixHeight, int x1, int y1, int x2, int y2, int color) {

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

		if (x < 0 || x >= pixWidth) {
			continue;
		};

		for (int y = y1; y < y2; y++) {

			if (y < 0 || y >= pixHeight) {
				continue;
			};

			pixels[y * pixWidth + x] = color;

		};

	};

	return;
};

void Draw_RectA(int* pixels, int pixWidth, int pixHeight, int xAnchor, int yAnchor, int horizontalShift, int verticalShift, double angle, int width, int height, int color) {

	int x1 = xAnchor + horizontalShift * cos((angle - 90) * 3.14 / 180) + verticalShift * cos(angle * 3.14 / 180);
	int y1 = yAnchor + horizontalShift * sin((angle - 90) * 3.14 / 180) + verticalShift * sin(angle * 3.14 / 180);

	int x2 = x1 + height * cos(angle * 3.14 / 180);
	int y2 = y1 + height * sin(angle * 3.14 / 180);

	int x4 = x1 + width * cos((angle - 90) * 3.14 / 180);
	int y4 = y1 + width * sin((angle - 90) * 3.14 / 180);

	int x3 = x1 + height * cos(angle * 3.14 / 180) + width * cos((angle - 90) * 3.14 / 180);
	int y3 = y1 + height * sin(angle * 3.14 / 180) + width * sin((angle - 90) * 3.14 / 180);

	Draw_Line(pixels, pixWidth, pixHeight, x1, y1, x2, y2, color);
	Draw_Line(pixels, pixWidth, pixHeight, x2, y2, x3, y3, color);
	Draw_Line(pixels, pixWidth, pixHeight, x3, y3, x4, y4, color);
	Draw_Line(pixels, pixWidth, pixHeight, x4, y4, x1, y1, color);

	return;
};

void Draw_Circle(int* pixels, int pixWidth, int pixHeight, int x1, int y1, int radius, int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	for (float x = x1 - radius; x < x1 + radius; x += .1) {

		if (x < 0) {
			continue;
		};
		if (x >= pixWidth) {
			continue;
		};

		int y = sqrt(radius * radius - (x - x1) * (x - x1)) + y1 - 1;

		if (y >= 0 && y < pixHeight) {
			pixels[(int)(y * pixWidth + x)] = color;
		};

		y = -sqrt(radius * radius - (x - x1) * (x - x1)) + y1 + 1;

		if (y < 0) {
			continue;
		};
		if (y >= pixHeight) {
			continue;
		};

		pixels[(int)(y * pixWidth + x)] = color;

	};

	return;
};


void Draw_CircleFilled(int* pixels, int pixWidth, int pixHeight, int x1, int y1, int radius, int color) {

	if (color < 0) {
		color = 0xffffff;
	};

	for (int x = x1 - radius; x < x1 + radius; x++) {

		if (x < 0) {
			continue;
		};
		if (x >= pixWidth) {
			continue;
		};

		for (int y = y1 - radius; y < y1 + radius; y++) {

			if ((y < 0) || (y >= pixHeight)) {
				continue;
			};

			if (sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) > radius) {
				continue;
			};

			pixels[y * pixWidth + x] = color;

		};

	};

	return;
}

void Draw_Button(
	int* pixels, int pixWidth, int pixHeight,
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

	Draw_CircleFilled(pixels, pixWidth, pixHeight, circleX1, circleY1, roundingRadius, colorFill);
	Draw_CircleFilled(pixels, pixWidth, pixHeight, circleX2, circleY2, roundingRadius, colorFill);
	Draw_CircleFilled(pixels, pixWidth, pixHeight, circleX3, circleY3, roundingRadius, colorFill);
	Draw_CircleFilled(pixels, pixWidth, pixHeight, circleX4, circleY4, roundingRadius, colorFill);

	Draw_Circle(pixels, pixWidth, pixHeight, circleX1, circleY1, roundingRadius, colorOutline);
	Draw_Circle(pixels, pixWidth, pixHeight, circleX2, circleY2, roundingRadius, colorOutline);
	Draw_Circle(pixels, pixWidth, pixHeight, circleX3, circleY3, roundingRadius, colorOutline);
	Draw_Circle(pixels, pixWidth, pixHeight, circleX4, circleY4, roundingRadius, colorOutline);

	Draw_RectFilled(pixels, pixWidth, pixHeight, x1, circleY1, x2, circleY3, colorFill);
	Draw_RectFilled(pixels, pixWidth, pixHeight, circleX1, y1, circleX2, circleY1, colorFill);
	Draw_RectFilled(pixels, pixWidth, pixHeight, circleX1, circleY3, circleX2, y2, colorFill);

	Draw_Line(pixels, pixWidth, pixHeight, circleX1, y1 - 1, circleX2, y1 - 1, colorOutline);
	Draw_Line(pixels, pixWidth, pixHeight, circleX1, y2, circleX2, y2, colorOutline);
	Draw_Line(pixels, pixWidth, pixHeight, x1, circleY3, x1, circleY1, colorOutline);
	Draw_Line(pixels, pixWidth, pixHeight, x2 - 1, circleY3, x2 - 1, circleY1, colorOutline);

	return;
};


#endif
