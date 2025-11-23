

#pragma once

#define string_maxLength 128

#define RGB(r, g, b)	(b | (g << 8) | (r << 16))
#define GetRValue(rgb)	( (rgb >> 16) & 0xff)
#define GetGValue(rgb)	( (rgb >> 8) & 0xff )
#define GetBValue(rgb)	( (rgb) & 0xff )

#define RGB_BLEND(color1, color2, amount)	RGB(\
(int)(GetRValue(color1) * (amount / 100.0) + GetRValue(color2) * (1 - amount / 100.0)),\
(int)(GetGValue(color1) * (amount / 100.0) + GetGValue(color2) * (1 - amount / 100.0)),\
(int)(GetBValue(color1) * (amount / 100.0) + GetBValue(color2) * (1 - amount / 100.0))\
)

// contains drawing commands for winapi graphics

struct frameStruct {
	int width;
	int height;
	int* pixels;
};

enum {
	TEXT_CLIP = -1,
	TEXT_WRAP
};

void frame_DrawText(struct frameStruct* frame, int x1, int y1, char text[], int text_radius, int text_spacing, float text_thickness, short text_structure, int text_color);

void frame_DrawLine(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color);

void frame_DrawLineModulus(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color);

void frame_DrawLineA(struct frameStruct* frame, int x1, int y1, int dist, double angle, int color);

void frame_DrawRect(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color);

void frame_DrawRectFilled(struct frameStruct* frame, int x1, int y1, int x2, int y2, int color, float transparency);

void frame_DrawRectA(struct frameStruct* frame, int xAnchor, int yAnchor, int horizontalShift, int verticalShift, double angle, int width, int height, int color);

void frame_DrawRectAFilled(struct frameStruct* frame, int xAnchor, int yAnchor, int horizontalShift, int verticalShift, int angle, int width, int height, int color);

void frame_DrawCircle(struct frameStruct* frame, int x1, int y1, int radius, int color);

void frame_DrawCircleFilled(struct frameStruct* frame, int x1, int y1, int radius, int color);

void frame_DrawSemiCircleFilled(struct frameStruct* frame, int x1, int y1, int radius, int sliceAngle, int angle, int color, float transparency);

void frame_DrawTriangleFilled(struct frameStruct* frame, int x1, int y1, int x2, int y2, int x3, int y3, int color);
