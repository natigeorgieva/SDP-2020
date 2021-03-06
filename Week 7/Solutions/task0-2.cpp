#include <iostream>
#include <stack>    ///Добавяме библиотеката нужна да използваме стекове


/**
	Функция, която по подадена РЕФЕРЕНЦИЯ към стек от цели числа
	въвежда в нея числа от клавиатурата докато не достигне 0

	@param[in] st референция към стек от цели числа
*/
void inputStack(std::stack<int>& st) {
	int input;		///Променливата, в която ще помним текущото въведено число от клавиатурата

	///Правим безкраен цикъл. Логиката, която ще го прекъсне ще е в цикъла!
	while (1) {
		std::cin >> input;

		if (input == 0) {
			break;
		}

		st.push(input); /// "Слагаме" текущата стойност на върка на стака
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
		std::cout << st.top() << " "; ///Изписваме най-гораната стойност
		st.pop();					  ///И след това я трием
	}
	std::cout << '\n';
}


/**
	Функцията изпълняваща логиката изискана от условието на задачата

	@param[in] st1, st2 двата стек, чиито елементи ще събираме
	
	@returns result изходния стек съдържащ поелементната сума на двата
				подадени стека
*/
std::stack<int> sum(std::stack<int> st1, std::stack<int> st2) {
	std::stack<int> result;	///стеак, който ще върнем
	int sum = 0;            ///Сумата, която се налага, ако стековетеа са различна големина

	///Въртим цикъл докато и в двата стеак има елементи
	while (st1.size() != 0 && st2.size() != 0) {
		result.push(st1.top() + st2.top());   ///Добавяме сумата на двата горни елемента на подадените стекове в резултатния
		st1.pop();		///Премахваме най-горните елементи и на двата стека
		st2.pop();
	}
	
	///Сега според в това кой от двата стека има останали елементи (ако има такива)
	///се изпълнява определния цикъл от долните два


	while (st1.size() != 0) {
		sum += st1.top();
		st1.pop();
	}

	while (st2.size() != 0) {
		sum += st2.top();
		st2.pop();
	}

	if (sum != 0) result.push(sum); ///Ако сумата е различна от нула я добавяме

	return result;
}

int main() {
	std::stack<int> st1, st2;

	inputStack(st1);
	inputStack(st2);

	std::stack<int> res = sum(st1, st2);

	printStack(res);

}