// program to find the cycle and also the starting point of the cycle
#include<iostream>
#include<vector>
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

void ifcycle_linkedlist(Node* head) {
	if (head == NULL or head->next == NULL) {
		cout << "notgood";
		return;
	}

	Node* slow = head;
	Node* fast = head;
	Node* entry = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			cout << "no cycle";
			while (slow != entry) {
				slow = slow->next;
				entry = entry->next;
			}
			cout << "Cycle starts at node with value: " << entry->data;
			return; // Added return to exit the function af
		}
	}
	cout << "no cycle";
}

void ifcycle(Node* head) {
	unordered_set < Node* > node;
	while (head != NULL) {
		if (node.count(head)) {
			cout << head->data;
			return;
		}
		node.insert(head);
		head = head->next;
	}
	cout << "no cycle";
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(9);
	head1->next->next->next = new Node(3);
	head1->next->next->next->next = new Node(2);
	head1->next->next->next->next->next = head1->next->next->next;

	// ifcycle(head1);
	ifcycle_linkedlist(head1);
}