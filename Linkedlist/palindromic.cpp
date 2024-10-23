#include<iostream>
#include<vector>
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

Node* rev( Node* head) {
	Node* prev = NULL;
	Node* nex = NULL;

	while (head != NULL) {
		nex = head->next;
		head->next = prev;
		prev = head;
		head = nex;
	}
	return prev;
}

//o(n/2 for finding middle+n/2 for reversing+n/2 for comaring the two half)
void palindromic_reverse(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	slow->next = rev(slow->next);

	slow = slow->next;
	while (slow != NULL) {
		if (head->data != slow->data) {
			cout << "no";
			return;
		}
		head = head->next;
		slow = slow->next;
	}
	cout << "yes";



}
//O(n)
void palindromic_vactor(Node* head) {
	vector<int>nodes;

	while (head != NULL) {
		nodes.emplace_back(head->data);
		head = head->next;
	}

	int low = 0;
	int high = nodes.size() - 1;

	while (low <= high) {
		if (nodes[low] != nodes[high]) {
			cout << "no";
			return;
		}
		else {
			low++;
			high--;

		}

	}
	cout << "yes";

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(3);
	head1->next->next->next->next = new Node(2);
	head1->next->next->next->next->next = new Node(1);

	palindromic_vactor(head1);
	palindromic_reverse(head1);

}