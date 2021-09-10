
/* 
Time Complexity: The time complexity of the above solution is O(n) as the method does a simple tree traversal in a bottom-up fashion. 
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    // always use initialization list rather than assignment
    //for constructors for improved performance
    Node(int val) : data(val), left(NULL), right(NULL){};
};

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

    //check for left subtree

    Node *lans = findLCA(root->left, n1, n2);
    Node *rans = findLCA(root->right, n1, n2);

    // if our intiuition is correct means one key is
    // in left and other in right then root will be the LCA
    if (lans && rans)
    {
        //if both are non-null
        return root;
    }

    //otherwise the LCA would be either lans or rans

    if (lans != NULL)
    {
        return lans;
    }
    else
    {
        return rans;
    }
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

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->data;

    // note that this would work in case of if both keys are present
    //for other case we can go for two boolean flag values just to see

    return 0;
}