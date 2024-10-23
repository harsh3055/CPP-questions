#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next ;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void print(Node* head) {
	while (head != NULL) {
		cout << head->data << endl;
		head = head->next;
	}
}

Node* reverse(Node* root) {
	Node* dummyNode = NULL;
	Node* nex = root;
	while (root != NULL) {
		nex = nex->next;
		root->next = dummyNode;
		dummyNode = root;
		root = nex;
	}
	return dummyNode;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);

	//print(head);
	print(reverse(head));
	//print(head);

	delete head->next->next;
	delete head->next;
	delete head;
}