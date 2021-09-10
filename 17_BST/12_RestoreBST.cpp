

/* Recover a bst given that only two nodes of it are swapped */

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Util(Node *root, Node **first, Node **last, Node **mid, Node **prev)
{
    if (root == NULL)
        return;

    //do the inorder traversal
    Util(root->left, first, last, mid, prev);

    //check for violation
    if (*prev && (root->data < (*prev)->data))
    {
        //first time violation else second time
        if (*first == NULL)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            //second time violation
            *last = root;
        }
    }

    *prev = root;
    Util(root->right, first, last, mid, prev);
}

void RestoreBST(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    //create three pointers and one temp pointer
    Node *first, *last, *mid, *prev;

    first = last = mid = prev = NULL;

    Util(root, &first, &last, &mid, &prev);

    if (first && last)
        swap(&(first->data), &(last->data));
    else if (first && mid) // swap adjacent nodes
        swap(&(first->data), &(mid->data));

    //else nodes have not been swapped,
    //tree is already bst
    return;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    /*
            4
           / \
          3   6
         /   / \
        2   5   10
    */

    Node *root = new Node(4);
    root->left = new Node(10);
    root->right = new Node(6);
    root->left->left = new Node(2);

    root->right->left = new Node(5);
    root->right->right = new Node(3);

    inorder(root);

    RestoreBST(root);

    cout << endl;
    inorder(root);
    return 0;
}

/* 
Time Complexity: O(n) 
We can solve this in O(n) time and with a single traversal of the given BST. Since inorder traversal of BST is always a sorted array, the problem can be reduced to a problem where two elements of a sorted array are swapped. There are two cases that we need to handle:
1. The swapped nodes are not adjacent in the inorder traversal of the BST. 

 For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}. 
 The inorder traversal of the given tree is 3 25 7 8 10 15 20 5 
If we observe carefully, during inorder traversal, we find node 7 is smaller than the previous visited node 25. Here save the context of node 25 (previous node). Again, we find that node 5 is smaller than the previous node 20. This time, we save the context of node 5 (the current node ). Finally, swap the two node’s values.

2. The swapped nodes are adjacent in the inorder traversal of BST.

  For example, Nodes 7 and 8 are swapped in {3 5 7 8 10 15 20 25}. 
  The inorder traversal of the given tree is 3 5 8 7 10 15 20 25 
Unlike case #1, here only one point exists where a node value is smaller than the previous node value. e.g. node 7 is smaller than node 8. 
How to Solve? We will maintain three-pointers, first, middle, and last. When we find the first point where the current node value is smaller than the previous node value, we update the first with the previous node & the middle with the current node. When we find the second point where the current node value is smaller than the previous node value, we update the last with the current node. In the case of #2, we will never find the second point. So, the last pointer will not be updated. After processing, if the last node value is null, then two swapped nodes of BST are adjacent.


*/