
/* count total number of nodes in a binary tree */

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

int count_Nodes(Node *root);

int main()
{
    Node *root = new Node(6);

    root->left = new Node(1);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(5);

    //expected level order  : 0,1,2,3,4,5
    cout << count_Nodes(root);
    return 0;
}

int count_Nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + count_Nodes(root->left) + count_Nodes(root->right);
}
