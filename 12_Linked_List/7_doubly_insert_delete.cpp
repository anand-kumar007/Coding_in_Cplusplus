/* 
program for inserting and deleting the nodes
in a doubly linked list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insert_Begin(Node *&head, int val)
{
    Node *n = new Node(val);

    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;

    return;
}

void insert_End(Node *&head, int val)
{
    if (head == NULL)
    {
        insert_Begin(head, val);
        return;
    }

    //traverse till last
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *n = new Node(val);

    temp->next = n;
    n->prev = temp;

    return;
}

void display_DLL(Node *head)
{
    cout << "NULL";
    while (head != NULL)
    {
        cout << "<-" << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;

    return;
}

void delete_head(Node *&head)
{
    Node *to_delete = head;

    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete to_delete;
}

void delete_Node(Node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }

    if (pos == 1)
    {
        delete_head(head);
        return;
    }

    //traverse to that node(which is to be deleted)
    int count = 1;
    Node *temp = head;

    while (temp->next != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    return;
}

int main()
{
    Node *head = NULL;

    insert_Begin(head, 10);
    insert_End(head, 20);
    insert_End(head, 30);
    insert_End(head, 40);
    insert_End(head, 50);
    insert_End(head, 60);

    display_DLL(head);

    int pos = 1;
    delete_Node(head, pos);

    display_DLL(head);
    return 0;
}