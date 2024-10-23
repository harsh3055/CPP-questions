//intersection point of two node

#include<iostream>
#include<unordered_set>
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
	cout << head->data;
}

void findIntersection(Node* head1, Node* head2) {

	int count1 = 0, count2 = 0;
	Node* temp1 = head1;
	Node* temp2 = head2;
	while (temp1 != NULL) {
		count1++;
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		count2++;
		temp2 = temp2->next;
	}

	int move = abs(count1 - count2);

	while (move != 0) {
		if (count1 > count2)
			head1 = head1->next;
		else
			head2 = head2->next;

		move--; // decrement move variable
	}
	while (head1->data != head2->data) {
		head1 = head1->next;
		head2 = head2->next;
	}
	print(head1);
}


//complexity O(m+n)
void findIntersection3(Node* head1, Node* head2) {
	unordered_set<Node*>s;
	while (head1 != NULL) {
		s.insert(head1);
		head1 = head1->next;
	}
	while (head2 != NULL) {
		if (s.count(head2)) {
			cout << head2->data;
			return;
		}
		head2 = head2->next;
	}
}

//complexity O(m*n)
void findIntersection2(Node* head1, Node* head2) {

	Node* temp1 = head1;

	while (temp1 != NULL) {
		Node* temp2 = head2;
		while (temp2 != NULL) {
			if (temp1 == temp2) {
				cout << temp1->data;
				return;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head1 = new Node(5);
	head1->next = new Node(6);
	head1->next->next =  new Node(3);
	head1->next->next->next = new Node(9);


	Node* head2 = new Node(2);
	head2->next = new Node(4);
	head2->next->next = new Node(5);
	head2->next->next->next = head1->next->next;

	//findIntersection(head1, head2);
	findIntersection3(head1, head2);


}