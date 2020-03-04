#include <iostream>
#include <cctype>
using namespace std;

const int MAX_LEN = 100;

char* makeAcronym(char* inpt){
    if(inpt == nullptr){
        return nullptr;
    }

    char* acronym = new char[MAX_LEN];

    int currPos = 0, currStart = -1, currLen = 0, posAcronym = 0;

    while(inpt[currPos] != '\0'){

        if(isalpha(inpt[currPos])){
            currStart = currPos;

            while(isalpha(inpt[currPos])){
                 currPos++;
                 currLen++;
            }

            if(currLen > 1){
                acronym[posAcronym] = toupper(inpt[currStart]);
                posAcronym++;
            }

            currStart = -1;
            currLen = 0;
        }
        else{
            currPos++;
        }
    }

    acronym[posAcronym] = '\0';

    return acronym;
}


int main(){
    ///„R„Œ„x„t„p„r„p„}„u „ƒ„y „…„{„p„x„p„„„u„| „{„Œ„} char „y „}„… „x„p„„y„ƒ„r„p„}„u „p„t„‚„u„ƒ„p „r„Œ„‚„~„p„„ „€„„ new
    ///„{„Œ„t„u„„„€ „ƒ„}„u „x„p„t„u„|„y„|„y „„p„}„u„„„„„p „x„p „}„p„ƒ„y„r„p
    char* inpt = new char[MAX_LEN];

    ///„R„Œ„x„t„p„r„p„}„u „…„{„p„x„p„„„u„|, „r „{„€„z„„„€ „t„p „x„p„„y„Š„u„} „p„t„‚„u„ƒ„p, „{„Œ„t„u„„„€ „ƒ„u „~„p„}„y„‚„p „p„{„‚„€„~„y„}„p
    ///„H„p„~„…„|„‘„r„p„}„u „s„€ „x„p „t„€„q„‚„p „„‚„p„{„„„y„{„p „‹„€„} „~„‘„}„p „r„u„u„t„~„p„s„p „t„p „}„… „x„p„„y„Š„u„} „p„t„‚„u„ƒ
    char* result = nullptr;


    cout<<"Enter a string (max length "<<MAX_LEN-1<<"): ";
    /**
        „P„€„~„u„w„u „y„ƒ„{„p„}„u „t„p „r„Œ„r„u„t„u„} „ƒ„y„}„r„€„|„u„~ „~„y„x „y„x„„€„|„x„r„p„}„u cin.getline(), „~„p
        „{„€„z„„„€ „„€„t„p„r„p„}„u „{„Œ„t„u „t„p „x„p„„y„Š„u „r„Œ„r„u„t„u„~„y„‘ „~„y„x „y „ƒ „{„p„{„r„p „}„p„{„ƒ„y„}„p„|„~„p „t„Œ„|„w„y„~„p
        „B „ƒ„|„…„‰„p„‘ „„€„~„u„w„u „}„p„ƒ„y„r„p „u „ƒ „t„Œ„|„w„y„~„p MAX_LEN „y „„„‚„‘„q„r„p „t„p „x„p„„y„Š„u„} „„„u„‚„}„y„~„y„‚„p„‹„y „ƒ„y„}„r„€„|
        „‹„u „y„}„p„}„u „~„p„z-„s„€„|„‘„}„p „t„Œ„|„w„y„~„p „~„p „~„y„x„p MAX_LEN - 1
    */
    cin.getline(inpt, MAX_LEN);

    cout<<"The acronym is: ";

    result = makeAcronym(inpt);

    cout<<result;


}
