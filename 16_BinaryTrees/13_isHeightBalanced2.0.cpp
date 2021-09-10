

/* 
height balanced tree

if for each node
The difference between heights of left subtree and right subtree is not more than 1. 
then it is height balanced otherwise  not


instead of using height method separately we can pass a pointer to height
this way complexity of time reduces to O(N) from O(N^2) earlier 
*/

// #include <iostream>
// #include <cstdlib>
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

int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = Height(root->left);
    int rh = Height(root->right);

    return max(lh, rh) + 1;
}

bool isHeightBalanced(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;

    if (isHeightBalanced(root->left, &lh) == false)
    {
        return false;
    }

    if (isHeightBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(4);
    root->left->right = new Node(7);

    root->right->left = new Node(9);

    //make it Not height balanced
    // root->left->left->left = new Node(23);
    // root->left->left->left->left = new Node(21);

    int height = 0;

    bool ans = isHeightBalanced(root, &height);

    if (ans)
    {
        cout << "yes! tree is height balanced" << endl;
    }
    else
    {
        cout << "No! tree is not height balanced" << endl;
    }
    return 0;
}