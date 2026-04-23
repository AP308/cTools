
#pragma once

#define string_maxLength 128

#define RGB(r, g, b)	((b) | ((g) << 8) | ((r) << 16))
#define RGB_GetR(rgb)	( (rgb >> 16)	& 0xff)
#define RGB_GetG(rgb)	( (rgb >> 8)	& 0xff )
#define RGB_GetB(rgb)	( (rgb)			& 0xff )

#define RGB_BLEND(color1, color2, amount)	RGB(\
(int)(RGB_GetR(color1) * (amount / 100.0) + RGB_GetR(color2) * (1 - amount / 100.0)),\
(int)(RGB_GetG(color1) * (amount / 100.0) + RGB_GetG(color2) * (1 - amount / 100.0)),\
(int)(RGB_GetB(color1) * (amount / 100.0) + RGB_GetB(color2) * (1 - amount / 100.0))\
)

void Draw_Char(
	int* pPixels, int cx, int cy,
	char character,
	int x1, int y1, int scale,
	int* endx, int* endy,
	int color
);

void Draw_TextRect(
	int* pPixels, int cx, int cy,
	char* pString, int string_cBuffer,
	int x1, int y1, int x2, int y2,
	int color
);

void Draw_Line(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
);

void Draw_LineDouble(
	int* pPixels, int cx, int cy,
	double x1, double y1, double x2, double y2,
	int color
);

void Draw_LineA(
	int* pPixels, int cx, int cy,
	int x1, int y1, int dist, double angle,
	int color
);

void Draw_Rect(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
);

void Draw_RectFilled(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
);

void Draw_RectA(
	int* pPixels, int cx, int cy,
	int xAnchor, int yAnchor, int horizontalShift, int verticalShift, double angle, int width, int height,
	int color
);

void Draw_Circle(
	int* pPixels, int cx, int cy,
	int x1, int y1, int radius,
	int color
);

void Draw_CircleFilled(
	int* pPixels, int cx, int cy,
	int x1, int y1, int radius,
	int color
);

void Draw_Button(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int roundingRadius,
	int colorFill, int colorOutline
);
