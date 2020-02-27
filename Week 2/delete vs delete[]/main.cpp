/***
    Програма целяща да покаже разликата между delete и delete[]

    Кратко описание:
        Двата оператора изчистват паметта сочена от подадения указател, но delete[] извиква
        деструктура на всеки елемент на заделения от new[] масив, а delete само деструктура
        на първия елемент.

        Използването на delete[] върху указател със памет заделена с new води до тежки
        главоболия!

    Инструкции за употреба:
        При всяко заделяне на памет с new, чистете с delete.
        При всяко заделяне на памет с new[], чистете с delete[], дори ако сте заделили памет за вградени типове данни.

        Грешното използване на тези оператори води до нежелани ефекти:
            - По-малко точки на домашни, контролни и прочее
            - Random крашване на програмата
            - Психично разтройсвто и главоболие

    Повече информация за двата оператора може да намерите на:
        http://www.cplusplus.com/reference/new/operator%20delete/
        http://www.cplusplus.com/reference/new/operator%20delete[]/
        https://stackoverflow.com/questions/2425728/delete-vs-delete-operators-in-c
*/


#include <iostream>
using namespace std;

class Test{
public:
    /**
        При създаването на всеки обект създаваме доста голям масив
        в динамичанта памет
    */
    Test(){
        cout<<"Object created\n";
        memoryHole = new int[100000];
    }

    ~Test(){
        cout<<"Object destroyed\n";
        delete[] memoryHole;
    }

private:
    int *memoryHole;
};

int main(){
    int pause;
    Test* ptr1, *ptr2, *ptr3;

    /**
    Тест какво се случва при използване на delete[] при заделена памет с new

    ptr3 = new Test;
    delete[] ptr3;
    */

    cout<<"Before allocation of massive amount of objects...";
    cin>>pause; ///Използваме вход от клавиатурата за пауза при проверка на памметта чрез някоя програма или дебъгера на VS


    ///Създаваме общо 3000 елемента в ДП -> 3000 * 100 000= 300 000 000 int елемента в паметта приблизително 1.1GB
    ptr1 = new Test[1500];
    ptr2 = new Test[1500];
    cout<<"After allocation of massive amount of objects...";
    cin>>pause;


    delete[] ptr1;
    cout<<"After delete[] ptr1...";
    cin>>pause;

    delete ptr2;
    cout<<"After delete ptr2...";
    cin>>pause;
}
