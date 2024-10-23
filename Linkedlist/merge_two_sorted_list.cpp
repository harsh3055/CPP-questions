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

Node* merge(Node* l1, Node* l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	if (l1->data < l2->data) {
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else {
		l2->next = merge(l1, l2->next);
		return l2;
	}
}

print(Node* head) {
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
	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	head1->next->next->next->next = new Node(5);
	head1->next->next->next->next->next = new Node(6);

	Node* head2 = new Node(4);
	head2->next = new Node(7);
	head2->next->next = new Node(9);

	merge(head1, head2);
	print(head1);



}