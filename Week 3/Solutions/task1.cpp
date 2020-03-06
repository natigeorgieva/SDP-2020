#include <iostream>
using namespace std;

const int MAX_LEN = 100;

void change(char* &str, char targetChar, char newChar){
    ///Ако указателя не сочи към нищо няма какво да правим
    if(str == nullptr){
        return;
    }

    ///Почваме да обхождаме масива
    int pos = 0;

    while(str[pos]!='\0'){
        if(str[pos] == targetChar){
            str[pos] = newChar;
        }
        pos++;
    }
}

int main(){
    ///Създаваме си указател към char и му записваме адреса върнат от new
    ///където сме заделили паметта за масива
    char* inpt = new char[MAX_LEN];
    char targetChar, newChar;

    cout<<"Enter a string (max length "<<MAX_LEN-1<<"): ";
    /**
        Понеже искаме да въведем символен низ използваме cin.getline(), на
        който подаваме къде да запише въведения низ и с каква максимална дължина
        В случая понеже масива е с дължина MAX_LEN и трябва да запишем терминиращи символ
        ще имаме най-голяма дължина на низа MAX_LEN - 1
    */
    cin.getline(inpt, MAX_LEN);

    cout<<"Enter targetChar: ";
    cin>>targetChar;
    cout<<"Enter newChar:";
    cin>>newChar;

    change(inpt, targetChar, newChar);

    cout<<"After change: ";
    cout<<inpt<<endl;
}
