
/* 
check if the two given bst's are same

both structurally as well as values at each nodes
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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;

    else
    {
        bool a = root2->data == root1->data;
        bool b = isIdentical(root1->left, root2->left);
        bool c = isIdentical(root1->right, root2->right);

        if (a && b && c)
            return true;
    }

    return false;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(12);

    root->left->left = new Node(5);
    root->left->right = new Node(8);
    // ----------------

    Node *root2 = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);

    root->left->left = new Node(5);
    root->left->right = new Node(9);

    bool ans = isIdentical(root, root2);

    if (ans)
        cout << "identical" << endl;
    else
        cout << "Not identical" << endl;

    return 0;
}