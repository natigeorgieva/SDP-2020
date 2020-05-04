#include <iostream>
#include <list>

/**
	Тестова структура, с която ще покажем как една шаблонна функция
	може да работи със всякакъв тип данни*
*/
struct Rect {
	float w, h;
};


/**
	Предефинираме си операторите за нашата структура, защото
	шаблонните функции го изискват
*/
std::ostream& operator<<(std::ostream& os, Rect r) {
	os << "Widht: " << r.w << " Height: " << r.h << '\n';

	return os;
}

std::istream& operator>>(std::istream& is, Rect& r) {
	is >> r.w >> r.h;

	return is;
}


template<class T>
void inputList(std::list<T>& l) {
	T input;

	//Въвеждаме докато не получим несъответсвие на типовете данни
	//Тогава ще се вдигне флага failbit (или някой друг флаг за грешка), който предотвратява изтеглянето
	//на информация от потока докато не се свали
	while (std::cin >> input) {
		l.push_back(input);
	}

	std::cin.clear(); //Сваляме всички флагове, за да може да си ползваме потока без проблем
}

template<class T>					//template<typename T> typename и class в констекста на шаблони са едно и също
void outputList(std::list<T> l) {
	//Но в случая, когато искаме да съзададем обект зависещ от този тип, както сега за интератора
	//трябва да използваме typename, за да подскажем на компилатора, че зависи от нещо друго, а не е обикновена структура или тип данни
	typename std::list<T>::iterator it = l.begin(); 


	while (it != l.end()) {
		std::cout << *it << " ";
		it++;
	}
}

int main() {
	std::list<int> listInt;
	std::list<Rect> listRect;

	inputList(listRect);

	outputList(listRect);

	std::cin.ignore();

	inputList(listInt);

	outputList(listInt);
}
