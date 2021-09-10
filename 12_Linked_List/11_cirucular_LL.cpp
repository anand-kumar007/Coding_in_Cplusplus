/*
cicular Linked list

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

void insert_Begin(Node *&head, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    //traverse till last and then modify the links
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
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

    Node *n = new Node(val);
    Node *temp = head;

    //traverse till last and then modify the links
    while (temp->next != head)
    {
        temp = temp->next;
    }

    n->next = head;
    temp->next = n;
    return;
}

void delete_head(Node *&head)
{
    //traverse to last and then modify the pointers
    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    Node *to_delete = head;

    temp->next = head->next;
    head = head->next;

    delete to_delete;

    return;
}

void delete_node(Node *&head, int pos)
{
    // pos = pos/length(LL)
    if (pos == 1)
    {
        delete_head(head);
        return;
    }

    int count = 1;
    Node *temp = head;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *to_delete = temp->next;

    temp->next = temp->next->next;
    delete to_delete;

    return;
}

void display_CLL(Node *head)
{
    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    cout << endl;
    return;
}

int main()
{
    Node *head = NULL;

    insert_End(head, 10);
    insert_End(head, 20);
    insert_End(head, 30);
    insert_End(head, 40);
    insert_End(head, 50);

    display_CLL(head);

    int pos = 5;
    // int pos = 1;
    delete_node(head, pos);

    display_CLL(head);
    return 1;
}
/*
1->4->6->10->NULL
2->3->11->30->NULL
1->2->3->4->6->10->30->NULL

*/