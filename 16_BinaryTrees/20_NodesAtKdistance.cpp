

/* 
print all nodes at a distance of K from the given node
in the tree

There are two types of nodes to be considered. 
1) Nodes in the subtree rooted with target node. For example if the target node 
is 8 and k is 2, then such nodes are 10 and 14. 

2) Other nodes, may be an ancestor of target, or a node in some other subtree. 
For target node 8 and k is 2, the node 22 comes in this category.

Finding the first type of nodes is easy to implement. Just traverse subtrees
How to find nodes of second type? For the output nodes not lying 
in the subtree with the target node as the root, we must go 
through all ancestors. For every ancestor, 

we find its distance from target node, let the distance be d, 
now we go to other subtree (if target was found in left subtree, 
then we go to right subtree and vice versa) of the ancestor 
and find all nodes at k-d distance from the ancestor.

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

void printSubtree(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << ' ';
    }

    printSubtree(root->left, k - 1);
    printSubtree(root->right, k - 1);
}

int NodeAtKdistance(Node *root, int target, int k)
{
    if (root == NULL || k < 0)
    {
        return -1; //no valid distnce for printing
    }

    if (root->data == target)
    {
        printSubtree(root, k);
        return 0;
    }

    //check for left and right side of the root for the target

    int dl = NodeAtKdistance(root->left, target, k);
    if (dl != -1)
    {
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's left child from target
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            //our root is ancestor(so for ancestor right)
            // Else go to right subtree and print all k-dl-2 distant nodes
            // Note that the right child is 2 edges away from left child
            printSubtree(root->right, k - dl - 2);

        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }

    int dr = NodeAtKdistance(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << " ";
        else
            printSubtree(root->left, k - dr - 2);

        return 1 + dr;
    }

    return -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->left->left->right->right = new Node(9);

    root->right->left = new Node(3);
    root->right->right = new Node(4);

    //   printSubtree(root,2);
    int target = 6;
    int k = 2;

    int n = NodeAtKdistance(root, target, k);

    return 0;
}