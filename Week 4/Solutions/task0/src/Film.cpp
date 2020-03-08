#include "Film.h"
#include <ostream>

/***
	Фунцкия, която занулява даден обект. Ако checkMem е нула то 
	укзателя не се проверява за нулев и не се трие (Ако му подадем
	туко що съзаден обект и не сме занулили указателя то очевидно
	дори и да има стойност в този указател тя няма да е адрес на 
	клетка от heap-a и ако я изтрием програмата ще гръмне)

	@param[in] checkMem Флаг с който контролираме дали да приложим
						delete върху указателя

*/
void Film::nullify(bool checkMem = 0) {
	if (score != nullptr&&!checkMem) {
		delete[] score;
	}

	name = "";
	score = nullptr;
	scoreSize = 0;
	arrSize = 0;
}

/**
	Функиця, която увеличава размера на масива с оценки
*/
void Film::resize() {
	arrSize += 10;

	float* temp = new float[arrSize];

	///Ако текущи указател сочи към нещо
	if (score != nullptr) {
		for (int i = 0; i < scoreSize; i++) {
			temp[i] = score[i];
		}

		delete[] score; ///трием стария масив
	}

	///Записваме адреса на новия заделен динамично масив в указателя
	score = temp;
	
}


/**
	Фунцкия, която копира съдържанието на _f в дадения обект

	@param[in] _f подадения обект за копиране
*/
void Film::copy(const Film& _f) {
	name = _f.name;

	if (_f.score != nullptr) {
		scoreSize = _f.scoreSize;
		arrSize = _f.arrSize;

		score = new float[arrSize];

		for (int i = 0; i < scoreSize; i++) {
			score[i] = _f.score[i];
		}
	}
	else {
		scoreSize = 0;
		arrSize = 0;
	}
}

///Default-ен конструктур
Film::Film() {
	this->nullify();
}

///Copy конструктур
Film::Film(const Film& _f) {
	this->nullify();
	this->copy(_f);
	
}

///Desctruct-ор
Film::~Film() {
	delete[] score;
}

/**
	Предефениране на оператор =.

	@param[in] _f обекта, който ще присвояваме

	@return Връща текущи обект върху, който е приложен оператора =
*/
Film& Film::operator=(const Film& _f) {
	this->nullify(1);
	this->copy(_f);

	return *this;
}

/**
	Предефениране на оператор +, който се прилафа върху обект от Film

	@param[in] r стойността, която да добавим в масива с оценки

	@return Връща текущия обект върху, който е приложен оператора
*/
Film& Film::operator+(float r) {
	if (scoreSize + 1 >= arrSize) {
		this->resize();
	}

	score[scoreSize] = r;
	scoreSize++;

	return *this;
}

/**
	Предефениране на оператор +, който се прилафа върху променлива от float

	@param[in] r стойността, стояща отляво на оператора, която да добавим в масива с оценки
	@param[in] _f обекта, който седи от дясно на оператора

	@return Връща текущия обект върху, който е приложен оператора
*/
Film& operator+( float r, Film& _f) {
	if (_f.scoreSize + 1 >= _f.arrSize) {
		_f.resize();
	}

	_f.score[_f.scoreSize] = r;
	_f.scoreSize++;

	return _f;
}


/**
	Предефиниране на оператора << за стандартния поток към екрана

	@param[in] os потота върху, който е приложен <<
	@param[in] f обекта, който седи от дясно на оператора

	@return Връща потока подаден на функцията
*/
std::ostream& operator<<(std::ostream& os, const Film& f) {

	os << "Name: " << f.name << "  Score: " << f.average() << std::endl;

	return os;
}



bool Film::operator>=(const Film& f) const {
	if (this->average() >= f.average()) {
		return true;
	}

	return false;
}

float Film::average() const {
	float sum = 0;

	for (int i = 0; i < scoreSize; i++) {
		sum += score[i];
	}

	return sum / scoreSize;
}

void Film::setName(std::string _name) {
	name = _name;
}