#include <iostream>
#include <string>
#include <list>

/**
	Функция, която въвежда елементи в свързан списък с две
	връзки. Въведените елементи се вкарват в края на списъка.

	@param[in, out] l свързания списък с една връзка
*/
void inputListF(std::list<float>& l) {
	std::string s;

	while (1) {
		std::cin >> s;

		if (std::stof(s) != 0) {
			l.push_back(std::stof(s));
		}
		else {
			break;
		}
	}
}

void inputList(std::list<int>& l) {
	std::string s;

	while (1) {
		std::cin >> s;

		if (std::stoi(s) != 0) {
			l.push_back(std::stoi(s));
		}
		else {
			break;
		}
	}
}

/**
	Фунцкия, която принтира свързан списък с две връзки в правилен ред
*/
void printList(std::list<float> l) {
	std::list<float>::iterator i = l.begin();

	while (i != l.end()) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}

/**
	Функцията изискана от задачата
*/
void removeElements(std::list<float>& L1, std::list<int> L2) {
	std::list<int>::iterator itr2 = L2.begin();		//Взимаме итератор към списъка от индекси

	//Докато не сме стигнали до края на списъка от индекси
	while (itr2 != L2.end()) {

		//Ако индекса е валиден
		if (*itr2 > 0 && *itr2 <= (int)L1.size()) {
			std::list<float>::iterator itr = L1.begin(); //Взимаме интератор към списъка със стойности
			for (int i = 1; i < *itr2; i++) { //Преместваме итератора на търсената позиция
				itr++;
			}

			std::cout << *itr << " "; //Изписваме стойността на текущата позиция
		}

		itr2++; //преместваме итератора към списъка от индекси на следващата клетка
	}
}

int main() {
	std::list<float>  L1;
	std::list<int>    L2;

	std::cout << "Enter List 1: ";
	inputListF(L1);

	std::cout << "Enter List 2: ";
	inputList(L2);

	removeElements(L1, L2);

}
