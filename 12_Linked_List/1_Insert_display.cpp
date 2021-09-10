/*
Program to display create it and Linked list
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

void Insert_End(Node *&head, int val)
{
    Node *n = new (nothrow) Node(val);

    if (!n)
    {
        cout << "Not enough memory!!" << endl;
        return;
    }

    //check for empty linked list
    if (head == NULL)
    {
        head = n;
        return;
    }

    //traverse till last
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    return;
}

void Insert_Begin(Node *&head, int val)
{
    Node *n = new (nothrow) Node(val);

    if (!n)
    {
        cout << "not enough memory" << endl;
        return;
    }

    n->next = head;
    head = n;

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

int main()
{
    Node *head = NULL;
    Insert_End(head, 10);
    Insert_End(head, 20);
    Insert_End(head, 30);
    Insert_End(head, 40);
    Insert_End(head, 50);

    display_LL(head);

    Insert_Begin(head, 5);
    Insert_Begin(head, 2);

    display_LL(head);
    return 0;
}