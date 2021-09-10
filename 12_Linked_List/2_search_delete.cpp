/*
Program to search and delete the elements from a linked list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Insert_Begin(Node *&head, int val)
{
    Node *n = new Node(val);

    n->next = head;
    head = n;
}

void Insert_End(Node *&head, int val)
{
    Node *n = new Node(val);

    //check if LL is empty
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;

    return;
}

void display_LL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;

    return;
}

bool search(Node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }

    return false;
}

void delete_HeadNode(Node *&head)
{
    Node *todelete = head;
    head = head->next;

    delete todelete;

    return;
}

void deleteNode(Node *&head, int val)
{
    // 2 corner cases
    //1. empty linked list
    //2. only one item in LL

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete_HeadNode(head);
        return;
    }

    //traverse till (n-1)th node and modify the links

    Node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    Node *todelete = temp->next;

    temp->next = temp->next->next;

    delete todelete;
}

int main()
{
    Node *head = NULL;

    Insert_Begin(head, 20);
    Insert_Begin(head, 10);
    Insert_Begin(head, 5);

    Insert_End(head, 25);
    Insert_End(head, 35);
    Insert_End(head, 45);

    display_LL(head);

    // if (search(head, 4455))
    // {
    //     cout << "found" << endl;
    // }

    // else
    //     cout << "Not found!!" << endl;

    delete_HeadNode(head);
    display_LL(head);
    delete_HeadNode(head);
    display_LL(head);

    deleteNode(head, 45);
    display_LL(head);
    return 0;
}