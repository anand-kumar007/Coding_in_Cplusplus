

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
void InOrder(Node *root);

int search(int inorder[], int curr, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }

    return -1;
}
Node *BuildTree(int inorder[], int postorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    //since idx = n-1 initially
    static int idx = end;

    int curr = postorder[idx];
    idx--;

    Node *root = new Node(curr);

    if (start == end)
    {
        return root;
    }

    int pos = search(inorder, curr, start, end);
    

    root->right = BuildTree(inorder, postorder, pos + 1, end);
    root->left = BuildTree(inorder, postorder, start, pos - 1);

    return root;
}

int main()
{
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int postorder[] = {3, 4, 1, 5, 2, 0};

    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node *root = BuildTree(inorder, postorder, 0, n - 1);

    cout << "\nInOrder : ";
    InOrder(root);
    return 0;
}

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

/* 
Build a tree using inorder and 
postorder traversal 

    Time Complexity: O(n^2). The worst case occurs when the tree is left-skewed. Example postorder and Inorder traversals for worst-case are {A, B, C, D} and {D, C, B, A}. 
*/

