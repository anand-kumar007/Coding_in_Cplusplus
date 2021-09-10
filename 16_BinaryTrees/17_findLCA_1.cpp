

/* in this case we'll deal with the situation where
 there may not be all the given keys present in the tree
 
 there are two possibilities

1. check first if both nodes are there in the tree
2. or check while findin lca both are present in tree
 
*/

#include <iostream>
using namespace std;
class Node
{
public:
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

bool search_in_tree(Node *root, int n)
{
    if (root == NULL)
        return false;

    if (root->data == n ||
        search_in_tree(root->left, n) ||
        search_in_tree(root->right, n))
        return true;

    return false;
}

Node *Algorithm(Node *root, int n1, int n2, bool &v1, bool &v2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1)
    {
        v1 = true;
        return root;
    }

    if (root->data == n2)
    {
        v2 = true;
        return root;
    }

    //check in the left and right subtrees otherwise

    Node *left_lca = Algorithm(root->left, n1, n2, v1, v2);
    Node *right_lca = Algorithm(root->right, n1, n2, v1, v2);

    //if both are not null
    if (left_lca && right_lca)
        return root;

    if (left_lca != nullptr)
        return left_lca;

    else
        return right_lca;
}

Node *findLCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        cout << "Noting in the tree" << endl;
        return NULL;
    }
    bool v1 = false;
    bool v2 = false;

    Node *lca = Algorithm(root, n1, n2, v1, v2);

    if ((v1 && v2) || (v1 && search_in_tree(lca, n2)) || (v2 && search_in_tree(lca, n1)))
    {
        return lca;
    }

    //if none of the above
    return NULL;
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

    if (findLCA(root, 4, 5))
        cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    else
        cout << "NO ancestor" << endl;

    if (findLCA(root, 4, 6))
        cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    else
        cout << "NO ancestor" << endl;

    if (findLCA(root, 3, 4))
        cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    else
        cout << "NO ancestor" << endl;

    if (findLCA(root, 2, 4))
        cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    else
        cout << "NO ancestor" << endl;

    if (findLCA(root, 10, 2))
        cout << "\nLCA(10,2) = " << findLCA(root, 10, 4)->data;
    else
        cout << "\nNO ancestor" << endl;
}