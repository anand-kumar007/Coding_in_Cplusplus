

/*
using level order traversal approach


we'll traverse our tree level wise and will print the 
right most node of every level

O(N) space 
O(N) time

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



void LeftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        //represents how many nodes in each level

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " ";
            }

            //insert left and right items

            if (curr->left)
            {
                q.push(curr->left);
            }

            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
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

    LeftView(root);

    return 0;
}