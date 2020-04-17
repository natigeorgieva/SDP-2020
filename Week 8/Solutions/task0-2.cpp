#include <iostream>
#include <queue>
#include <string>
#include <algorithm>


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
	функция, която въвежда в реферирана опашка от цели числа,
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


///Функция принтираща опашкана екрана. За по-подробно обяснение се консултирайте с
///решените примери от предишното упашнение
void outputQueue(std::queue<int> q) {

	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
}

std::queue<int> sumQueues(std::queue<int> q1, std::queue<int> q2) {
	std::queue<int> output;

	int maxSize = std::max(q1.size(), q2.size());

	for (int i = 0; i < maxSize; i++) {
		output.push(q1.front() + q2.front());

		q1.push(q1.front());
		q2.push(q2.front());

		q1.pop();
		q2.pop();
	}


	return output;
}




int main() {

	std::queue<int> q1, q2;
	inputQueue(q1);
	inputQueue(q2);

	outputQueue(sumQueues(q1, q2));
}
