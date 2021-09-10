/* 

print the spiral or zig zag traversal of the bst or any binary tree
for that matter

Time Complexity: Worst case time complexity of the above method is O(n^2). Worst case occurs in case of skewed trees.

consecutively

*/

#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int Height(Node *root);
void PrintGivenLevel(Node *root, bool left_to_right, int level);
void SpiralOrder(Node *root, bool ltr_initial);

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    root->left->right->right = new Node(7);
    root->left->right->left = new Node(6);

    root->right->right = new Node(5);

    bool ltr = true;

    SpiralOrder(root, ltr);

    return 0;
}

void PrintGivenLevel(Node *root, bool left_to_right, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
    {
        cout << root->data << " ";
        return;
    }

    //else come here

    if (left_to_right)
    {
        PrintGivenLevel(root->left, left_to_right, level - 1);
        PrintGivenLevel(root->right, left_to_right, level - 1);
    }

    else
    {
        PrintGivenLevel(root->right, left_to_right, level - 1);
        PrintGivenLevel(root->left, left_to_right, level - 1);
    }
}
void SpiralOrder(Node *root, bool ltr)
{
    int h = Height(root);

    for (int i = 1; i <= h; i++)
    {
        PrintGivenLevel(root, ltr, i);

        //toggle ltr
        ltr = !ltr;
    }
}

int Height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = Height(root->left);
    int rh = Height(root->right);

    return max(lh, rh) + 1;
}