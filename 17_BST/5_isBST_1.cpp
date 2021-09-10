
/* 
check if the given tree is binary search tree or not

approach 1
every node is > left child and < right child
--> this is wrong condition

approach 2
every node > max(left subtree) and < min(right subtree)

but this requires a lots of traversal(repeated one)

approach 3

just like we used the range for building the bst from preorder

minallowed, maxallowed

node > minallowed and < maxallowed

      node(minallowed,maxallowed)
        /       \
       /         \
  left(min,node)   right(node,max)

this way we can check if the whole tree is bst or not
rather than traversing the tree again and again

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

bool isBST(Node *root, Node *min, Node *max)
{
    //base tree
    if (root == NULL)
        return true;

    if (min != NULL && (root->data < min->data))
        return false;
    if (max != NULL && (root->data > max->data))
        return false;

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return (leftValid && rightValid);
}

Node *InsertBST(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = InsertBST(root->left, val);
    else
        root->right = InsertBST(root->right, val);

    return root;
}

int main()
{
    Node *root = NULL;

    // root = InsertBST(root, 10);
    // InsertBST(root, -25);
    // InsertBST(root, 50);
    // InsertBST(root, 23);
    // InsertBST(root, 4);
    // InsertBST(root, 11);

    root = new Node(4);
    root->left = new Node(3);
    // root->right = new Node(-2);
    root->right = new Node(10);

    bool ans = isBST(root, NULL, NULL);

    if (ans)
        cout << "is BST " << endl;
    else
        cout << "Not a BST " << endl;

    return 0;
}

// Time Complexity : O(n)
//  Auxiliary Space : O(1) if Function Call Stack size is not considered,
// otherwise O(n)