#include <iostream>
#include <queue>
#include <string>


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
    „U„…„~„ˆ„{„y„‘, „{„€„‘„„„€ „„‚„€„r„u„‚„‘„r„p „t„p„|„y „u„|„u„}„u„~„„„y„„„u „r „€„„p„Š„{„p „ƒ„p „„€„t„‚„u„t„u„~„y „r
    „‚„p„ƒ„„„‘„‹ „‚„u„t, „„.„u. „u„|„u„}„u„~„„„p, „{„€„z„„„€ „ƒ„u„t„y „~„p „‰„u„|„€ „~„p „€„„p„Š„{„p„„„p „u „„€-„}„p„|„Œ„{
    „€„„ „r„ƒ„y„‰„{„y „€„ƒ„„„p„~„p„|„y
*/
bool isAscending(std::queue<int> q){

    ///„D„€„{„p„„„€ „r „€„„p„Š„{„p„„„p „y„}„p „„€„~„u „t„r„p „u„|„u„}„u„~„„„p
    while(q.size()>=2){
        int temp = q.front(); ///„H„p„„p„x„r„p„u„} „ƒ„„„€„z„~„€„ƒ„„„„„p „~„p „„‚„u„t„~„y„‘ „u„|„u„}„u„~„„
        q.pop();              ///„y „s„€ „„‚„u„}„p„‡„r„p„}„u

        if(q.front() < temp){ ///„@„{„€ „„„u„{„…„‹„y„‘ „„‚„u„t„u„~ „u„|„u„}„u„~„„ „u „„€-„}„p„|„Œ„{ „€„„ „„‚„u„t„y„Š„~„y„‘ „„‚„u„t„u„~, „x„~„p„‰„y „~„u „u „r „~„p„‚„p„ƒ„„„r„p„‹ „‚„u„t
            return false;     ///„R„|„u„t„€„r„p„„„u„|„~„€ „r„r„‚„Œ„‹„p„}„u false - „~„u „u „„€„t„‚„u„t„u„~„p
        }
    }

    return true; ///„@„{„€ „x„p „ˆ„‘„|„p„„„p „€„„p„Š„{„p „~„u „ƒ„}„u „~„p„}„u„‚„y„|„y „„‚„€„„„y„r„€„‚„u„‰„y„u „„„€ „„„‘ „u „„‚„€„t„‚„u„t„u„~„p „r „‚„p„ƒ„„„‘„‹ „‚„u„t „y „r„‚„Œ„‹„p„}„u true

}

std::queue<std::queue<int>> task4(std::queue<std::queue<int>> stst, int a, int b){
    std::queue<std::queue<int>> res;

    ///„O„q„‡„€„w„t„p„}„u „„€„u„|„u„}„u„~„„„~„€ „€„„p„Š„{„p„„„p „€„„ „€„„p„Š„{„y
    while(!stst.empty()){
        std::queue<int> temp = stst.front();  ///„H„p„„p„x„r„p„}„u „ƒ„y „{„€„„y„u „~„p „„‚„u„t„~„y„‘ „u„|„u„}„u„~„„ „~„p „€„„p„Š„{„p„„„p „€„„ „€„„p„Š„{„y
        int sum = 0;        ///„S„u„{„…„‹„p„„„p „ƒ„…„}„p „u„|„u„}„u„~„„„y„„„u

        while(!temp.empty()){ ///„R„…„}„y„‚„p„}„u „u„|„u„}„u„~„„„y„„„u „~„p „€„„p„Š„{„p„„„p
            sum+= temp.front();
            temp.pop();
        }

		///„@„{„€ „ƒ„…„}„p„„„p „…„t„€„r„|„u„„„r„€„‚„‘„r„p „…„ƒ„|„€„r„y„u„„„€ „„Œ„‡„p„}„u „„„u„{„…„‹„p„„„p „€„„p„Š„{„p „r „‚„u„x„…„|„„„p„„„~„p„„„p „€„„p„Š„{„p„„„p „€„„ „€„„p„Š„{„y
        if(sum>=a && sum<= b){
            res.push(stst.front());
        }

        stst.pop(); ///„P„‚„u„}„p„‡„r„p„}„u „€„„p„Š„{„p„„„p, „{„€„‘„„„€ „ƒ„}„u „€„q„‚„p„q„€„„„r„p„|„y „t„€ „ƒ„u„s„p, „x„p „t„p „€„q„‚„p„q„€„„„y„} „y „t„‚„…„s„y„„„u
    }

    return res;
}

int main(){
    std::queue<std::queue<int>> stst;

    for(int i = 0; i< 5; i++){
        std::queue<int> inpt;
        inputQueue(inpt);
        stst.push(inpt);
    }

    std::queue<std::queue<int>> res = task4(stst, 10, 50);

    while(!res.empty()){
        outputQueue(res.front());
        res.pop();
    }
}
