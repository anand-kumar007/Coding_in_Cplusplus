

/*
given a sorted array you are supposed to create 
a height balanced binary tree from it
Time Complexity: O(n)

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.

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

Node *HBST_Sorted(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    Node *root = new (nothrow) Node(arr[mid]);

    root->left = HBST_Sorted(arr, start, mid - 1);
    root->right = HBST_Sorted(arr, mid + 1, end);

    return root;
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = n - 1;

    Node *root = NULL;
    root = HBST_Sorted(arr, start, end);

    Preorder(root);

    return 0;
}