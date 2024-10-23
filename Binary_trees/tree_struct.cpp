// representing tree using a class and two pointer one is left and right
// this is the also also a funtion to calculate the boundry traversal of the binary tree
#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}

};

bool isLeaf(Node* root) {
	if (root->left == NULL and root->right == NULL)
		return true;
	return false;
}

void checkleft(Node*root, vector<int>&ans) {
	Node* node = root->left;
	while (node) {
		if (!isLeaf(node))
			ans.push_back(node->data);
		if (node->left)
			node = node->left;
		else
			node = node->right;
	}
}
void checkright(Node* root, vector<int>&ans) {
	Node* node = root->right;
	vector<int>temp;
	while (node) {

		if (!isLeaf(node))
			temp.push_back(node->data);
		if (node->right)
			node = node->right;
		else
			node = node->left;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		ans.push_back(temp[i]);
	}
}

void checkleaf( Node*root, vector<int>&ans) {
	if (isLeaf(root)) {
		ans.push_back(root->data);
		return;
	}
	if (root->left) checkleaf(root->left, ans);
	if (root->right) checkleaf(root->right, ans);
}

// void inorder(Node* root){
// 	if(root == NULL) return;
// 	inorder(root->left);
// 	cout<<root->data<<" ";
// 	inorder(root->right);
// }

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	Node* root = new Node(10);
	root->left = new Node(15);
	root->right = new Node(12);
	root->right->right = new Node(14);
	root->right->right->left = new Node(6);
	vector<int>ans;
	ans.push_back(root->data);

	checkleft(root, ans);
	checkleaf(root, ans);
	checkright(root, ans);

	for (int i : ans)
		cout << i << " ";
}