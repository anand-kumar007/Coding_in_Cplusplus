/* 
n--> nodes are given then total possible BST's are
2nCn/(n+1)

ie cataln of n


*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtrees = constructTrees(start, i - 1);
        vector<Node *> rightSubtrees = constructTrees(i + 1, end);

        //now that we have our left and rightsubtrees built let's form
        //a bigger tree out of them using the catalans concept

        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                Node *right = rightSubtrees[k];

                //our target
                Node *node = new Node(i);
                node->left = left;
                node->right = right;

                //push it to answer
                trees.push_back(node);
            }
        }
    }

    return trees;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int start = 1;
    int end = 3;

    vector<Node *> trees = constructTrees(start, end);

    cout << "-----------------------\n";

    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        cout << "\n";
    }

    return 0;
}