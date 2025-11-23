

#include "Util.h"

int num_CompareTolerance(double num1, double num2, double tol) {


	if (num1 < (num2 - tol) != num1 < (num2 + tol)) {
		return 1;
	};

	return 0;
};


int text_Compare(char string1[], char string2[]) {

	if (text_GetSize(string1) != text_GetSize(string2)) {
		return 0;
	};

	int len = text_GetSize(string1);

	for (int i = 0; i < len; i++) {

		if (string1[i] != string2[i]) {
			return 0;
		};

	};

	return 1;
};


int text_CompareBulk(char string[], char stringList[]) {

	char word[string_maxLength] = { 0 };

	int lenWord = text_GetSize(stringList);

	for (int w = 0; w < lenWord; w++) {

		if (stringList[w] != ' ') {
			text_AppendChar(word, stringList[w]);
		};

		if ((stringList[w] != ' ') && (w != lenWord - 1)) {
			continue;
		};

		if (text_Compare(string, word)) {
			return 1;
		};

		text_ClearString(word);


	};


	return 0;
};


void text_Shift(char string1[], int i, int n) {

	if (n == 0) {
		return;
	};

	if (n < 0) {

		int len = text_GetSize(string1);

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


void text_ClearString(char string[]) {

	for (int i = 0; i < string_maxLength; i++) {
		string[i] = 0;
	};

	return;
}


int text_GetSize(char string[]) {

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


void text_AppendString(char string1[], char string2[]) {

	if (string_maxLength < 0) {
		return;
	};

	int iEnd = 0;
	for (int i = 0; i < string_maxLength; i++) {

		if (!string1[i]) {
			iEnd = i;
			break;
		};

	};

	if (string_maxLength <= 0) {
		iEnd = 0;
	};

	for (int i = 0; i < string_maxLength; i++) {

		if (string_maxLength == 1) {
			string1[iEnd + i] = string2;
			continue;
		};

		if (string2[i] == 0) {	//when string2 over
			break;
		};

		string1[iEnd + i] = string2[i];

	};

	return;
}


void text_AppendChar(char string1[], char char1) {

	int iEnd = 0;
	for (int i = 0; i < string_maxLength; i++) {

		if (string1[i] == 0) {
			iEnd = i;
			break;
		};

	};

	if (string_maxLength <= 0) {
		iEnd = 0;
	};

	//if (iEnd >= string_maxLength - 1) {	// idk why, but can't append at last index
		//return;
	//};

	string1[iEnd] = char1;

	return;
}


void text_AppendInt(char string[], int num) {

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


void text_AppendDouble(char string[], double num, int accuracy) {

	if (num < 0) {
		text_AppendChar(string, '-');
		num *= -1;
	};

	text_AppendInt(string, num);
	text_AppendChar(string, '.');

	int dec = (num - (int)(num)) * 1000000;

	if (accuracy > 5) {
		accuracy = 5;
	};
	if (accuracy < 0) {
		accuracy = 0;
	};

	for (int i = 5; i >= 6 - (accuracy); i--) {

		int mult = 1;

		for (int j = 0; j < i; j++) {
			mult *= 10;
		};

		text_AppendInt(string, (int)(dec % (mult * 10) / (mult)));

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

//					   plrX, plrY, plrAngle, 2nd line data is all the rest
int util_CollisionDist(int plrX, double plrY, double plrAngle, int x1, int y1, int x2, int y2, int* pX, int* pY) {

	double deltaX1 = cos(plrAngle * 3.14 / 180);
	double deltaY1 = sin(plrAngle * 3.14 / 180);

	double deltaX2 = x2 - x1;
	double deltaY2 = y2 - y1;

	double v = (deltaX1 * (y1 - plrY) + (deltaY1) * (plrX - x1)) / ((deltaY1 * deltaX2) - (deltaX1 * deltaY2));

	double u = x1 - 1 + (deltaX2 * v);

	if (deltaX1 != 0) {
		u = ((x1 - plrX) + (deltaX2 * v)) / (deltaX1);
	};

	double pointX = (int)(x1 + deltaX2 * v);
	double pointY = (int)(y1 + deltaY2 * v);

	if (((pointY < y1) == (pointY < y2)) && ((pointX < x1) == (pointX < x2))) {	// if outside of line
		*pX = -1;
		*pY = -1;
		return -1;
	};

	if ((u <= 0) || (v <= 0)) {
		*pX = -1;
		*pY = -1;
		return -1;
		// return -1;
	};

	*pX = (int)(pointX);
	*pY = (int)(pointY);

	//return (sqrt(((pointX - plrX) * (pointX - plrX)) + ((pointY - plrY) * (pointY - plrY))));
};
