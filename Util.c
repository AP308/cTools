
#ifndef UTIL_C
#define UTIL_C

#include "Util.h"

#include <Math.h>

void text_ClearString(char* pString, int string_cBuffer) {

	for (int i = 0; i < string_cBuffer; i++) {
		pString[i] = 0;
	};

	return;
}

int text_GetLen(char* pString, int string_cBuffer) {

	for (int i = 0; i < string_cBuffer; i++) {

		if (pString[i] == 0) {
			return i;
		};

	};

	return string_cBuffer;
}

int text_StringToInt(char* pString, int string_cBuffer) {	// up to 9 digits

	int nDigits = 0;

	for (int i = 0; i < string_maxLength; i++) {

		if (nDigits >= 9) {
			break;
		};

		if (pString[i] == 0) {
			break;
		};

		if (pString[i] == '-' && i == 0) {
			continue;
		};

		if (pString[i] < '0' || pString[i] > '9') {
			break;
		};

		nDigits++;
	};

	int num = 0;
	int iDigit = 0;

	for (int i = 0; i < string_maxLength; i++) {

		if (iDigit >= nDigits) {
			break;
		};

		if (pString[i] == 0) {
			break;
		};

		if (pString[i] < '0' || pString[i] > '9') {
			continue;
		};

		int digit = (int)(pString[i] - '0');

		for (int n = 0; n < (nDigits - iDigit - 1); n++) {

			digit *= 10;

		};

		num += digit;
		iDigit++;

	};

	if (pString[0] == '-') {
		num *= -1;
	};

	return num;
};

double text_StringToDouble(char* pString, int string_cBuffer) {	// up to 6 decimal points

	double num = 0;

	int iPoint = -1;
	for (int i = 0; i < string_maxLength; i++) {

		if (pString[i] == '.') {
			iPoint = i;
			break;
		};

	};

	num += text_StringToInt(pString, string_cBuffer);

	if (num < 0) {
		num *= -1;
	};

	if (iPoint < 0) {
		return num;
	};

	int nDigits = 0;

	for (int i = iPoint + 1; i < string_maxLength; i++) {

		if (nDigits >= 6) {
			break;
		};

		if (pString[i] < '0' || pString[i] > '9') {
			break;
		};

		nDigits++;

	};

	int iDigit = 0;

	for (int i = iPoint + 1; i < string_maxLength; i++) {

		if (iDigit >= nDigits) {
			break;
		};

		if (pString[i] == 0) {
			break;
		};

		if (pString[i] < '0' || pString[i] > '9') {
			continue;
		};

		double digit = (int)(pString[i] - '0');

		for (int n = 0; n < iDigit + 1; n++) {

			digit /= 10.0;

		};

		num += digit;
		iDigit++;

	};

	if (pString[0] == '-') {
		num *= -1;
	};

	return num;
};

void text_AppendChar(
	char* pString, int string_cBuffer,
	char character
) {

	int iEnd = text_GetLen(pString, string_cBuffer);

	if (iEnd < 0) {
		return;
	};
	
	if (iEnd >= string_cBuffer) {
		return;
	};

	pString[iEnd] = character;

	return;
}

void text_AppendString(
	char* pString1, int string1_cBuffer,
	char* pString2, int string2_cBuffer
) {

	int iEnd1 = text_GetLen(pString1, string1_cBuffer);
	int iEnd2 = text_GetLen(pString2, string2_cBuffer);

	for (int i = 0; i < iEnd2; i++) {
		pString1[iEnd1 + i] = pString2[i];
	};

	return;
}

void text_AppendInt(
	char* pString, int string_cBuffer,
	int num
) {

	int iEnd = 0;
	for (int i = 0; i < string_maxLength; i++) {

		if (!pString[i]) {
			iEnd = i;
			break;
		};

	};

	if (num == 0) {
		pString[iEnd] = '0';
		return;
	};

	int num_length = 0;
	int tempNum = abs(num);

	while (tempNum > 0) {

		num_length++;
		tempNum /= 10;

	};

	if (num < 0) {
		pString[iEnd] = '-';
		iEnd++;
	};

	num = abs(num);

	for (int i = num_length - 1; i >= 0; i--) {

		pString[iEnd + i] = (char)(num % 10 + 48);

		num /= 10;
	};

	return;
}

void text_AppendDouble(
	char* pString, int string_cBuffer,
	double number, int accuracy
) {

	if (accuracy > 5) {
		accuracy = 5;
	};
	if (accuracy < 0) {
		accuracy = 5;
	};

	if (number < 0) {
		text_AppendChar(pString, string_cBuffer, '-');
		number *= -1;
	};

	text_AppendInt(pString, string_cBuffer, (int)number);
	text_AppendChar(pString, string_cBuffer, '.');

	int dec = (number - (int)(number)) * 1000000;

	for (int i = 5; i >= 6 - (accuracy); i--) {

		int mult = 1;

		for (int j = 0; j < i; j++) {
			mult *= 10;
		};

		text_AppendInt(
			pString,
			string_cBuffer,
			(int)(dec % (mult * 10) / (mult)));

	};

	return;
}


double NormalizeAngle(double angle) {

	while (angle >= 360) {
		angle -= 360;
	};

	while (angle < 0) {
		angle += 360;
	};

	return angle;
}

int util_SegmentSegmentIntersection(
	double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4,
	int bind1, int bind2,
	double* px, double* py
) {

	double dx1 = x2 - x1;
	double dy1 = y2 - y1;

	double dx2 = x4 - x3;
	double dy2 = y4 - y3;

	if (!dx1 && !dy1) {
		return 0;
	};
	if (!dx2 && !dy2) {
		return 0;
	};

	double v = ((dx1) * (y3 - y1) + (dy1) * (x1 - x3));

	if ((dy1 * dx2) - (dx1 * dy2)) {
		v /= (1.0 * (dy1 * dx2) - (dx1 * dy2));
	};

	double u = ((x3 - x1) + (dx2 * v));

	if (dx1) {
		u /= (1.0 * dx1);
	};

	if (u > 1.0 && bind1) {
		return 0;
	};
	if (v > 1.0 && bind2) {
		return 0;
	};
	if (u < 0) {
		return 0;
	};
	if (v < 0) {
		return 0;
	};

	double collision_x = x3 + dx2 * v;
	double collision_y = y3 + dy2 * v;

	if (((collision_y < y1) == (collision_y < y2)) && ((collision_x < x1) == (collision_x < x2)) && bind1) {
		//return 0;
	};
	if (((collision_y < y3) == (collision_y < y4)) && ((collision_x < x3) == (collision_x < x3)) && bind2) {
		//return 0;
	};

	*px = collision_x;
	*py = collision_y;

	return 1;

};

char util_SegmentCircleIntersection(
	double x1, double y1, double x2, double y2,
	double h, double k, double radius,
	int bind1,
	double* px1, double* py1,
	double* px2, double* py2
) {

	double a = x2 - x1;
	double b = x1 - h;
	double c = y2 - y1;
	double d = y1 - k;
	double e = radius * radius;

	double q_a = a * a + c * c;

	if (!q_a) {
		return 0;
	};

	double q_b = 2 * a * b + 2 * c * d;
	double q_c = b * b + d * d - e;

	double chunk = q_b * q_b - 4 * q_a * q_c;

	if (chunk < 0) {
		return 0;
	};

	chunk = sqrt(chunk);

	double u = (-q_b - chunk) / (2 * q_a);

	if (u <= 0) {
		return 0;
	};

	if (u > 1 && bind1) {
		return 0;
	};

	if (px1 && py1) {
		*px1 = x1 + a * u;
		*py1 = y1 + c * u;
	};

	u = (-q_b + chunk) / (2 * q_a);

	if (u <= 0) {
		return (1 << 4);
	};

	if (u > 1 && bind1) {
		return (1 << 4);
	};

	if (px2 && py2) {
		*px2 = x1 + a * u;
		*py2 = y1 + c * u;
	};

	return ((1 << 4) + (1 << 0));

};

/* orbit 2 centers??
* 	double a = x2 - x1;
	double b = x1 - x3;
	double c = y2 - y1;
	double d = y1 - y3;
	double e = radius * radius;

	double q_a = a * a + c * c;
	double q_b = 2 * a * b + 2 * c * d;
	double q_c = e - b * b - c * c;

	double chunk = sqrt(q_b * q_b - 4 * q_a * q_c);

	double u = (-q_b + chunk) / (2 * q_a);

	*px1 = x1 + a * u;
	*py1 = y1 + c * u;*/

#endif
