#include <iostream>
#include <forward_list>
#include <list>

template<class T>
using flist = std::forward_list<T>;


/**
	Функция, която проверява дали един символен низ се
	състои само от цифри

	@param[in] s Входния низ

	@returns   Връща true, ако е изпълнено условието, в
			   противен случай false
*/
bool isInteger(std::string s) {
	bool state = true;		///Флаг, с който означаваме дали текущия низ съдържа само цифри

	for (int i = 0; state && i < s.length(); i++) {
		if (!isdigit(s[i])) {		///Ако намерим символ различен от цифра сваляме флага
			state = false;
		}
	}

	return state;
}


/**
	Функция, която конвертира даден символен низ в целочислена стойност

	@param[in] s Входния низ

	@returns   Връща числото в символния низ като целочислена данна
*/
int toInteger(std::string s) {
	int num = 0; ///Текущото число

	for (int i = 0; i < s.length(); i++) {
		num = 10 * num + (s[i] - '0');	///Умножаваме текущото число с 10 и го събираме с текущата цифра
	}

	return num;

}


/**
	Функция, която въвежда елементи в свързан списък с една
	връзка. Въведените елементи се вкарват в началото на списъка.

	@param[in, out] l свързания списък с една връзка
*/
void inputFlist(flist<int>& l) {
	std::string s;

	while (1) {
		std::cin >> s;

		if (isInteger(s)) {
			l.push_front(toInteger(s)); ///Нямаме опция да пъхаме елементи отзад
		}
		else {
			break;
		}
	}
}


/**
	Функция, която въвежда елементи в свързан списък с две
	връзки. Въведените елементи се вкарват в края на списъка.

	@param[in, out] l свързания списък с една връзка
*/
void inputList(std::list<int>& l) {
	std::string s;

	while (1) {
		std::cin >> s;

		if (isInteger(s)) {
			l.push_back(toInteger(s)); ///Можем да пъхаме елементи на последната след позиция
		}
		else {
			break;
		}
	}
}

/**
	Функция, която принтира свързан списък с една връзка на екрана
	започвайки от началото.
*/
void printFlist(flist<int> l) {
	flist<int>::iterator i = l.begin(); ///Създаваме итератор, с който обхождаме списъка

	///Докато итератора не стигне до края на списъка
	while (i != l.end()) {
		std::cout << *i << " ";///Принтираме стойността на клетката
		i++;                   ///Преместваме итератора на следващата клетка
	}
	std::cout << std::endl;
}

/**
    Рекурсивна функция, която принтира свързан списък с една връзка в
    обратна посока.
*/
void iterateBackFlist(flist<int>& l, flist<int>::iterator i) {
	///Дъното е достигнато, когоато итератора стигне края на списъка
	if (i == l.end()) {
		return;
	}

	///Запазваме стойността на текущата клетка
	int val = *i;

	i++;                        ///Преместваме итератора на следващата клетка
	iterateBackFlist(l, i);     ///Извикваме същата функция

	std::cout << val << " ";    ///Когато се връщаме от горноизвиканата функция, изписваме стойността на клетката
}


/**
    Функция, която задава начална стойност на итератора използван
    за принтиране на списъка и стартира рекурсивното извеждане
*/
void printBackFlist(flist<int> l) {
	flist<int>::iterator i = l.begin();

	iterateBackFlist(l, i);

	std::cout << std::endl;
}


/**
    Фунцкия, която принтира свързан списък с две връзки в правилен ред
*/
void printList(std::list<int> l) {
	std::list<int>::iterator i = l.begin();

	while (i != l.end()) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}

/**
    Фунцкия, която принтира свързан списък с две връзки в обратен ред
*/
void printBackList(std::list<int> l) {
	std::list<int>::reverse_iterator i = l.rbegin();  ///Еквивалетно като предишните обхождания, но и използваме итератор, който обхожда списъка наобратно

	while (i != l.rend()) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}

int main() {
	flist<int> list1;		///forward_list<int> list1;
	std::list<int>  list2;

	std::cout << "Enter Flist: ";
	inputFlist(list1);

	std::cout << "Enter List: ";
	inputList(list2);

	std::cout << "Printing Flist forwards: ";
	printFlist(list1);

	std::cout << "Printing Flist backwards: ";
	printBackFlist(list1);

	std::cout << "Printing List forwards: ";
	printList(list2);

	std::cout << "Printing List backwards: ";
	printBackList(list2);
}


