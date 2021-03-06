#include "Bigint.h"
#include <algorithm>  /// min, max
#include <iostream>   /// ostream, istream


/**
	Конструктор по подразбиране за класа Bigint.
	Зануляваме ВСИЧКИ стойности на обекта
*/
Bigint::Bigint() {
	ptr = nullptr;
	size = 0;
	used = 0;
}

/**
	Копиращ конструктор за класа Bigint.
	Зануляваме указателя и прилагаме deepcopy
	върху обекта
*/
Bigint::Bigint(const Bigint& obj) {
	ptr = nullptr;
	this->copy(obj);
}

/**
	Предефиниране на оператора = за класа. Прилага
	deepcopy върху обекта и след това връща константна референция към него

	@param[in] obj Десния операнд
	
	@returns Константна референция към левия операнд
*/
const Bigint& Bigint::operator=(const Bigint& obj) {
	if (this == &obj) {
		return *this;
	}

	copy(obj);

	return *this;
}

/**
	Предефиниране на опеартора +. Той събира почленно 
	елементите на масива и ги записва в нов резултатен 
	обект. 

	@param[in] obj Десния операнд 
	@returns Нов обект който съдържа резултата от операцията

	@exceptsafe Ако някой от указателите на опрерандите е nullptr 
				функцията хвъря exeption
	@throws 1 Ако указателя на десния операнд е nullptr
	@throws 2 Ако указателя на Левия операнд е nullptr
*/
Bigint Bigint::operator+(const Bigint& obj) {

	///Tук правим проверки ако един от двата указателя е nullptr
	try {
		if (obj.ptr == nullptr) throw 1;
		if (ptr == nullptr) throw 2;
	}
	catch (int a) { ///Ако е такъв случая изписваме, кое първо се е счупило, изписваме на екрана и хвърляме грешката на останалите функции по стака
		if (a == 1) {
			std::cout << "Right operand cannot have unitialised array";
		}
		else {
			std::cout << "Left operand cannot have unitialised array";
		}

		throw;
	}

	///Ако всичко е точно и няма нещо, което да ни счупи работата на програмата си създаваме обекта,
	///в който пазим резултата
	Bigint result;

	///За новия обект взимаме размера на масива да е максималния от размерите на двата операнда,
	///а използвания размер да е максималния от използвания от двата операнда
	result.size = std::max(size, obj.size);
	result.used = std::max(used, obj.used);

	///Създаваме си новия динамичен масив
	result.ptr = new ushort[size];

	///sum ще ни пази текущия сбор на две от цифите на двата операнда
	ushort sum = 0;
	///Понеже брояча ще го използваме в няколко масива си го инициализираме извън тях
	unsigned int i = 0;

	///Събираме поцифрено двете чилса, следователно ще ги събираме до дължината на по-малкото от тях
	for (; i < std::min(used, obj.used); i++) {
		sum += ptr[i] + obj.ptr[i];			///Взимаме сбора на двете текущи цифри и ги прибавяме към остатъка
		result.ptr[i] = sum % 10;		    ///Запазваме на текущата цифра последната от текущия сбор
		sum /= 10;							///Запазваме остатъка от текущия сбор
	}

	///В случая че едно от двте числа е по-дълго от другото
	///проверяваме кое от тях е и прибавяме неговите останали цифри 
	///към крайния резултат
	if (used > obj.used) {
		for (; i < used; i++) {
			sum += ptr[i];
			result.ptr[i] = sum % 10;
			sum /= 10;
		}
	}
	else if (used < obj.used) {
		for (; i < obj.used; i++) {
			sum += obj.ptr[i];
			result.ptr[i] = sum % 10;
			sum /= 10;
		}
	}

	///Ако в края на събиранията е останал остатък то го лепваме накрая и увеличаваме размера на числото с 1 
	if (sum != 0) {
		result.used++;
		result.ptr[i] = sum;
	}

	return result;
}

/**
	Предефиниране на оператор >>, който приема поток от istream
	и извлича първия симвомен подниз, който е от цифри, и го слага
	поелементно в масива на десния операнд

	@param[in, out] is Входния поток
	@param[in] obj Обекта в, който слагаме информацията от потока

	@returns Потока is
*/
std::istream& operator>>(std::istream& is,  Bigint& obj){
	///Ако указателя на обекта не занулен, осввобождаваме памметта рефериран от него
	///и го зануляваме
	if (obj.ptr != nullptr) {
		delete[] obj.ptr;
		obj.ptr = nullptr;
	}

	///зануляваме останалите стойности
	obj.size = 0;
	obj.used = 0;

	///Понеже може да се случи преди това да сме извличали от потока и да не сме премахнали
	///някой от символите спиращи неговото извличане го премахваме. Типичен случай, който сте
	///срещали е при използване на cin и getline един след друг
	if (is.peek() == ' ' || is.peek() == '\n') {
		is.get();
		is.clear();
	}

	///Докато следващия знак е цифра извличаме от потока
	while (isdigit(is.peek())) {

		///Ако размера на масива не е достатъчно голям го увеличавме
		if (obj.used + 1 >= obj.size) {
			obj.resize();
		}
		
		///присвояваме на текущата позиция извлечената цифра
		obj.ptr[obj.used] = is.get()-'0';
		obj.used++;
	}


	///Обръщаме масива понеже числото от потока го пълним наобратно в масива
	obj.rev();

	return is;
}


/**
	Предефинираме опратора <<, който приема поток за изход като ляв операнд и 
	обект, чиийто стойности предаваме на потока, като десен операнд

	@param[in, out] os	потока който използваме
	@param[in]		obj обекта, чиито стойности от неговия масив пращаме на потока

	@returns os
*/
std::ostream& operator<<(std::ostream& os, Bigint obj) {
	
	///Ако в обекта не е запазен масив, то няма какво да принтираме
	if (obj.ptr == nullptr) {
		return os;
	}

	///Пращаме стойностите на масива една по енда на потока
	for (unsigned int i = obj.used -1 ; i > 0 ;i--) {
		os << obj.ptr[i];
	}
	os << obj.ptr[0];
	return os;
}

/**
	Функция, която реализира deepcopy алгоритъм за обекти от класа

	@param[in] obj Обекта, чийто стойности че се копират "дълбоко" в нашия обект
*/
void Bigint::copy(const Bigint& obj) {
	///Копираме си обикновенните стойности
	size = obj.size;
	used = obj.used;

	///Ако указателя на приложения обект не е nullptr, то той сочи към нещо. 
	///Следователно освобождаваме паметта реферирана от него и го зануляваме
	if (ptr != nullptr) {
		delete[] ptr;
		ptr = nullptr;
	}
		
	///Ако подадения обект не пази някакаква референция към масив
	///То няма какво да копираме и приклкючваме
	if (obj.ptr == nullptr) {
		return;
	}

	///Заделяме си паметта и запазваме нейния първи адрес в указателя
	ptr = new ushort[size];

	///Копираме си само нужните стойности, а не неизползваната от нас част
	for (unsigned int i = 0; i < size; i++) {
		ptr[i] = obj.ptr[i];
	}

	return;
}

/**
	Функция, която увеличава размера на масива, като съзадава нов с по-голям
	размер, копира стойностите от стария масива, освобжодава стария масив и на негово
	място запаметява новия (запаметява го в указателя)
*/
void Bigint::resize() {
	ushort* temp = new ushort[(size+2) * 2]; ///Заделяме нов масив с по-голям рамер от стария и запаметяваме  неговия адрес в текущ указател
	size = (size + 2) * 2;	///Отразяваме промяна в размера и в променливата на обект, която пази неговия размер


	///Копираме поелементно стария масив в новия (само използваните от нас стойности)
	for (unsigned int i = 0; i < used; i++) {
		temp[i] = ptr[i];
	}

	///Зануляваме укзателя ако не е бил преди това. Обърмете внимание, че горе копираме елементи,
	///така че вие трябва да сте сигурни ваши код да не може да има несъответсвие спрямо размерите и дали е заделена памет
	if (ptr != nullptr) {
		delete[] ptr;
		ptr = nullptr;
	}

	ptr = temp; /// Запаметяваме новозаделения масив в обекта
}

///Функция която обръща масива на даден обект
void Bigint::rev() {
	for (unsigned int i = 0; i < used / 2; i++)
	{
		ushort temp = ptr[i];
		ptr[i] = ptr[used - 1 - i];
		ptr[used - 1 - i] = temp;
	}
}