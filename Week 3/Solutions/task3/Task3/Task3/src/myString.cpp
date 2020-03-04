#include "myString.h"
#include <string.h>
#include <cmath>

#pragma warning(disable : 4996)

myString::myString() {
	str = nullptr;
	len = 0;
}

myString::myString(char* _str) {
	len = strlen(_str) + 1;
	str = new char[len];
	strcpy(str, _str);
}


void myString::setStr(char* _str) {
	if (str != nullptr) {
		delete[] str;
	}
	
	len = strlen(_str) + 1;
	str = new char[len];
	strcpy(str, _str);
}

int myString::cmp(char* _str) {

	if (_str == nullptr || str == nullptr) {
		return 100;
	}
	
	int diffSize = strlen(str) - strlen(_str);
	int overlapLen = fmax(strlen(str), strlen(_str));
	
	for (int i = 0; i < overlapLen; i++) {
		if (str[i] > _str[i]) return 1;
		if (str[i] < _str[i]) return -1;
	}

	if (diffSize == 0) {
		return 0;
	}

	if (strlen(str) > strlen(_str)) {
		return -1;
	}
	else {
		return 1;
	}
}

int myString::find(char* _str) {
	if (_str == nullptr || str == nullptr) {
		return -1;
	}

	if (strlen(str) < strlen(_str)) {
		return -1;
	}

	for (int i = 0; i < strlen(str) - strlen(_str); i++) {
		int counter = 0;
		while (str[i+counter] == _str[counter]) {
			counter++;
		}

		if (counter == strlen(_str)) return i;
	}

	return -1;

}

void myString::deleteSubStr(char* _str) {
	if (_str == nullptr || str == nullptr) {
		return;
	}

	if (strlen(str) < strlen(_str)) {
		return;
	}

	int pos = -1, shift = 0;

	while ((pos = this->find(_str)) != -1) {

		while (str[pos + strlen(_str)+shift] != '\0') {
			str[pos + shift] = str[pos + strlen(_str)+shift];
			shift++;
		}
		str[pos + shift] = '\0';
		shift = 0;
		pos = 0;
	}
}

void myString::concatenateBack(char* _str) {
	char* temp = new char[strlen(str) + strlen(_str) + 1];
	temp[strlen(str) + strlen(_str)] = '\0';

	strcpy(temp, str);
	strcpy(temp + strlen(str), _str);

	delete[] str;
	str = temp;
}

void myString::concatenateFront(char* _str) {
	char* temp = new char[strlen(str) + strlen(_str) + 1];

	temp[strlen(str) + strlen(_str)] = '\0';
	strcpy(temp, _str);
	strcpy(temp + strlen(_str), str);

	delete[] str;
	str = temp;
}