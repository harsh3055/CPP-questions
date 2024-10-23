#include<iostream>
#include<vector>
using namespace std;


//how to save data

//a[5]=[1][2][3][4][5] //array
//0  1  2  3  4

//[1]->[2]->[3]->[4]->[5] //linkedlist


//data structure

//int data
//pointer -> which points to next node
//pointer is a variable that store memory address of any other variable of same datatype

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}

};

void print(Node* head) {
	if (head == NULL) return;

	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}


void findMiddleElement(Node* head) {
	int middleIndex = 0;
	int totalCount = 0;
	Node* temp = head;

	if (head == NULL) return;

	while (temp != NULL) {
		totalCount++;
		temp = temp->next;
	}
	middleIndex = totalCount / 2;

	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;

		if (count == middleIndex) {
			cout << "Middle element is: " << head->data;
			break;
		}
	}
}

void addElementInBeggining(Node* head, int n) {
	if (head == NULL) {
		head = new Node(n);
	} else {
		Node* temp = new Node(n);
		temp->next = head;
		head = temp;
	}
	print(head);
}


void addMultipleElementInEnd(Node* head, int arr[], int sizee) {
	if (head == NULL) {
		// head = new Node(n);
	} else {
		Node* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		// Node* temp = new Node(n);
		// tail->next = temp;

//for multiple insertion at the end
		for (int i = 0; i < sizee; i++) {
			Node* temp = new Node(arr[i]);
			tail->next = temp;
			tail = tail->next;
		}
	}
	print(head);
}
void addSingleElementInEnd(Node* head, int n) {
	if (head == NULL) {
		head = new Node(n);
	} else {
		Node* tail = head;

		while (tail->next != NULL) {
			tail = tail->next;
		}

		Node* temp = new Node(n);
		tail->next = temp;
	}
	print(head);
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);


//print function to print the elements in the linkedlist
	// print(head);

//find middle element of the linkedlist
	// findMiddleElement(head);

//add element in the begininning of the linkedlist
	// addElementInBeggining(head, 5);

//add multiple element in the end of the linkedlist
	// vector<int>arr = {6, 7, 8, 9};
	int arr[4] = {6, 7, 8, 9};
	addMultipleElementInEnd(head, arr, 4);

//add single element in the end of the linkedlist
	// addSingleElementInEnd(head, 5);

}
