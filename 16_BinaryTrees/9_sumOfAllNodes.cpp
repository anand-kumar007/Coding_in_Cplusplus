
/* sum of all nodes in a binary tree */

#include <iostream>
#include <queue>
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

int sum_Nodes(Node *root);

int main()
{
    Node *root = new Node(6);

    root->left = new Node(1);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(5);

    //expected level order  : 0,1,2,3,4,5
    cout << sum_Nodes(root);
    return 0;
}

int sum_Nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lsum = sum_Nodes(root->left);
    int rsum = sum_Nodes(root->right);

    return (root->data + lsum + rsum);
}
