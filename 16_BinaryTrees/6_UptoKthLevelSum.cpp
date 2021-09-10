
/* find sum of nodes upto the Kth level */

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
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

int LevelOrder_Kth(Node *root, int k);

int main()
{
    Node *root = new Node(6);

    root->left = new Node(1);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(5);

    //expected level order  : 0,1,2,3,4,5

    int k = 2;
    cout << LevelOrder_Kth(root, k);
    return 0;
}

int LevelOrder_Kth(Node *root, int k)
{
    queue<Node *> q;

    if (root == NULL)
    {
        return -1;
    }
    int sum = 0;
    int level = 0;

    q.push(root);
    q.push(NULL);

    while (q.empty() == false && level <= k)
    {
        Node *temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            sum += temp->data;
            //If not null then analyze it's left and right
            // cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        else
        {

            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }

    return sum;
}