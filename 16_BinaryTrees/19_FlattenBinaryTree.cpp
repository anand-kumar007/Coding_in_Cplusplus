

/* 
FLATTEN A BINARY TREE (in place)

after flattening left of each node should point to 
NULL and right should point to next node in the PREORDER 
sequence

You're not allowed to use any other data structure
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void Flatten(Node *&root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        //single node so no need to flattten
        return;
    }

    //if left is null then no need to do flattening
    if (root->left != NULL)
    {
        //flatten left subtree recursively
        Flatten(root->left);

        //now base case has arrived
        Node *temp = root->right;

        root->right = root->left;
        root->left = NULL;

        //now traverse to tail of newly flatten tree and append
        //temp there
        Node *counter = root->right;
        while (counter->right != NULL)
        {
            counter = counter->right;
        }

        counter->right = temp;
    }

    //call for righ subtree
    Flatten(root->right);
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << ' ';

    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Flatten(root);

    //preorder should be
    // 1,2,4,5,3,6,7
    Preorder(root);
    return 0;
}