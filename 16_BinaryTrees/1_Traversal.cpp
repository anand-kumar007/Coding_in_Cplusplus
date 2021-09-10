/* 
tree traversals
1. preorder
    root
    left subtree
    right subtree

2. inorder 
    left subtree
    root
    right subtree

3. post order
    
   left subtree
   right subtree
   root

*/

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

void PreOrder(Node *root);
void InOrder(Node *root);
void PostOrder(Node *root);

int main()
{
    Node *root = new Node(1);

    root->left = new Node(10);
    root->right = new Node(90);

    root->left->left = new Node(23);
    root->left->right = new Node(2);

    root->right->left = new Node(40);
    root->right->right = new Node(33);

    // root->left->left->left = new Node(10);
    // root->left->right->right =new Node(100);

    // root->right->left->left = new Node(50);
    // root->right->left->right = new Node(88);

    cout << "Preoder : ";
    PreOrder(root);

    cout << "\nInOrder : ";
    InOrder(root);

    cout << "\nPostOrder : ";
    PostOrder(root);

    return 0;
}

/* 

 tree
      ----
       1    <-- root
     /   \
    10      90  
  /   \     / \
 23     2  40  33    <-- leaves
 
 */

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
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

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

/* 
in this data structure data is stored int the form of hierarchy
in the form of levels

properties :

1. maxm nodes at level L --> 2^L

eg : level 0 --> max nodes = 1
     level 2 --> max nodes = 2
     level 2 --> max nodes = 4

2.  maxm nodes in a tree with height H --> (2^H) - 1

    level 0 (means height(H) = 1) --> max nodes 2^1 -1 = 1 
    level 1 (means height(H) = 2) --> max nodes 2^2 -1 = 3 
    level 2 (means height(H) = 3) --> max nodes 2^3 -1 = 7 

3. for storing N nodes minimum height(minimum levels) = Log2(N+1)

    just take the log2 of 2nd property

4. a binary tree with L leaves must have at least Log2(N+1) number of 
   levels


*/