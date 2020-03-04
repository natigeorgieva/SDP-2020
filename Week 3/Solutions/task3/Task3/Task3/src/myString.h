#pragma once

class myString {
	char* str;
	int len;

public:
	myString();
	myString(char*);

	void setStr(char*);
	int cmp(char*);
	int find(char*);
	void deleteSubStr(char*);
	void concatenateBack(char*);
	void concatenateFront(char*);
	const char* getStr() { return str; }

};