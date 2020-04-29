#include "BigInt.h"
#include <string.h>
#include <string>
#include <algorithm>

/*** Голямата четворка ***/

BigInt::BigInt() {
	arrSize = 10;
	currSize = 2;
	base = 10;
	sign = false;

	str = new char[arrSize];
	strcpy_s(str, arrSize, "0");
}

BigInt::BigInt(const BigInt& bi) {
	str = nullptr;

	copy(bi);
}

BigInt::BigInt(usint n, lint num) {
	arrSize = 10;
	currSize = 0;
	base = n;
	sign = (num < 0 ? true : false);

	num = abs(num);

	str = new char[arrSize];

	if (num == 0) {
		strcpy_s(str, arrSize, "0");
		currSize = 1;
	}

	while (num != 0) {
		if (currSize + 1 >= arrSize) {
			resize();
		}

		str[currSize] = toChar(num % base);
		num /= base;

		currSize++;
	}

	str[currSize] = '\0';
	currSize++;
}

BigInt& BigInt::operator=(const BigInt& bi) {
	if (this == &bi) {
		return *this;
	}

	copy(bi);

	return *this;
}

/************************/

//========================================================================================

/***     Оператори    ***/

BigInt BigInt::operator+(const BigInt& bi) {
	BigInt left, right, // Тук ще запишем копие на подадените числата, за да не променяме оригиналите, когато се налага това 
		res;			// Тук ще запишем резултата от нашата операция

	int p = this->base - bi.base; // Гледаме каква е разликата на двете бройни системи

	//В следващите блокове правим нужните привеждания към по-ниската система
	//Ако и двете са еднакви не пипаме нищо
	if (p == 0) {
		left = *this;
		right = bi;
	}
	//Или бр. сист. на левия операнд е по-малка, привеждаме десния
	else if (p < 0) {
		left = *this;
		right = bi.toDec().toBase(base);
	}
	//Или бр. сист. на десния операнд е по-малка, привеждаме левия
	else {
		left = this->toDec().toBase(bi.base);
		right = bi;
	}

	//Ако двете числа са с еднакъв знак, то тяхната сума ще е равна на сумата по модул и техния общ знак
	if (sign == bi.sign) {
		res = sumAbs(right);
		res.sign = sign;
	}
	//В противен случай
	else {
		res = subAbs(right); // Изваждаме двете числа по модул

		//И преценяваме какъв ще е знака на резултата

		//Ако левия операнд е по-голям по модул значи взимаме негови знак
		if (cmpAbs(right) == 1) {
			res.sign = sign;
		}
		//В противен случай взимаме знака на десния
		else {
			res.sign = bi.sign;
		}
	}

	return res;
}

BigInt BigInt::operator+(lint num) {
	BigInt right(10, num); //Привеждаме десния операнд на обект 

	//И си използваме вече реализирания оператор+ за два обекта
	return *this + right;
}

BigInt operator+(lint num, const BigInt& bi) {
	//Еквивалентно на горния оператор
	BigInt left(10, num);

	return left + bi;
}

BigInt BigInt::operator-(const BigInt& bi) {
	// Тук повечето логика е еквивалентна на оператор+, но има допълнителни неща защото изваждането не е комутативно

	BigInt left, right, res;

	if (this->base < bi.base) {
		left = *this;
		right = bi.toDec().toBase(base);
	}
	else {
		left = this->toDec().toBase(bi.base);
		right = bi;
	}


	//Ако и двете числа са с различни знаци 
	if ((sign && !bi.sign) || (!sign && bi.sign)) {
		//То взимаме тяхната сума по модул
		res = left.sumAbs(right);
		//И взимаме знака на левия операнд
		res.sign = sign;
	}
	//В противен случай, т.е са с еднакви знаци
	else {
		int a = left.cmpAbs(right); //Сравняваме двете числа по модул

			//Ако лявото е по голямо от дясното взимаме знака на левия операнд и тяхната разлика по модул
		if (a == 1) {
			res = left.subAbs(right);
			res.sign = sign;
		}
		//Ако са равни то разликата на две еднакви числа е нула
		else if (a == 0) {
			return BigInt(left.base, 0);
		}
		else {
			res = left.subAbs(right);
			res.sign = !sign;
		}

	}


	return res;
}

//Логиката е еквивалентна като предишните оператори
BigInt BigInt::operator-(lint num) {
	BigInt right(10, num);

	return *this - right;
}

BigInt operator-(lint num, const BigInt& bi) {
	BigInt left(10, num);

	return left - bi;
}

BigInt BigInt::operator++() {
	BigInt inc(base, 1); //Щом ще увеличим числото с единица то най-лесно си създаваме едно число със същата основа, което е единица

	*this = *this + inc;

	return *this;
}

BigInt BigInt::operator++(int) {
	BigInt inc(base, 1), copy = *this;

	*this = *this + inc;

	return copy;
}

BigInt BigInt::operator--() {
	BigInt inc(base, 1);

	*this = *this - inc;

	return *this;
}

BigInt BigInt::operator--(int) {
	BigInt inc(base, 1), copy = *this;

	*this = *this - inc;

	return copy;
}

std::istream& operator>>(std::istream& is, BigInt& bi) {
	int inptNum;
	usint inptBase;

	std::cout << "Enter base: ";
	is >> inptBase;
	std::cout << "Enter number: ";
	is >> inptNum;

	bi = BigInt(inptBase, inptNum);

	return is;
}

std::ostream& operator<<(std::ostream& os, BigInt bi) {
	if (bi.sign) os << "-";

	for (uint i = bi.currSize - 2;; i--) {
		os << bi.str[i];

		if (i == 0) break;
	}
	os << "(" << bi.base << ")" << std::endl;

	return os;
}

///************************/

//========================================================================================

/***     Помощни функции    ***/

void BigInt::resize() {

	try {
		if (arrSize > arrSize + 10) throw 1; // Ако прехвърлим горната граница на типа то това ще е фатално
	}
	catch (int a) {
		std::cout << "The limit of uint is reached when resising the array!\n"; //За това просто прекратяваме програмата, за да не станат други грешки, и уведомяваме потребителя
		throw;
	}

	//Ако всичко е точно си прилагаме deepcopy
	char* newStr = new char[arrSize + 10];

	strcpy_s(newStr, arrSize + 10, str);

	delete[] str;

	arrSize += 10;
	str = newStr;

}

void BigInt::copy(const BigInt& bi) {
	if (str != nullptr) {
		delete[] str;
		str = nullptr;
	}

	try {
		//Ако има разминаване от това какво е запазено в указателя и това колко елемента има в масива чупим програмата,
		//за да уведомим потребителя, че има нещо нередно. Правя го, за да си спестя нерви по време на създаване на 
		//програмата, ако нещо не работи както трябва
		if (bi.arrSize != 0 && bi.str == nullptr)throw 1; 
	}
	catch (int a) {
		std::cout << "Object has size != 0 but the pointer isn't set!!";
		throw;
	}

	arrSize = bi.arrSize;
	currSize = bi.currSize;
	base = bi.base;
	sign = bi.sign;

	str = new char[arrSize];
	strcpy_s(str, arrSize, bi.str);
}

char BigInt::toChar(usint id)const {
	if (id >= 0 && id < 10) {
		return '0' + id;
	}
	else if (id >= 10 && id < 16) {
		return 'A' + id - 10;
	}
	else {
		std::cout << "Illegal int : " << id << std::endl;
		exit(1);
	}
}

usint BigInt::toInt(char id)const {
	if (id >= '0' && id <= '9') {
		return id - '0';
	}
	else if (id >= 'A' && id <= 'F') {
		return id - 'A' + 10;
	}
	else {
		std::cout << "Illegal char : " << id << std::endl;
		exit(1);
	}
}

///1 - левия > десния
///0 - левия == десния
///-1 - левия < десния
///Сравняваме само число с една и съща база!!
int BigInt::cmpAbs(const BigInt& bi) {
	///Ако лявото число е по късо от дясното очевидно то ще е по-малко
	if (currSize < bi.currSize) {
		return -1;
	}
	///Еквивалентно за обратното
	else if (currSize > bi.currSize) {
		return 1;
	}


	///Ако са равни то сравняваме поцифрено от дясно на ляво, защото така записваме числото
	for (uint i = currSize - 2;; i--) {
		usint diff = toInt(str[i]) - toInt(bi.str[i]);

		if (diff > 0) {
			return 1;
		}
		else if (diff < 0) {
			return -1;
		}

		if (i == 0) {
			return 0;
		}
	}
}

///Вижте реализацията от Week6 BigInt
BigInt BigInt::sumAbs(const BigInt& bi) {
	BigInt res;

	uint minSize = (currSize > bi.currSize ? bi.currSize : currSize) - 1;


	res.base = base;

	usint sum = 0;
	uint i = 0;
	for (; i < minSize; i++) {
		sum += toInt(str[i]) + toInt(bi.str[i]);

		if (i + 1 >= res.arrSize) {
			res.resize();
		}

		res.str[i] = toChar(sum % base);
		sum /= base;
	}

	for (; i < currSize - 1; i++) {
		sum += toInt(str[i]);

		if (i + 1 >= res.arrSize) {
			res.resize();
		}

		res.str[i] = toChar(sum % base);
		sum /= base;
	}

	for (; i < bi.currSize - 1; i++) {
		sum += toInt(bi.str[i]);

		if (i + 1 >= res.arrSize) {
			res.resize();
		}

		res.str[i] = toChar(sum % base);
		sum /= base;
	}

	if (sum) {
		if (i + 1 >= res.arrSize) {
			res.resize();
		}

		res.str[i] = toChar(sum);
		i++;
	}

	res.str[i] = '\0';
	res.currSize = i + 1;
	return res;
}

BigInt BigInt::subAbs(const BigInt& bi) {
	BigInt subt, min;

	int a = this->cmpAbs(bi);

	///Следващите проверки служат, за да нагласим умаляемото да е по-голямото число
	if (a == 0) {
		return BigInt(base, 0);
	}
	else if (a == -1) {
		subt = bi;
		min = *this;
	}
	else {
		subt = *this;
		min = bi;
	}

	///Обхождаме умалителя
	for (usint i = 0; i < min.currSize - 1; i++) {
		///Ако текущата цифра на умаляемото е по-голямо от цифрата на умалителя
		///то намираме коя от  следващите цифри е различна от нула, взимаме й една единица
		///разпределяме на предишните 0ли, ако има, base - 1, и тогава намираме разликата 
		if (toInt(min.str[i]) > toInt(subt.str[i])) {
			uint j = i  // Позицията на последната нула
				, steps = 0; // броя нули, преди да стигнем до цифра различна от 0

			while (toInt(subt.str[j]) == 0) { //Ако цифрата е нула си увеличаваме броячите
				j++;
				steps++;
			}

			//Когато стигнем до цифра различна от 0ла намаляваме с 1
			subt.str[j] = toChar(toInt(subt.str[j]) - 1);

			//Ако е имало нули по пътя разпределяме взетото от предишната цифра
			while (steps > 0) {
				subt.str[j] = toChar(base - 1);
				steps--;
				j--;
			}

			//намираме разликата на текущите цифри + прибавеното
			subt.str[i] = toChar(toInt(subt.str[i]) + base - toInt(min.str[i]));
		}
		//В противен случай прости си изваждаме двете числа
		else {
			subt.str[i] = toChar(toInt(subt.str[i]) - toInt(min.str[i]));
		}
	}

	//Понеже при ваденето е възможно да се получат водещи нули ще ги премахнем, за да не пречат на бъдещи изчисления
	while (subt.str[subt.currSize - 2] == '0') {
		subt.str[subt.currSize - 2] = '\0';
		subt.currSize--;
	}

	//Връщаме резултатното чило, но по модул, със знаците се разправяме при операторите, за да не се натрупват много операции във една функция
	return subt;
}

BigInt BigInt::toDec()const {
	///Принципно е изключително лесно да се преобразува от една система в друга
	///като умножаваме всяка цифра с базата на определената степен, но в тази реализация
	///можем да стигаме до степен от няколко хиляди и това не ни позволява да използваме вградените типове
	///за това ще използваме просто обект от този тип и степенуването ще го представим като
	///поредици от умножения
	BigInt res;				///резултата	
	BigInt currPower(10, 1);///текущата степен

	for (uint i = 0; i < currSize - 1; i++) {

		for (usint j = 0; j < toInt(str[i]); j++) { ///Събираме си базата толкова пъти колкото е цифрата, т.е. ги умножаваме
			res = res + currPower;
		}

		BigInt temp = currPower; ///Пазим си копие на текущата база

		///Събирайки текущата степен със себе си колкото е големината на базата намираме следващата степен
		for (int j = 0; j < base - 1; j++) {
			currPower = currPower + temp;
		}
	}

	//Връщаме резултата
	return res;

}

BigInt BigInt::toBase(usint base)const {
	///За да превърнем едно число от десетична система в някой друга се извършват просто
	///последователни деления по модул и целочислени. Отново няма да ни свърши работа
	///да преобразуваме числото в някое от типовете вградени в c++, ние ще постъпим по хитър начин
	///Числото на което ще делим го знаем то е базата. А делимото ще го образуваме на всяка стъпка
	///Така алгоритъма, който ще реализираме е деление с опашка

	usint sum = 0; ///текущото число за деление
	uint pos = 0; ///Текущата позиция

	///Ще използваме стринг, за да не усложняваме алгоритъма с използване на динамична памет
	///Понеже и нашата структура и string могат да съхраняват един низ с максимална дължина, която е една и съща
	///това няма да доведе до проблем при конвертирането от единия тип в другия
	std::string result = ""; ///Резултатното число
	std::string currNum(str); /// Копираме си нашето число 
	std::string nextNum = ""; ///цялата част получена при текущото деление

	///Докато числото, което делим е различно от "0"
	while (currNum != "0") {

		//С този цикъл реализираме делението с опашка, като на всяка стъпка сваляме цифра от делимото
		//и го добавяме към опашката. След това делим на делителя и цялата част отива в резултата, а модулната
		//част си остава в опашката
		for (uint i = currNum.length() - 1;; i--) {
			sum = sum * 10 + toInt(currNum[i]); ///Добавяме новата цифра към опашката

			nextNum += toChar(sum / base);///записваме си цялата част от делението
			sum %= base; ///Оставяме си модулната в опашката


			if (i == 0) break; ///Когато свършат цифрите от делимото прекратяваме опашката
		}

		result += toChar(sum);  ///Остатъка по модул го добавяме към резултата
		sum = 0;				///нулираме текущата опашка
		currNum = nextNum;		///Запазваме новополученото число, като новото число, което ще делим
		nextNum = ""; ///и си зануляваме резултата
		///Премахваме получените водещи нули
		currNum.erase(0, std::min(currNum.find_first_not_of('0'), currNum.size() - 1));
		std::reverse(currNum.begin(), currNum.end());///Обръщаме числото да е реда, който ни върши работа

	}

	///Създаваме си резултатния обект и присвояваме нужните стойности
	BigInt res;

	res.base = base;
	delete[] res.str;


	res.currSize = result.length() + 1;
	res.str = new char[result.length() + 10];
	res.arrSize = result.length() + 10;
	strcpy_s(res.str, result.length() + 10, result.c_str());

	return res;
}

/******************************/