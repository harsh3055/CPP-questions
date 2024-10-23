// balaced tree is that tree in which the difference in the height of the left and right subtree
// of any node is not greater than 1;

#include<iostream>
#include<vector>
using namespace std;

class node {
public:
	int data;
	node * left;
	node *right;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

};


int check_balanced(node* root) {
	if (!root)
		return 0;

	int left_height = check_balanced(root->left);

	if (left_height == -1)
		return -1;

	int right_height = check_balanced(root->right);

	if (right_height == -1)
		return -1;

	if (abs(left_height - right_height > 1))
		return -1;

	return max(left_height, right_height) + 1;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	node* root = new node(3);
	root->left = new node(7);
	root->right = new node(8);
	root->right->left = new node(1);
	root->right->right = new node(0);

	int is_balanced = check_balanced(root) != -1 ? 12 : 0;
	cout << is_balanced;
}