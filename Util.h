
#pragma once

#define string_maxLength 128

#define util_HIWORD(num) ((num >> 8) & (0xff))
#define util_LOWORD(num) ((num)		 & (0xff))

void text_ClearString(char* pString, int string_cBuffer);

int text_GetLen(char* pString, int string_cBuffer);

int text_StringToInt(char* pString, int string_cBuffer);

double text_StringToDouble(char* pString, int string_cBuffer);

void text_AppendChar(
	char* pString, int string_cBuffer,
	char character
);

void text_AppendString(
	char* pString1, int string1_cBuffer,
	char* pString2, int string2_cBuffer
);

void text_AppendInt(
	char* pString, int string_cBuffer,
	int num
);

void text_AppendDouble(
	char* pString, int string_cBuffer,
	double number, int accuracy
);

double NormalizeAngle(double angle);

int util_SegmentSegmentIntersection(
	double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4,
	int bind1, int bind2,
	double* px, double* py
);

char util_SegmentCircleIntersection(
	double x1, double y1, double x2, double y2,
	double h, double k, double radius,
	int bind1,
	double* px1, double* py1,
	double* px2, double* py2
);
