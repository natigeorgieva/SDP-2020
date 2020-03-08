#pragma once

#include <string>

class Film {
	std::string name;		///Името на филма
	float* score;		    ///Указател, който ще съдържа адреса на динамично заделената памет за оценките
	int scoreSize,			///Броя текущи оценки
		arrSize;			///Текущия размер на масива

	///Член фунцкии, които искаме да ползваме само в класа без да може някой друг да ги използва
	///извън него
	void nullify(bool checkMem);
	void resize();
	void copy(const Film& _f);

public:
	Film();
	Film(const Film& _f);
	~Film();
	Film& operator=(const Film& _f);

	Film& operator+(float r);
	friend Film& operator+(float r, Film& f);

	friend std::ostream& operator<<(std::ostream& os, const Film& f);

	bool operator>=(const Film& f) const;

	float average() const;
	void setName(std::string _name);
};