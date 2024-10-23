#include<iostream>
#include<vector>
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
//time complexity  = O(n)
// space complexity = O(n) auxillary stack
// in skew tree it goes to o(n) worst case
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        //base case
        if (root == NULL or root == p or root == q)
                return root;

        Node* left = lowestCommonAncestor(root->left, p , q);
        Node * right = lowestCommonAncestor(root->right , p, q);

        if (left == NULL)
                return right;
        else if ( right == NULL)
                return left;

        else
                return root;
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

        Node * left = root->left->right;
        Node * right = root->left->left;

        Node *temp = lowestCommonAncestor(root, left, right);
        cout << temp->val;

}