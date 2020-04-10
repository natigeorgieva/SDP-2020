#include <iostream>
#include <queue>
#include <string>


/**
	Фунцкия, която проверява дали един символен низ се
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
	Фунцкия, която конвертира даден символен низ в целочислена стойност

	@param[in] s Входния низ

	@returns   Връща числото в символния низ като целочислена данна
*/
int toInteger(std::string s) {
	int num = 0; ///Текущото число

	for (int i = 0; i < s.length(); i++) {
		num = 10 * num + (s[i] - '0');	///Умножаваме ткущото число с 10 и го събираме с текущата цифра
	}

	return num;

}


/**
	фунцкия, която въвежда в реферирана опашка от цели числа,
	докато не се въведе нещо, което не е цяло число

	@param[in, out] q Подадена опашка, в която пълним цели числа

*/
void inputQueue(std::queue<int>& q) {
	std::string input;  ///Низ, в който пазим текущия вход от клавиатурата

	while(1) {
		std::cin >> input;		///Извличаме от потока низ

		if (isInteger(input)) {			///Ако извлечения низ е число
			q.push(toInteger(input));   ///Преобразуваме го в такова и го слагаме в опашката
		}
		else {							///В противен случай терминираме функцията
			return;
		}
	}
}


///Фунцкия принтираща опашкана екрана. За по-подробно обяснение се консултирайте с
///решените примери от предишното упашнение
void outputQueue(std::queue<int> q) {

	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
}

///Фунцкия сортираща дадена опашка в други две
void sortMod2(std::queue<int> q, std::queue<int>& even, std::queue<int>& odd) {

	while (!q.empty()) {
		if (q.front() % 2) {
			odd.push(q.front());
		}
		else {
			even.push(q.front());
		}
		q.pop();
	}
}

int main() {
	/**
	std::cout << toInteger("1234")<<'\n';
	std::cout << toInteger("999") << '\n';
	std::cout << isInteger("asd") << '\n';
	std::cout << isInteger("999") << '\n';
	*/

	std::queue<int> q, e, o;
	inputQueue(q);
	outputQueue(q);

	sortMod2(q, e, o);

	std::cout << "\nEven : ";
	outputQueue(e);

	std::cout << "\nOdd : ";
	outputQueue(o);

}
