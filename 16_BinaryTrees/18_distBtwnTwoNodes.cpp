

/* 

distance btwn any two given nodes of the tree 

find lca

d1 = findDistance(lac,n1);
d1 = findDistance(lac,n2);

return d1+d2;

but before that need to findout the lca
and there are two possibilities

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
        left = nullptr;
        right = nullptr;
    }
};

//considering the case that both exists
//otherwise we'll replace findlca code differently
Node *findLCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL ? left_lca : right_lca);
}

// distance is equal of the levels btwn the root and asked node

int findDist(Node *root, int k, int distTillNow)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return distTillNow;
    }

    int left_dist = findDist(root->left, k, distTillNow + 1);
    if (left_dist != -1)
    {
        return left_dist;
    }

    else
        return findDist(root->right, k, distTillNow + 1);
}

int DistBtwnNodes(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return -1;
    }

    Node *lca = findLCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
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

    // int res = DistBtwnNodes(root, 5, 7);
    // int res = DistBtwnNodes(root, 5, 3);
    int res = DistBtwnNodes(root, 1, 4);

    cout << res << endl;

    return 0;
}