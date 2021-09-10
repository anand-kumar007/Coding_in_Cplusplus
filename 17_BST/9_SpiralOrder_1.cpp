
/* 

print the spiral or zig zag traversal of the bst or any binary tree
for that matter

1. using 2 stacks 
while(s1 and s2 are not empty)
    while(s1 not empty)
    while (s2 not empty)
push right and left child of node to s1
and left and right child of node to s2

consecutively
s1 shows currlevel stack 
and s2 shows nextlevel stack

spiral order traversal in O(n) time and O(n) extra space.
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

void SpiralOrder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st1;
    stack<Node *> st2;

    st1.push(root);
    Node *curr = NULL;

    while (!st1.empty() || !st2.empty())
    {

        while (!st1.empty())
        {
            curr = st1.top();
            st1.pop();
            cout << curr->data << " ";
            //its left right
            if (curr->left != NULL)
                st2.push(curr->left);
            if (curr->right != NULL)
                st2.push(curr->right);
        }

        while (!st2.empty())
        {
            curr = st2.top();
            st2.pop();
            cout << curr->data << " ";

                       //it's right left
            if (curr->right != NULL)
                st1.push(curr->right);
            if (curr->left != NULL)
                st1.push(curr->left);
        }
    }

    return;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    root->left->right->right = new Node(7);
    root->left->left = new Node(6);

    root->right->right = new Node(5);

    SpiralOrder(root);

    return 0;
}