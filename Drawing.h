
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

void frame_DrawChar(
	int* pPixels, int cx, int cy,
	char character,
	int x1, int y1, int scale,
	int* endx, int* endy,
	int color
);

void frame_DrawTextRect(
	int* pPixels, int cx, int cy,
	char* pString, int string_cBuffer,
	int x1, int y1, int x2, int y2,
	int color
);

void frame_DrawLine(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
);

void frame_DrawLineA(
	int* pPixels, int cx, int cy,
	int x1, int y1, int dist, double angle,
	int color
);

void frame_DrawRect(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
);

void frame_DrawRectFilled(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int color
);

void frame_DrawRectA(
	int* pPixels, int cx, int cy,
	int xAnchor, int yAnchor, int horizontalShift, int verticalShift, double angle, int width, int height,
	int color
);

void frame_DrawCircle(
	int* pPixels, int cx, int cy,
	int x1, int y1, int radius,
	int color
);

void frame_DrawCircleFilled(
	int* pPixels, int cx, int cy,
	int x1, int y1, int radius,
	int color
);

void frame_DrawButton(
	int* pPixels, int cx, int cy,
	int x1, int y1, int x2, int y2,
	int roundingRadius,
	int colorFill, int colorOutline
);
