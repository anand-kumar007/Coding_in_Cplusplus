
/* level order traversal using doubly ended queue */

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

void LevelOrder(Node *root);

int main()
{
    Node *root = new Node(0);

    root->left = new Node(1);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(5);

    root->right->right = new Node(10);
    root->left->left->left = new Node(34);
    root->left->left->right = new Node(40);

    //expected level order  : 0,1,2,3,4,5

    LevelOrder(root);
    return 0;
}

void LevelOrder(Node *root)
{
    queue<Node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);
    q.push(NULL);

    while (q.empty() == false)
    {
        if (q.front() != NULL)
        {
            cout << q.front()->data << " ";
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }

            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        else
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}