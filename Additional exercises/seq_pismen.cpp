#include <iostream>
#include <list>

struct Node{
	int data;
	Node* next;
};

using namespace std;

int func(int p, int n) {

	list<int> sequence;

	sequence.push_back(n);
	list<int>::iterator gen = sequence.begin();

	for (int i = 0; i < p-1; i++) {
		if (i % 2) {
			sequence.push_back(2 * (*gen));
			gen++;
		}
		else {
			sequence.push_back(1 + (*gen));
		}

		cout << " " << sequence.back();
	}

	return sequence.back();
}

int func2(int p, int n) {
	Node first;
	first.next = new Node;

	Node* gen = first.next;
	Node* tail = first.next;
	first.next->data = n;

	for (int i = 0; i < p - 1; i++) {
		if (i % 2) {
			tail->next = new Node;
			tail = tail->next;
			tail->data = 2 * gen->data;
			gen = gen->next;
		}
		else {
			tail->next = new Node;
			tail = tail->next;
			tail->data = 1 + gen->data;
		}
	}
	func((*tail).data, 10);
	return tail->data;
}

int main() {
	cout << endl<<func2(100, 3);
}