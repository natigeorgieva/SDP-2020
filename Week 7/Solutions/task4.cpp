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


std::stack<std::stack<int>> task4(std::stack<std::stack<int>> stst, int a, int b){
    std::stack<std::stack<int>> res;

    ///Обхождаме елементно стека от стекове
    while(!stst.empty()){
        std::stack<int> temp = stst.top();  ///Запазваме си копие на горрния елемент на стека от стекове
        int sum = 0;        ///Текущата сума елементите

        while(!temp.empty()){ ///Сумираме елементите на стека
            sum+= temp.top();
            temp.pop();
        }

		///Ако сумата удовлетворява условието пъхаме текущия стек в стека от стекове
        if(sum>=a && sum<= b){
            res.push(stst.top());
        }

        stst.pop(); ///Премахваме стека, който сме обработвали до сега, за да обработим и другите
    }

    return res;
}

int main(){

    std::stack<std::stack<int>> stst;

    for(int i = 0; i< 5; i++){
        std::stack<int> inpt;
        inputStack(inpt);
        stst.push(inpt);
    }

    std::stack<std::stack<int>> res = task4(stst, 10, 50);

    while(!res.empty()){
        printStack(res.top());
        res.pop();
    }

}
