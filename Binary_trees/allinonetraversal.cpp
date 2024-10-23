// here we are making all the preorder inorder and postorder tranversal using a one stack

//algorithm
// first make a stack of {node, value} pair
// insert the root with value 1
// iterate through the stack until it gets empty
// if you found the top node in the stack with value 1 just add it to the preorder vector

// push the same node with doing plus one to the int value
// also insert the left node if there is any with value of 1

// if you found the top node in the stack with value 2 just add it to the inorder
// push the same node in the stack but with incremented value
// also insert the rght node if there us any with valye od 1

// if you enocunter that top node has a value of 3 just put it in the postorder traversal

#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> allinOne(node *root)
{   // this is the answer vector whcih will contain all the three vector inorder preorder and postorder

    vector<vector<int>> ans;
    stack<pair<node *, int>> st;

    // pushing in the stack the root with the rank as one;

    st.push({root, 1});
    vector<int> pre, in, post;

    if (root == NULL)
        return ans;

    while (st.empty() == false)
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);

    return ans;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> ans = allinOne(root);

    for (int i{0}; i < ans.size(); i++)
    {
        for (int j{0}; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}