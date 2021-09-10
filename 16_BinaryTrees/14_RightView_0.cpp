
/* 
The problem can be solved using simple recursive traversal. We can keep track of level of a node by passing a parameter to all recursive calls. The idea is to keep track of maximum level also. And traverse the tree in a manner that right subtree is visited before left subtree.

Whenever we see a node whose level is more than maximum level so far, we print the node because this is the last node in its level (Note that we traverse the right subtree before left subtree).

This is more easy to understand 
currlevel will take care of everything and since we are using 
the by refernce for maxlevel so far that makes our work more easy

*/

#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};



void RightView(Node *root, int currLevel, int &maxlevel)
{
    if (root == NULL)
    {
        return;
    }

    if (currLevel > maxlevel)
    {
        cout << root->data << " ";
        maxlevel = currLevel;
    }

    if (root->right)
    {
        RightView(root->right, currLevel + 1, maxlevel);
    }
    if (root->left)
    {
        RightView(root->left, currLevel + 1, maxlevel);
    }

    return;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    //another tree
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->left->left = new Node(6);

    int maxlevel = -1;
    int currlevel = 0;
    RightView(root, currlevel, maxlevel);

    return 0;
}