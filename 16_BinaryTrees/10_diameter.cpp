
/* count total number of nodes in a binary tree */

#include <iostream>
using namespace std;

struct Node
{
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

    int lheight = Height(root->left);
    int rheight = Height(root->right);

    return (max(lheight, rheight) + 1);
}

int calcDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lHeight = Height(root->left);
    int rHeight = Height(root->right);

    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return (max(currDiameter, max(lDiameter, rDiameter)));

    // Returning max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
}

int main()
{
    Node *root = new Node(6);

    // root->left = new Node(1);
    // root->right = new Node(2);

    // root->left->left = new Node(3);
    // root->left->right = new Node(4);

    // root->right->left = new Node(5);

    // 6 diameter
    root->left = new Node(10);
    root->left->left = new Node(10);
    root->left->left->left = new Node(10);

    root->left->right = new Node(10);
    root->left->right->right = new Node(10);
    root->left->right->right->right = new Node(10);

    //expected level order  : 0,1,2,3,4,5
    cout << calcDiameter(root);
    return 0;
}


// O(N) solution

int diameterOpt( Node *root, int *height)
{
    // lh --> Height of left subtree
    // rh --> Height of right subtree
    int lh = 0, rh = 0;

    // ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree
    int ldiameter = 0, rdiameter = 0;

    if (root == NULL)
    {
        *height = 0;
        return 0; // diameter is also 0
    }

    // Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // ldiameter
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);

    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}