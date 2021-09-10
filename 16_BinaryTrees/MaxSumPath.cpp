

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

// a recusive function
int UtilMaxPathSum(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = UtilMaxPathSum(root->left, ans);
    int right = UtilMaxPathSum(root->right, ans);

    // maxm of four path we need to consider here
    // 1. max(root,root+left+right) ==> either root only or the whole path
    // 2. max(root+left, root+righ) ==> either rootandleft or rootandright

    int NodeMax = max(max(left + right + root->data, root->data),
                      max(root->data + left, root->data + right));

    ans = max(ans, NodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    //over(will be used in recusion calls not he actual ans)
    return singlePathSum;
}

int MaxSumPath(Node *root)
{
    int ans = INT_MIN;

    UtilMaxPathSum(root, ans);

    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);

    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << MaxSumPath(root) << endl;
    return 0;
}