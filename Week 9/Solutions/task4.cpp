#include <iostream>
#include <string>
#include <list>


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
void printList(std::list<int> l) {
	std::list<int>::iterator i = l.begin();

	while (i != l.end()) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}

/**
	Функцията изискана от задачата
*/
std::list<int> filterSum(std::list<std::list<int>> l) {
	std::list<std::list<int>>::iterator itrLL = l.begin(); //Взимаме итератор към главния списък от списъци

	while (itrLL != l.end()) {//Обхождаме го до края на списъка

		std::list<int>::iterator itrL = (*itrLL).begin();//Взимаме си итератор към текущия подсписък

		//Обхождаме подсписъка до края
		while (itrL != (*itrLL).end()) {

			//Ако намерим отрицателно число в подсписъка
			if (*itrL <= 0) {
				std::list<int>::iterator temp = --itrL; //Запазваме итератор към предишния елемент от списъка, защото като изтрием текущия елемент ще изгубил връзката
				(*itrLL).erase(++itrL); //Връщаме си стария итератор на текущата позиция и изтрива елемента

				itrL = temp; // Присвояваме на итератора запазения преден итератор
			}

			itrL++; //Преместваме итератора на подсписъка към следващия елемент
		}

		itrLL++; //Преместваме итератора на списъка от списъци към следващия елемент
	}

	std::list<int> res; //Създаваме си реазултатния списък
	itrLL = l.begin(); //Връщаме си итератора към началото

	while (itrLL != l.end()) {
		int sum = 0;
		std::list<int>::iterator itrL = (*itrLL).begin();

		while (itrL != (*itrLL).end()) {
			sum += *itrL;//Сумираме си елементите на подсписъка
			itrL++;
		}

		res.push_back(sum); //Слагаме сумата в резултатния списък

		itrLL++;
	}

	return res;
}


int main() {
	std::list<std::list<int>> l;

	for (int i = 0; i < 3; i++) {
		l.push_back(std::list<int>());

		inputList(l.back());
	}

	std::list<int> res = filterSum(l);
	printList(res);
}

/***
1 -1 10 9 2 0
4 -18  90 -199 0
1 2 3 0
*/
