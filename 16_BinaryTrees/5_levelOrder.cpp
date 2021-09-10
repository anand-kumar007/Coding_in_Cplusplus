
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
        Node *temp = q.front();

        q.pop();
        if (temp != NULL)
        {
            //if not null then print its data
            //If not null then analyze it's left and right
            cout << temp->data << " ";
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
            }
        }
    }
}

/* 

    Time Complexity: O(n) where n is the number of nodes in the binary tree 
Space Complexity: O(n) where n is the number of nodes in the binary tree 

*/