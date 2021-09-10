/*
Method2
O(N) time only 
The trick is to set a range {min .. max} for every Node. Initialize the range as {INT_MIN .. INT_MAX}. The first Node will definitely be in range, so create a root Node. To construct the left subtree, set the range as {INT_MIN …root->data}. If a value is in the range {INT_MIN .. root->data}, the values are part of the left subtree. To construct the right subtree, set the range as {root->data..max .. INT_MAX}. 
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

Node *constructTreeUtil(int pre[], int *preIndex, int key,
                        int min, int max, int size)
{

    if (*preIndex >= size)
        return NULL;

    Node *root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = new Node(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            // {min .. key} . since root.data = key passing key
            root->left = constructTreeUtil(pre, preIndex,
                                           pre[*preIndex],
                                           min, key, size);
        }
        if (*preIndex < size)
        {

            // {key..max} will go in right

            root->right = constructTreeUtil(pre, preIndex,
                                            pre[*preIndex],
                                            key, max, size);
        }
    }

    return root;
}

Node *BuildTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0],
                             INT_MIN, INT_MAX, size);
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
    int pre[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(pre) / sizeof(pre[0]);

    Node *root = NULL;

    root = BuildTree(pre, n);

    Inorder(root);
    return 0;
}
