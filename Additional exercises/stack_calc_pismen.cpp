#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string str;
	cin >> str;
	stack<int> digits, chars;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '(') {
			if (str[i] >= '0' && str[i] <= '9') {
				digits.push(str[i]- '0');
			}
			else if (str[i] == '$' || str[i] == '@') {
				chars.push(str[i]);
			}
			else {
				int a, b, oper;

				a = digits.top();
				digits.pop();
				b = digits.top();
				digits.pop();

				oper = chars.top();
				chars.pop();

				if (oper == '@') {
					digits.push((a + b) % 10);
				}
				else {
					if (a < b) {
						digits.push(a);
					}
					else {
						digits.push(b);
					}
				}
			}
		}
	}

    cout << endl<<digits.top();
}
