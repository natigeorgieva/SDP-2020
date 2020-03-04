#include <iostream>
using namespace std;

const int MAX_LEN = 100;

void change(char* &str, char targetChar, char newChar){
    ///„@„{„€ „…„{„p„x„p„„„u„|„‘ „~„u „ƒ„€„‰„y „{„Œ„} „~„y„‹„€ „~„‘„}„p „{„p„{„r„€ „t„p „„‚„p„r„y„}
    if(str == nullptr){
        return;
    }

    ///„P„€„‰„r„p„}„u „t„p „€„q„‡„€„w„t„p„}„u „}„p„ƒ„y„r„p
    int pos = 0;

    while(str[pos]!='\0'){
        if(str[pos] == targetChar){
            str[pos] = newChar;
        }
        pos++;
    }
}

int main(){
    ///„R„Œ„x„t„p„r„p„}„u „ƒ„y „…„{„p„x„p„„„u„| „{„Œ„} char „y „}„… „x„p„„y„ƒ„r„p„}„u „p„t„‚„u„ƒ„p „r„Œ„‚„~„p„„ „€„„ new
    ///„{„Œ„t„u„„„€ „ƒ„}„u „x„p„t„u„|„y„|„y „„p„}„u„„„„„p „x„p „}„p„ƒ„y„r„p
    char* inpt = new char[MAX_LEN];
    char targetChar, newChar;

    cout<<"Enter a string (max length "<<MAX_LEN-1<<"): ";
    /**
        „P„€„~„u„w„u „y„ƒ„{„p„}„u „t„p „r„Œ„r„u„t„u„} „ƒ„y„}„r„€„|„u„~ „~„y„x „y„x„„€„|„x„r„p„}„u cin.getline(), „~„p
        „{„€„z„„„€ „„€„t„p„r„p„}„u „{„Œ„t„u „t„p „x„p„„y„Š„u „r„Œ„r„u„t„u„~„y„‘ „~„y„x „y „ƒ „{„p„{„r„p „}„p„{„ƒ„y„}„p„|„~„p „t„Œ„|„w„y„~„p
        „B „ƒ„|„…„‰„p„‘ „„€„~„u„w„u „}„p„ƒ„y„r„p „u „ƒ „t„Œ„|„w„y„~„p MAX_LEN „y „„„‚„‘„q„r„p „t„p „x„p„„y„Š„u„} „„„u„‚„}„y„~„y„‚„p„‹„y „ƒ„y„}„r„€„|
        „‹„u „y„}„p„}„u „~„p„z-„s„€„|„‘„}„p „t„Œ„|„w„y„~„p „~„p „~„y„x„p MAX_LEN - 1
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
