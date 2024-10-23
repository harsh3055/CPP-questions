#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
	int data;
	int key;
	Node* prev;
	Node* next;

	Node(int data, int key) {
		this->data = data;
		this->key = key;
		this->prev = nullptr;
		this->next = nullptr;
	}
};

unordered_map<int, Node*> cache;
Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);
int cap;

void LRUCache(int capacity) {
	cap = capacity;
	head->next = tail;
	tail->prev = head;
}

void addNode(Node* newNode) {
	Node* temp = head->next;
	newNode->next = temp;
	newNode->prev = head;
	head->next = newNode;
}

void deleteNode(Node* deleteNode) {
	Node* deleteNext = deleteNode->next;
	Node* deletePrev = deleteNode->prev;
	deletePrev->next = deleteNext;
	deleteNext->prev = deletePrev;
	delete deleteNode;
}

int get(int key) {
	auto it = cache.find(key);
	if (it != cache.end()) {
		Node* newNode = it->second;
		int res = newNode->data;
		cache.erase(it);
		deleteNode(newNode);
		addNode(newNode);
		return res;
	}
	return -1;
}

void put(int key, int val) {
	auto it = cache.find(key);
	if (it != cache.end()) {
		Node* existingNode = it->second;
		cache.erase(it);
		deleteNode(existingNode);
	}
	if (cache.size() == cap) {
		cache.erase(tail->prev->key);
		deleteNode(tail->prev);
	}
	addNode(new Node(val, key));
	cache[key] = head->next;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin);
	freopen("../outputf.out", "w", stdout);
#endif

	cin >> cap;
	int k, v;
	cin >> k >> v;

	LRUCache(cap);
	put(k, v);
	cout << get(k);
}
