#pragma once
#include <Math.h>

// contains functions for string manipulation

#define string_maxLength 128

int num_CompareTolerance(double num1, double num2, double tol);

int text_Compare(char string1[], char string2[]);

int text_CompareBulk(char string[], char stringList[]);	// compare 1 string with list of strings (ex. text_CompareBulk("dog", "tree dog house") would return true)

void text_Shift(char string1[], int i, int n);	// shifts text at pos 'i' by 'n' amount (n may be < 0)

void text_ClearString(char string[]);

int text_GetSize(char string[]);

int text_StringToInt(char string[]);

double text_StringToDouble(char string[]);

void text_AppendString(char string1[], char string2[]);

void text_AppendChar(char string1[], char char1);

void text_AppendInt(char string[], int num);

void text_AppendDouble(char string[], double num, int accuracy);

double NormalizeAngle(double angle);

double DeltasToDegrees(double deltaX, double deltaY);

int util_CollisionDist(int plrX, double plrY, double plrAngle, int x1, int y1, int x2, int y2, int* pX, int* pY);

