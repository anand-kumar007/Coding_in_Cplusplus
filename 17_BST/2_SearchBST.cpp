

/*
searching in a binary search tree
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
        Node *temp = new (nothrow) Node(val);
        return temp;
    }

    if (val < root->data)
        root->left = InsertBST(root->left, val);
    else
        root->right = InsertBST(root->right, val);

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

Node *Search(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->data)
        return root;

    if (key > root->data)
        return Search(root->right, key);
    else
        return Search(root->left, key);
}

int main()
{
    Node *root = NULL;

    root = InsertBST(root, 10);
    InsertBST(root, -25);
    InsertBST(root, 50);
    InsertBST(root, 23);
    InsertBST(root, 4);
    InsertBST(root, 11);

    Inorder(root);
    //should give -25,4,10,11,23,50

    cout << "\n--------------------------\n";

    if (Search(root, 250))
        cout << "key exists!!" << endl;
    else
        cout << "key doesn't exists!!" << endl;

    return 0;
}