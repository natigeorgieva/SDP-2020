#include <iostream>
#include <list>

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
    Фунцкия изпълняваща условието от задачата
*/
void insertN(std::list<int>& l, int pos, int val, bool f){
    ///Ако позицията преминава броя елементи
    ///Cast-ваме l.size() към int, защото е от usnigned int, а това преобразува
    ///pos в unsigned int, което води до логически грешки, когато е отрицателно
    if(pos > (int)l.size()){
        l.push_back(val);
        return;
    }


    ///Ако е отрицателно
    if(pos <= 0){
        l.push_front(val);
        return;
    }

    ///Щом трябва да пъхнем елемент в списъка си създаваме итератор, с който да го обхождаме
    ///докато намерим търсения елемент
    std::list<int>::iterator itr = l.begin();

    for(int i = 0; i < pos; i++) itr ++;


    ///Ако сме задали f == true, то пъхаме стойността пред позицията на итератора (вижте как работи insert)
    if(f){
        l.insert(itr,val);
    }else{
        ///В противен случай увеличаваме итератора с едно и пъхаме преди текущия елемент
        itr++;

        l.insert(itr,val);
    }
}

int main() {

	std::list<int>  list1;

	std::cout << "Enter List: ";
	inputList(list1);

	insertN(list1, -5, 999, 1);
	insertN(list1, 5, 888, 0);
	insertN(list1, 5, 777, 1);
	insertN(list1, 15, 666, 1);

	printList(list1);


}
