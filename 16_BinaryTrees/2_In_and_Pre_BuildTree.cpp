
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
Node *BuildTree(int inorder[], int preorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    static int idx = 0;
    int curr = preorder[idx];
    idx++;

    Node *root = new Node(curr);

    if (start == end)
    {
        return root;
    }

    int pos = search(inorder, curr, start, end);
 

    root->left = BuildTree(inorder, preorder, start, pos - 1);
    root->right = BuildTree(inorder, preorder, pos + 1, end);

    return root;
}

int main()
{
    // int inorder[] = {1, 2, 4, 3, 5};
    // int preorder[] = {4, 2, 1, 5, 3};

    int inorder[] = {3,1,4,0,5,2};
    int preorder[] = {0,1,3,4,2,5};

    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node *root = BuildTree(inorder, preorder, 0, n - 1);

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
preorder traversal 

    Time Complexity: O(n^2). The worst case occurs when the tree is left-skewed. Example Preorder and Inorder traversals for worst-case are {A, B, C, D} and {D, C, B, A}. 
*/