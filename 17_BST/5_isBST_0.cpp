/* 
this program will run a bit slower than our third approach
since everytime we need to check the max(leftsubtree)
and min(rightsubtree) everytime for each node


*/

#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int max_of_left(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    int maximum = root->data;

    int leftmax = max_of_left(root->left);
    int rightmax = max_of_left(root->right);

    maximum = max(max(leftmax, rightmax), maximum);

    return maximum;
}

int min_of_right(Node *root)
{
    if (root == NULL)
        return INT_MAX;

    int mini = root->data;

    int leftmini = min_of_right(root->left);
    int rightmini = min_of_right(root->right);

    mini = min(min(leftmini, rightmini), mini);

    return mini;
}

bool isBST(Node *root)
{
    if (root == NULL)
        return true;

    if ((root->data < max_of_left(root->left)))
        return false;

    if ((root->data > min_of_right(root->right)))
        return false;

    bool leftValid = isBST(root->left);
    bool rightValid = isBST(root->right);

    return leftValid && rightValid;
}

Node *InsertBST(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = InsertBST(root->left, val);
    else
        root->right = InsertBST(root->right, val);

    return root;
}

int main()
{
    Node *root = NULL;

    // root = InsertBST(root, 10);
    // InsertBST(root, -25);
    // InsertBST(root, 50);
    // InsertBST(root, 23);
    // InsertBST(root, 4);
    // InsertBST(root, 11);

    root = new Node(4);
    root->left = new Node(3);
    // root->right = new Node(-2);
    root->right = new Node(10);

    bool ans = isBST(root);

    if (ans)
        cout << "is BST " << endl;
    else
        cout << "Not a BST " << endl;

    return 0;
}