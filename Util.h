#pragma once
#include <Math.h>

// contains functions for string manipulation

#define string_maxLength 128

#define util_HIWORD(num) ((num >> 8) & (0xff))
#define util_LOWORD(num) ((num) & (0xff))

int num_CompareTolerance(double num1, double num2, double tol);

int text_Compare(char string1[], char string2[]);

int text_CompareBulk(char string[], char stringList[]);	// compare 1 string with list of strings (ex. text_CompareBulk("dog", "tree dog house") would return true)

void text_Shift(char string1[], int i, int n);	// shifts text at pos 'i' by 'n' amount (n may be < 0)

void text_ClearString(char text[], int text_maxLen);

int text_GetLen(char string[], int string_maxLen);

int text_StringToInt(char string[]);

double text_StringToDouble(char string[]);

void text_AppendString(
	char text1[], int text1_nChars,
	char text2[], int text2_nChars
	);

void text_AppendChar(char* text, int text_len, char character);

void text_AppendInt(char string[], int string_maxLen, int num);

void text_AppendDouble(char* text, int text_len, double number, int accuracy);

double NormalizeAngle(double angle);

double DeltasToDegrees(double deltaX, double deltaY);

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
