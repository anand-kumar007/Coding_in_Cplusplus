
/*
building a binary search tree from preorder traversal

this approach needs 
space --> O(N) for the inorder building
time ---> O(N^2) for algorithm

this is fine in case of Binary trees but 
with Binary search tree we can optimize it to 

O(N) time alone
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int findPos(int in[], int key, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (key == in[i])
            return i;
    }

    return -1;
}

Node *BuildBST(int pre[], int in[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    static int idx = 0;
    int key = pre[idx];
    idx++;

    Node *root = new Node(key);
    //search for the key in the inorder sequence
    int pos = findPos(in, key, start, end);
    root->left = BuildBST(pre, in, start, pos - 1);
    root->right = BuildBST(pre, in, pos + 1, end);

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    Node *root = NULL;

    int pre_arr[] = {7, 5, 4, 6, 8, 9};
    int in_arr[] = {4, 5, 6, 7, 8, 9};

    int n = 6;
    int start = 0, end = n - 1;

    root = BuildBST(pre_arr, in_arr, start, end);
    Inorder(root);
    return 0;
}