/*
this approach takes O(N^2) time 
we can optimize it using postorder traversal
for the solution

*/
#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool Util_isBST(Node *root, Node *min, Node *max)
{
    //base tree
    if (root == NULL)
        return true;

    if (min != NULL && (root->data < min->data))
        return false;
    if (max != NULL && (root->data > max->data))
        return false;

    bool leftValid = Util_isBST(root->left, min, root);
    bool rightValid = Util_isBST(root->right, root, max);

    return (leftValid && rightValid);
}

bool isBST(Node *root)
{
    return Util_isBST(root, NULL, NULL);
}

int Size_of_BST(Node *root)
{
    if (root == NULL)
        return 0;

    int l = Size_of_BST(root->left);
    int r = Size_of_BST(root->right);

    return l + r + 1;
}

int LargestBST(Node *root)
{
    if (root == NULL)
        return 0;

    if (isBST(root))
        return Size_of_BST(root);

    return max(LargestBST(root->left), LargestBST(root->right));
}

int main()
{
    /* Let us construct the following Tree
        50
        /  \
       10   60
      / \   /  \
     5  20 55 70
           /   / \
         45   65 80
    */

    Node *root = new Node(50);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(55);
    root->right->left->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    /* The complete tree is not BST
    as 45 is in right subtree of 50.
    The following subtree is the largest BST
        60
        / \
     55   70
     /    / \
    45   65 80
    */
    cout << " Size of the largest BST is " << LargestBST(root);

    // cout<<isBST(root);
    return 0;
}