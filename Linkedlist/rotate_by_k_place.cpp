#include <iostream>
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

void rotate(Node* head, int n) {

	if (head == NULL || n == 0) {
		return;
	}

	Node* for_length = head;

	int count = 0;
	while (for_length != 0) {
		count++;
		for_length = for_length->next;
	}

	if (n > count) {
		n = n % count;
	}

	Node* temp = head;
	Node* curr = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = curr;

	for (int i = 0; i < n - 1; i++) {
		curr = curr->next;
	}

	head = curr->next;
	curr->next = NULL;
	print(head);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	int n;
	cin >> n;

	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(9);
	head1->next->next->next = new Node(3);
	head1->next->next->next->next = new Node(2);

	rotate(head1, n);
	//print(head1);
}