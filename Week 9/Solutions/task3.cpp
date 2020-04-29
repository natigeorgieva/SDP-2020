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
	
	//Логиката е почти еквивалентна на тази от задача 2
	std::list<int>::iterator itr2 = L2.begin();

	while (itr2 != L2.end()) {
		bool flag = false; //Този път си създаваме флаг с който ще означим дали сме изтрили елемент


		if (*itr2 > 0 && *itr2 <= (int)L1.size()) {
			std::list<float>::iterator itr = L1.begin();
			for (int i = 1; i < *itr2; i++) {
				itr++;
			}
			flag = true;   //Вдигаме флага
			L1.erase(itr); //Трием елемента на тази позиция
		}

		//Тук е глвното, което се различава от 2ра задача. Понеже сме "изместили" (по-скоро сме намалили техния пореден номер с 1) всички елементи от изтрития надясно
		//с едно на наляво то  ще вземем да обходим списъка с индекси от там където сме стигнали до края и на всякъде където има индекс по-голям от текущия ще го намалим с 1
		std::list<int>::iterator itr = itr2; 

		
		while (flag && itr != L2.end()) {
			if (*itr > * itr2) (*itr)--;
			itr++;
		}

		itr2++;
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

	printList(L1);
}
