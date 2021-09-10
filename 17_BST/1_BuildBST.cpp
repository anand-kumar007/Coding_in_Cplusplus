/*
BST are binary trees which are generally used for optiized searching

for searching bst takes O(logn) time while normal BT takes O(n) time

building a BST takes O(n^2) time and inorder traversal takes O(n) time

inorder traversal of BST gives ascendign order of Number

and hence we can use it for sorting also

Properties of BST
1. all left nodes are smaller and all right nodes are greater
    than the root node.
2. there are no duplicate elements in the BST

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *InsertBST(Node *root, int val)
{
    if (root == NULL)
    {
        Node* temp = new(nothrow) Node(val);
        return temp;
    }

    if (val < root->data)
        root->left = InsertBST(root->left, val);
    else
        root->right = InsertBST(root->right, val);

    return root;
}

void Inorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    Inorder(root->left);
    cout<<root->data<< " ";
    Inorder(root->right);

}

int main()
{
    Node* root = NULL;

    root= InsertBST(root,10);
    InsertBST(root, -25);
    InsertBST(root,50);
    InsertBST(root,23);
    InsertBST(root,4);
    InsertBST(root,11);

    Inorder(root);

    //should give -25,4,10,11,23,50
    return 0;
}