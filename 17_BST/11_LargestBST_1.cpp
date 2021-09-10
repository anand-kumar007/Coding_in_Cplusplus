/* 
here we are using preorder traversal kindo of thing

and we are analyzing the things in bottom up fashion

and for every node we are maintaining five information

and accordingly we are maininting those values
*/

#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

struct Info
{
    int size;
    int min;
    int max;
    int ans; //largest bst size
    bool isbst;

    // Info()
    // {
    //     size = 0;
    //     min = INT_MAX;
    //     max = INT_MIN;
    //     ans = 0;
    //     isbst = true;
    // }
};

Info LargestBST(Node *root)
{
    if (root == NULL)
        return {0, INT_MAX, INT_MIN, 0, true};

    //another base condition would be for just the single node
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    //algo comes here
    Info leftOne = LargestBST(root->left);
    Info RightOne = LargestBST(root->right);

    Info currOne;
    currOne.size = leftOne.size + RightOne.size + 1;

    //update the info of curr Node only if it's right,left,and node itself
    //satisfies the condition of isBST
    if (leftOne.isbst && RightOne.isbst &&
        (leftOne.max < root->data && RightOne.min > root->data))
    {
        currOne.ans = currOne.size;
        currOne.isbst = true;
        currOne.max = RightOne.max;
        currOne.min = leftOne.min;

        return currOne;
    }

    //else
    currOne.ans = max(leftOne.ans, RightOne.ans);
    currOne.isbst = false;

    return currOne;
}

int main()
{
    /* Let us construct the following Tree
        50
        /  \
       10   60
      / \   /  \
     5  20 55 70
           /   / \
         45   65 80
    */

    Node *root = new Node(50);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(55);
    root->right->left->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    /* The complete tree is not BST
    as 45 is in right subtree of 50.
    The following subtree is the largest BST
        60
        / \
     55   70
     /    / \
    45   65 80
    */
    cout << " Size of the largest BST is " << LargestBST(root).ans;

    return 0;
}
