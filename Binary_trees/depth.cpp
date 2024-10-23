// finding the depth of the binary tree using queue and recursion
// finding the diamter of the binary tree using recursion
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

node* new_node(int data) {
	node*temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// inorder printing of the binary tree
void print(node *root) {
	if (root == NULL)
		return;
	print(root->left);
	cout << root->data << endl;
	print(root->right);
}

// some of the left and right heigh of the binary tree is the diameter of the tree
int calculate_diameter(node* root, int & diameter) {
	if (root == NULL)
		return 0;
	int lh = calculate_diameter(root->left, diameter);
	int rh = calculate_diameter(root->right, diameter);
	diameter = max(diameter, lh + rh);
	return 1 + max(lh, rh);
}

//time complexity is O(n)
//space complexity is O(1)
int calculate_depth_recursively(node* root) {
	// base condition
	if (root == NULL)
		return 0;

	int lh = calculate_depth_recursively(root->left);

	int rh = calculate_depth_recursively(root->right);


	return 1 + max(lh, rh);
}

//time complexity is O(n)
//space complexity is O(n)
int calculate_depth(node* root) {
	queue<node* > q;
	int sz;
	int level = 0;
	q.push(root);
	while (!q.empty())
	{
		level++;
		sz = q.size();
		for (int i = 0; i < sz; i++) {
			node* temp = q.front();
			q.pop();

			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return level;


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif

	node* root = new_node(5);
	root->left = new_node(2);
	root->right = new_node(1);
	root->left->right = new_node(10);
	root->right->left = new_node(3);
	root->right->right = new_node(4);
	root->right->right->left = new_node(8);
	root->right->right->right = new_node(11);

	//print(root);
	cout << calculate_depth(root);
	cout << endl;
	cout << calculate_depth_recursively(root) << endl;
	int diameter = 0;
	calculate_diameter(root, diameter);
	cout << "diameter " << diameter;
}