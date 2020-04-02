#include <iostream>
#include <stack>


/**
	Функция, която по подадена РЕФЕРЕНЦИЯ към стек от цели числа
	въвежда в нея числа от клавиатурата докато не достигне 0

	@param[in] st референция към стек от цели числа
*/
void inputStack(std::stack<int>& st) {
	int input;		///Променливата, в която ще помним текущото въведено число от клавиатурата

	///Правим безкраен цикъл. Логиката, която ще го прекъсне, ще е в цикъла!
	while (1) {
		std::cin >> input;

		if (input == 0) {
			break;
		}

		st.push(input); /// "Слагаме" текущата стойност на върха на стака
	}
}


/**
	Функция, която по подадено КОПИЕ на стек от цели числа
	изписва елементите на стека от най-горен към най-долен

	@param[in] st стека от цели числа, който принтираме
*/
void printStack(std::stack<int>& st) {
	///Докато стека не е празен
	while (st.size() != 0) {
		std::cout << st.top() << " "; ///Изписваме най-горната стойност
		st.pop();					  ///И след това я трием
	}
	std::cout << '\n';
}

/**
	Функция, която изпълнява изискваната логика от задачата

	@param[in] st стека, който ще сортираме в другите два
	@paramp[in] odd, even референции към два стека, в които съответно ще сортираме
*/
void sortMod2(std::stack<int> st, std::stack<int>& odd, std::stack<int>& even) {

	///Докато в подадения стек за сортирана има елементи
	while (st.size() != 0) {
		///Определяме в кой от двата стека ще слагаме най-горния елемент на st
		if (st.top() % 2) {
			odd.push(st.top()); ///Слагаме най-горната стойност от стека st в стека odd
		}
		else {
			even.push(st.top()); ///Аналогично
		}

		st.pop(); ///Премахваме най-горния елемент на st
	}
}

int main() {
	std::stack<int> input_stack, odd_stack, even_stack;
	inputStack(input_stack);

	sortMod2(input_stack, odd_stack, even_stack);

	std::cout << "Odd: ";
	printStack(odd_stack);

	std::cout << "Even: ";
	printStack(even_stack);
}