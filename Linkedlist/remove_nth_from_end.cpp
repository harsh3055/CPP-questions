//removing nth node from the end from the linkedlist

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n; cin >> n;

	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);


	Node* dummyNode = head;
	while (n != 0) {
		dummyNode = dummyNode->next;
		n--;
	}
	Node* toDelete = head;

	while (dummyNode->next != NULL) {
		toDelete = toDelete->next;
		dummyNode = dummyNode->next;
	}
	toDelete->next = toDelete->next->next;
	print(head);
}