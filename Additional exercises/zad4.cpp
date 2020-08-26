#include<iostream>
#include <queue>
using namespace std;

queue<int> mergeQueue(queue<int> a, queue<int> b) {
	queue<int> c;

	while (a.size() != 0 && b.size()!=0) {
		if (a.front() < b.front()) {
			c.push(a.front());
			a.pop();
		}
		else if (a.front() > b.front()) {
			c.push(b.front());
			b.pop();
		}
		else {
			c.push(b.front());
			b.pop();
			c.push(a.front());
			a.pop();
		}
	}

	while (a.size() != 0) {
		c.push(a.front());
		a.pop();
	}

	while (b.size() != 0) {
		c.push(b.front());
		b.pop();
	}

	return c;
}


int main() {
	
}
