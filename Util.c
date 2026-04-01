

#include "Util.h"

int num_CompareTolerance(double num1, double num2, double tol) {


	if (num1 < (num2 - tol) != num1 < (num2 + tol)) {
		return 1;
	};

	return 0;
};


int text_Compare(char string1[], char string2[]) {

	if (text_GetLen(string1, string_maxLength) != text_GetLen(string2, string_maxLength)) {
		return 0;
	};

	int len = text_GetLen(string1, string_maxLength);

	for (int i = 0; i < len; i++) {

		if (string1[i] != string2[i]) {
			return 0;
		};

	};

	return 1;
};

void text_Shift(char string1[], int i, int n) {

	if (n == 0) {
		return;
	};

	if (n < 0) {

		int len = text_GetLen(string1, string_maxLength);

		for (int l = i - n - 1; l < len - n + 1; l++) {

			string1[l + n + 1] = string1[l + 1];
			//l--;

		};

		//string1[len - 1] = 0;
		//string1[len - 2] = 0;
		return;

	};

	for (int l = string_maxLength - n - 2; l >= i; l--) {
		string1[l + n] = string1[l];
		string1[l] = ' ';
	};

	return;

}


void text_ClearString(char text[], int text_maxLen) {

	for (int i = 0; i < text_maxLen; i++) {
		text[i] = 0;
	};

	return;
}


int text_GetLen(char string[], int string_maxLen) {

	for (int i = 0; i < string_maxLength; i++) {

		if (string[i] == 0) {
			return i;
		};

	};

	return (0);
}


int text_StringToInt(char string[]) {	// up to 9 digits

	int nDigits = 0;

	for (int i = 0; i < string_maxLength; i++) {

		if (nDigits >= 9) {
			break;
		};

		if (string[i] == 0) {
			break;
		};

		if (string[i] == '-' && i == 0) {
			continue;
		};

		if (string[i] < '0' || string[i] > '9') {
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

		if (string[i] == 0) {
			break;
		};

		if (string[i] < '0' || string[i] > '9') {
			continue;
		};

		int digit = (int)(string[i] - '0');

		for (int n = 0; n < (nDigits - iDigit - 1); n++) {

			digit *= 10;

		};

		num += digit;
		iDigit++;

	};

	if (string[0] == '-') {
		num *= -1;
	};

	return num;
};


double text_StringToDouble(char string[]) {	// up to 6 decimal points	// 123456789.123456

	double num = 0;

	int iPoint = -1;
	for (int i = 0; i < string_maxLength; i++) {

		if (string[i] == '.') {
			iPoint = i;
			break;
		};

	};

	num += text_StringToInt(string);

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

		if (string[i] < '0' || string[i] > '9') {
			break;
		};

		nDigits++;

	};

	int iDigit = 0;

	for (int i = iPoint + 1; i < string_maxLength; i++) {

		if (iDigit >= nDigits) {
			break;
		};

		if (string[i] == 0) {
			break;
		};

		if (string[i] < '0' || string[i] > '9') {
			continue;
		};

		double digit = (int)(string[i] - '0');

		for (int n = 0; n < iDigit + 1; n++) {

			digit /= 10.0;

		};

		num += digit;
		iDigit++;

	};

	if (string[0] == '-') {
		num *= -1;
	};

	return num;
};


void text_AppendString(
	char text1[], int text1_nChars,
	char text2[], int text2_nChars
	) {
		
	for (int i = 0; i < text2_nChars; i++) {
		text1[text1_nChars + i] = text2[i];
	};

	return;
}


void text_AppendChar(char* text, int text_len, char character) {

	int iEnd = -1;
	for (int i = 0; i < text_len; i++) {

		if (text[i] == 0) {
			iEnd = i;
			break;
		};

	};

	if (iEnd > (text_len - 1)) {
		return;
	};

	if (iEnd < 0) {
		return;
	};

	text[iEnd] = character;

	return;
}


void text_AppendInt(char string[], int string_maxLen, int num) {

	int iEnd = 0;
	for (int i = 0; i < string_maxLength; i++) {

		if (!string[i]) {
			iEnd = i;
			break;
		};

	};

	if (num == 0) {
		string[iEnd] = '0';
		return;
	};

	int num_length = 0;
	int tempNum = abs(num);

	while (tempNum > 0) {

		num_length++;
		tempNum /= 10;

	};

	if (num < 0) {
		string[iEnd] = '-';
		iEnd++;
	};

	num = abs(num);

	for (int i = num_length - 1; i >= 0; i--) {

		string[iEnd + i] = (char)(num % 10 + 48);

		num /= 10;
	};

	return;
}


void text_AppendDouble(char* text, int text_len, double number, int accuracy) {

	if (accuracy > 5) {
		accuracy = 5;
	};
	if (accuracy < 0) {
		accuracy = 5;
	};

	if (number < 0) {
		text_AppendChar(text, text_len, '-');
		number *= -1;
	};

	text_AppendInt(text, text_len, (int)number);
	text_AppendChar(text, text_len, '.');

	int dec = (number - (int)(number)) * 1000000;

	for (int i = 5; i >= 6 - (accuracy); i--) {

		int mult = 1;

		for (int j = 0; j < i; j++) {
			mult *= 10;
		};

		text_AppendInt(
			text,
			text_len,
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


double DeltasToDegrees(double deltaX, double deltaY) {

	if (deltaX == 0 && deltaY == 0) {
		return -1;
	};

	if (deltaY == 0 && deltaX > 0) {
		return 0;
	};

	if (deltaY == 0 && deltaX < 0) {
		return 180;
	};

	if (deltaX == 0 && deltaY > 0) {
		return 90;
	};

	if (deltaX == 0 && deltaY < 0) {
		return 270;
	};

	double angle = atan(deltaY / deltaX) * 180 / 3.14;
	if (deltaX < 0 && deltaY < 0) {	//Quadrant III
		return angle + 180;
	};

	if (deltaX < 0 && deltaY > 0) {	//Quadrant I
		return angle + 180;
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
