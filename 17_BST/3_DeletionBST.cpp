

/*
searching in a binary search tree
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

Node *InsertBST(Node *root, int val)
{
    if (root == NULL)
    {
        Node *temp = new (nothrow) Node(val);
        return temp;
    }

    if (val < root->data)
        root->left = InsertBST(root->left, val);
    else
        root->right = InsertBST(root->right, val);

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

Node *inorderSucc(Node *root)
{
    //loop down to leftmost node in the bst(cz that'll be
    //our inorder successor)
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

Node *DeleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    //first search in which half we've our key to be deleted
    if (key > root->data)
        root->right = DeleteNode(root->right, key);
    else if (key < root->data)
        root->left = DeleteNode(root->left, key);

    //if key to be deleted is the root node
    else
    {
        //case 1: no left and right child
        if (root->left == NULL && root->right == NULL)
            return NULL;

        //case 2: only one child
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        //case 3: two childrens
        //find inorderSucc of this temp node and delete that
        //after swapping that successor with root to be deleted

        else
        {
            // Get the inorder successor
            // (smallest in the right subtree)
            Node *succ = inorderSucc(root->right);

            root->data = succ->data;

            //now problem reduces to deleting the succ
            root->right = DeleteNode(root->right, succ->data);
        }
    }

    return root;
}

int main()
{
    Node *root = NULL;

    root = InsertBST(root, 10);
    InsertBST(root, -25);
    InsertBST(root, 50);
    InsertBST(root, 23);
    InsertBST(root, 4);
    InsertBST(root, 11);

    Inorder(root);
    //should give -25,4,10,11,23,50

    cout << "\n--------------------------\n";
    root = DeleteNode(root, -25);
    Inorder(root);

    return 0;
}