#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* SortedIntersect(Node* a, Node* b) {
	Node *p = a, *q = b;
	Node dummy;
	dummy.next = nullptr;

	Node* c = &dummy;

	while (p != nullptr && q != nullptr) {

		while (p != nullptr && p->next != nullptr && p->data == p->next->data) {
			p = p->next;
		}

		while (q != nullptr && q->next != nullptr && q->data == q->next->data) {
			q = q->next;
		}

		if (p->data == q->data) {
			c->next = new Node;
			c = c->next;
			c->data = p->data;
			c->next = nullptr;

			p = p->next;
			q = q->next;
		}
		else if(p->data < q->data) {
			p = p->next;
		}
		else {
			q = q->next;
		}
	}

	return dummy.next;
}

void printL(Node* l) {
	while (l != nullptr) {
		cout << l->data << " ";
		l = l->next;
	}

	cout << endl;
}

int main() {
	Node dummy1, dummy2;
	dummy1.next = nullptr;
	dummy2.next = nullptr;

	Node* c1 = &dummy1;
	Node* c2 = &dummy2;

	int input;

	while (1) {
		cin >> input;
		if (input == 0) {
			break;
		}

		c1->next = new Node;
		c1 = c1->next;
		c1->data = input;
		c1->next = nullptr;

	}
	//printL(dummy1.next);
	
	while (1) {
		cin >> input;
		if (input == 0) {
			break;
		}

		c2->next = new Node;
		c2 = c2->next;
		c2->data = input;
		c2->next = nullptr;
	}
	//printL(dummy2.next);

	printL(SortedIntersect(dummy1.next, dummy2.next));
}