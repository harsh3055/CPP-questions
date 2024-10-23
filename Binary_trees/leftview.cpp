#include<iostream>
#include<vector>
#include <queue>
#include<limits.h>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node(int data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

//using queue
void leftView(Node * root) {
	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		int n = q.size();
		for (int i = 1 ; i <= n ; i++) {

			Node* node = q.front();
			q.pop();
			if (i == 1)
				cout << node->val << "->";
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
}
// using recursion
int maxlevel = INT_MIN;
void leftviewrec(Node * root, int level = 0) {
	if (root == NULL)
		return;
	if (maxlevel < level) {
		cout << root->val << "->";
		maxlevel = level;
	}
	level = level + 1;
	leftviewrec(root->left, level);
	leftviewrec(root->right, level);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right->left = new Node(14);


	leftView(root);


}