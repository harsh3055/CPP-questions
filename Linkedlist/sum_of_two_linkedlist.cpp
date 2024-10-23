#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {};
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

Node* sum(Node* head1, Node* head2) {
	Node* dummyNode = new Node;
	Node* temp = dummyNode;
	int carry = 0;
	while (head1 != NULL or head2 != NULL or carry != 0) {
		int sum = 0;
		if (head1 != NULL) {
			sum += head1->data;
			head1 = head1->next;
		}

		if (head2 != NULL) {
			sum += head2->data;
			head2 = head2->next;
		}
		sum += carry;
		carry = sum / 10;
		Node* newNode = new Node(sum % 10);
		temp->next = newNode;
		temp = temp->next;
	}
	print(dummyNode->next);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head1 = new Node(5);
	head1->next = new Node(6);
	head1->next->next = new Node(7);
	head1->next->next->next = new Node(9);

	Node* head2 = new Node(2);
	head2->next = new Node(4);
	head2->next->next = new Node(3);

	sum(head1, head2);


}

