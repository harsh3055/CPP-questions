#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* bottom;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->bottom = NULL;
	}

};

void print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->bottom;
	}
}

Node* mergeList(Node* a, Node* b) {
	Node* temp = new Node(0);
	Node* res = temp;

	while (a != NULL and b != NULL) {
		if (a->data < b->data) {
			temp->bottom = a;
			temp = temp->bottom;
			a = a->bottom;
		}
		else {
			temp->bottom = b;
			temp = temp->bottom;
			b = b->bottom;
		}
	}

	if (a) temp->bottom = a;
	else temp->bottom = b;

	return res->bottom;
}

Node* flatten(Node* root) {
	if (root == NULL or root->next == NULL) {
		return root;
	}
	root->next = flatten(root->next);
	mergeList(root, root->next);
	return root;
}

void flatten_vector(Node* head) {
	Node* temp = new Node(0);
	Node* res = temp;
	vector<int> v;
	while (head != NULL) {
		Node* newhead = head;
		while (newhead != NULL) {
			v.push_back(newhead->data);
			newhead = newhead->bottom;
		}
		head = head->next;
	}
	sort(v.begin(), v.end());
	for (auto it : v) {
		Node* newNode = new Node(it);
		temp->bottom = newNode;
		temp = temp->bottom;
	}
	print(res->bottom);
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head = new Node(1);
	head->bottom = new Node(2);
	head->bottom->bottom = new Node(3);
	head->bottom->bottom->bottom = new Node(4);

	Node* head2 = new Node(3);
	head2->bottom = new Node(9);
	head2->bottom->bottom = new Node(10);

	head->next = head2;

	//print(flatten(head));
	flatten_vector(head);


}