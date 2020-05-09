#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

struct Employee {
	std::string name;
	int id;
	float salary;

	///Конструктори с инициализиращ списък (това след двуеточието)
	Employee():name("default"), id(0), salary(0){};
	Employee(std::string _name, int _id, float _salary):name(_name), id(_id), salary(_salary) {};
};


///Предефинираме си оператора за изход към обект от ostream за подаден обект от 
std::ostream& operator<<(std::ostream& os, Employee e) {
	os << "Name: " <<std::setw(20)<< e.name << " ID: " << std::setw(5) << e.id << " Salary: " << std::setw(5) << e.salary << std::endl;
	return os;
}

///Предефинираме си и оператора за запис към файл
std::fstream& operator<<(std::fstream& ofs, Employee& e) {
	ofs << e.name << '\n' << e.id << '\n' << e.salary << '\n';

	return ofs;
}

///Следващите два опеартора са предефинирани за извличане от потоци от istream и ostream

///Дирекнтно подаваме референция към обекта, който ще използваме да запазим данните от файла
std::istream& operator>>(std::istream& is, Employee& e) {
	std::getline(is, e.name);
	is >> e.id >> e.salary;
	is.ignore();

	return is;
}


std::fstream& operator>>(std::fstream& ifs, Employee& e) {
	std::getline(ifs, e.name);
	ifs >> e.id >> e.salary;
	ifs.ignore();

	return ifs;
}




template<class T>
void inputList(std::list<T>& l) {
	T input;

	///Въвеждаме докато не получим несъответсвие на типовете данни
	///Тогава ще се вдигне флага failbit (или някой друг флаг за грешка), който предотвратява изтеглянето
	///на информация от потока докато не се свали
	while (std::cin >> input) {
		l.push_back(input);
	}

	std::cin.clear(); ///Сваляме всички флагове, за да може да си ползваме потока без проблем
}

template<class T>					///template<typename T> typename и class в констекста на шаблони са едно и също
void outputList(std::list<T> l) {
	///Но в случая, когато искаме да създадем обект зависещ от този тип, както сега за итератора
	///трябва да използваме typename, за да подскажем на компилатора, че зависи от нещо друго, а не е обикновена структура или тип данни
	typename std::list<T>::iterator it = l.begin();

	std::cout << std::left;

	while (it != l.end()) {
		std::cout << *it;
		it++;
	}
}


int main() {
	std::list<Employee> dataList; ///В този списък ще съхраняваме информацията извлечена от файла

	///Отваряме файла за четене от него
	std::fstream data("data.txt", std::ios::in);

	Employee inptEm; ///Това ще ни е обекта, който ще ползваме, за да запомним информацията за един запис от файла

	///Докато не сме стигнали края на файла
	while (!data.eof()) {
		data >> inptEm;///си въвеждаме в обекта данни от файла
		dataList.push_back(inptEm);///и записваме новите данни в списъка
	}

	std::cout << "After reading file...\n";
	outputList(dataList);

	inputList(dataList); ///Сега вкарваме нови обекти в списъка

	std::cout << "After user input file...\n";
	outputList(dataList);

	data.close(); ///Понеже ще използваме потока за друг файл, затваряме текущия свързан с него

	///Отваряме си нов файл, в който ще запишем резултата от нашето въвеждане, т.е. прочетените преди обекти и новите, които ние сме въвели от клавиатурата
	data.open("result.txt", std::ios::out | std::ios::trunc);

	std::list<Employee>::iterator it = dataList.begin(); 

	///Ще запишем всеки един елемент от списъка във резултатния файл
	while (it != dataList.end()) {
		data << *it;
		it++;
	}
}