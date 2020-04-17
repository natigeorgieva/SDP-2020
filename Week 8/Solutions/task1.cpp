#include <iostream>
#include <queue>
#include <string>
#include <stack>

/**
	„U„…„~„{„ˆ„y„‘, „{„€„‘„„„€ „„‚„€„r„u„‚„‘„r„p „t„p„|„y „u„t„y„~ „ƒ„y„}„r„€„|„u„~ „~„y„x „ƒ„u
	„ƒ„Œ„ƒ„„„€„y „ƒ„p„}„€ „€„„ „ˆ„y„†„‚„y

	@param[in] s „B„‡„€„t„~„y„‘ „~„y„x

	@returns   „B„‚„Œ„‹„p true, „p„{„€ „u „y„x„„Œ„|„~„u„~„€ „…„ƒ„|„€„r„y„u„„„€, „r
			   „„‚„€„„„y„r„u„~ „ƒ„|„…„‰„p„z false
*/
bool isInteger(std::string s) {
	bool state = true;		///„U„|„p„s, „ƒ „{„€„z„„„€ „€„x„~„p„‰„p„r„p„}„u „t„p„|„y „„„u„{„…„‹„y„‘ „~„y„x „ƒ„Œ„t„Œ„‚„w„p „ƒ„p„}„€ „ˆ„y„†„‚„y

	for (int i = 0; state && i < s.length(); i++) {
		if (!isdigit(s[i])) {		///„@„{„€ „~„p„}„u„‚„y„} „ƒ„y„}„r„€„| „‚„p„x„|„y„‰„u„~ „€„„ „ˆ„y„†„‚„p „ƒ„r„p„|„‘„}„u „†„|„p„s„p
			state = false;
		}
	}

	return state;
}


/**
	„U„…„~„{„ˆ„y„‘, „{„€„‘„„„€ „{„€„~„r„u„‚„„„y„‚„p „t„p„t„u„~ „ƒ„y„}„r„€„|„u„~ „~„y„x „r „ˆ„u„|„€„‰„y„ƒ„|„u„~„p „ƒ„„„€„z„~„€„ƒ„„

	@param[in] s „B„‡„€„t„~„y„‘ „~„y„x

	@returns   „B„‚„Œ„‹„p „‰„y„ƒ„|„€„„„€ „r „ƒ„y„}„r„€„|„~„y„‘ „~„y„x „{„p„„„€ „ˆ„u„|„€„‰„y„ƒ„|„u„~„p „t„p„~„~„p
*/
int toInteger(std::string s) {
	int num = 0; ///„S„u„{„…„‹„€„„„€ „‰„y„ƒ„|„€

	for (int i = 0; i < s.length(); i++) {
		num = 10 * num + (s[i] - '0');	///„T„}„~„€„w„p„r„p„}„u „„„u„{„…„‹„€„„„€ „‰„y„ƒ„|„€ „ƒ 10 „y „s„€ „ƒ„Œ„q„y„‚„p„}„u „ƒ „„„u„{„…„‹„p„„„p „ˆ„y„†„‚„p
	}

	return num;

}


/**
	„†„…„~„{„ˆ„y„‘, „{„€„‘„„„€ „r„Œ„r„u„w„t„p „r „‚„u„†„u„‚„y„‚„p„~„p „€„„p„Š„{„p „€„„ „ˆ„u„|„y „‰„y„ƒ„|„p,
	„t„€„{„p„„„€ „~„u „ƒ„u „r„Œ„r„u„t„u „~„u„‹„€, „{„€„u„„„€ „~„u „u „ˆ„‘„|„€ „‰„y„ƒ„|„€

	@param[in, out] q „P„€„t„p„t„u„~„p „€„„p„Š„{„p, „r „{„€„‘„„„€ „„Œ„|„~„y„} „ˆ„u„|„y „‰„y„ƒ„|„p

*/
void inputQueue(std::queue<int>& q) {
	std::string input;  ///„N„y„x, „r „{„€„z„„„€ „„p„x„y„} „„„u„{„…„‹„y„‘ „r„‡„€„t „€„„ „{„|„p„r„y„p„„„…„‚„p„„„p

	while(1) {
		std::cin >> input;		///„I„x„r„|„y„‰„p„}„u „€„„ „„€„„„€„{„p „~„y„x

		if (isInteger(input)) {			///„@„{„€ „y„x„r„|„u„‰„u„~„y„‘ „~„y„x „u „‰„y„ƒ„|„€
			q.push(toInteger(input));   ///„P„‚„u„€„q„‚„p„x„…„r„p„}„u „s„€ „r „„„p„{„€„r„p „y „s„€ „ƒ„|„p„s„p„}„u „r „€„„p„Š„{„p„„„p
		}
		else {							///„B „„‚„€„„„y„r„u„~ „ƒ„|„…„‰„p„z „„„u„‚„}„y„~„y„‚„p„}„u „†„…„~„{„ˆ„y„‘„„„p
			return;
		}
	}
}


///„U„…„~„{„ˆ„y„‘ „„‚„y„~„„„y„‚„p„‹„p „€„„p„Š„{„p„~„p „u„{„‚„p„~„p. „H„p „„€-„„€„t„‚„€„q„~„€ „€„q„‘„ƒ„~„u„~„y„u „ƒ„u „{„€„~„ƒ„…„|„„„y„‚„p„z„„„u „ƒ
///„‚„u„Š„u„~„y„„„u „„‚„y„}„u„‚„y „€„„ „„‚„u„t„y„Š„~„€„„„€ „…„„p„Š„~„u„~„y„u
void outputQueue(std::queue<int> q) {

	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
}


/**
    „U„…„~„{„ˆ„y„‘, „{„€„‘„„„€ „„‚„€„r„u„‚„‘„r„p „t„p„|„y „u„|„u„}„u„~„„„y„„„u „~„p
    „„€„t„p„t„u„~„p„„„p „€„„p„Š„{„p „€„q„‚„p„x„…„r„p„„ „„p„|„y„~„t„‚„€„}. „@„|„s„€„‚„y„„„Œ„}„p „u „‚„u„p„|„y„x„y„‚„p„~
    „ƒ „„€„}„€„‹„u„~ „ƒ„„„u„{ „y „€„„p„Š„{„p. „D„€„{„p„„„€ „r „„€„t„p„t„u„~„p„„„p „€„„p„Š„{„p „y„}„p „u„|„u„}„u„~„„„y
    „„Œ„‡„p„}„u „„Œ„‚„r„y„‘ „u„|„u„}„u„~„„ „r „ƒ„„„u„{„p („„„p„{„p „€„q„‚„Œ„‹„p„}„u „„€„t„‚„u„t„q„p„„„p „~„p „u„|„u„}„u„~„„„y„„„u „r „€„„p„Š„{„p„„„p)
    „y „r „€„„p„Š„{„p„„„p („„„p„{„p „x„p„„p„x„r„p„}„u „€„‚„y„s„y„~„p„|„~„p„„„p „„€„t„‚„u„t„q„p). „R„u„s„p „p„{„€ „€„„p„Š„{„p„„„p „u „€„q„‚„p„x„…„r„p„|„p
    „„p„|„y„~„t„€„} „„„€ „r„ƒ„u„{„y „t„r„p „„€„‚„u„t„~„y „u„|„u„}„u„~„„„p „r „t„r„u„„„u „„€„}„€„‹„~„y „ƒ„„„‚„…„{„„„…„‚„y „„„‚„‘„q„r„p „t„p „ƒ„y „ƒ„Œ„„p„t„p„„.

    @param[in] q „O„„p„Š„{„p„„„p, „‰„y„y„„„€ „u„|„u„}„u„~„„„y „‹„u „„‚„€„r„u„‚„‘„r„p„}„u

    @returns true - „p„{„€ „€„q„‚„x„…„r„p„„  „„p„|„y„~„t„‚„€„}
             false - „r „„‚„€„„„y„r„u„~ „ƒ„|„…„‰„p„z

*/
bool isPalindrome(std::queue<int> q){
    std::stack<int> tempSt; ///„P„€„}„€„‹„u„~ „ƒ„„„u„{, „r „{„€„z„„„€ „‹„u „€„q„Œ„‚„~„u„} „u„|„u„}„u„~„„„y„„„u „€„„ „€„„p„Š„{„p„„„p
    std::queue<int> tempQ;  ///„N„€„r„p „€„„p„Š„{„p, „{„Œ„t„u„„„€ „‹„u „„p„x„y„} „u„|„u„}„u„~„„„y„„„u „~„p „„€„t„p„t„u„~„p„„„p

    ///„D„€„{„p„„„€ „y„}„p „u„|„u„}„u„~„„„y „r „€„„p„Š„{„p„„„p
    while(!q.empty()){
        ///„P„Œ„‡„p„}„u „„‚„u„t„~„y„‘ „u„|„u„}„u„~„„ „~„p „€„„p„Š„p„{„„„p „r „„€„}„€„‹„~„y„„„u „ƒ„„„u„{ „y „€„„p„Š„{„p
        tempSt.push(q.front());
        tempQ.push(q.front());

        q.pop(); ///„„‚„u„}„p„Š„‡„r„p„}„u „„‚„u„t„~„y„‘ „u„|„u„}„u„~„„
    }

    ///„D„€„{„p„„„€ „y„}„p „u„|„u„}„u„~„„„y „r „„€„}„€„‹„~„y„‘ „ƒ„„„u„{
    while(!tempSt.empty()){
        ///„@„{„€ „t„r„p „„„u„{„…„‹„y „u„|„u„}„u„~„„„y „r „„€„}„€„‹„~„y„„„u „ƒ„„„‚„…„{„„„…„‚„y „ƒ„u „‚„p„x„}„y„~„p„r„p„„ „„„€ „€„„p„Š„{„p„„„p „~„u „u „€„q„‚„p„x„…„r„p„|„p „„p„|„y„~„t„‚„€„}
        if(tempSt.top() != tempQ.front()){
            return false;
        }

        ///„P„‚„u„}„p„‡„r„p„}„u „ƒ„y „„Œ„‚„r„y„„„u „t„r„p „u„|„u„}„u„~„„„p „x„p „„€„}„€„‹„~„y„„„u „ƒ„„„‚„…„{„„„…„‚„y, „x„p „t„p „t„€„ƒ„„„Œ„„y„} „ƒ„|„u„t„r„p„‹„y„„„u „u„|„u„}„u„~„„„y
        tempSt.pop();
        tempQ.pop();
    }

    return true;
}

int main(){
    std::queue<int> inpt;

    inputQueue(inpt);
    std::cout<<"Is the queue palindrome : "<<(isPalindrome(inpt) ? "Yes" : "No");
}
