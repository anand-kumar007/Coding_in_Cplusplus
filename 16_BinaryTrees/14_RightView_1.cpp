/*
here the approach is just visite the right subtree first
and mark that level visited

if for any particular node right subtree doesn't exists and 
there is no nodes on right of it in that level then it's level
need to be increased otherwise during recursion same(as of previous)
right subtree's level is used

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

vector<bool> visited(10, false);

void RightView(Node *root, vector<bool> &visited, int i)
{
    if (root == NULL)
    {
        return;
    }

    if (visited[i] == false)
    {
        cout << root->data << " ";
        visited[i] = true;
    }
    bool flag = false;
    if (root->right)
    {
        RightView(root->right, visited, ++i);
        flag = true;
    }
    if (root->left)
    {
        if (flag)
            RightView(root->left, visited, i);
        else
            RightView(root->left, visited, ++i);
    }

    return;
}

int main()
{
    Node *root = new Node(1);

    // root->left = new Node(2);
    // root->right = new Node(3);

    // root->left->left = new Node(4);
    // root->right->left = new Node(5);
    // root->right->right = new Node(6);
    // root->right->left->left = new Node(7);

    //another tree
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(6);

    int i = 0;
    RightView(root, visited, i);

    return 0;
}