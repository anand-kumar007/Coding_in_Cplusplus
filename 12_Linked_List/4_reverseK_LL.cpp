/*
reverse a linked list by k elements each
eg: 

1->2->3->4->5->6

k=2

2->1->4->3->6->5

just reverse the first k elements using iterative way
and call the recusion from (k+1)th elements

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
}

//reverseK Linked List

Node *Reverse_K(Node *&head, int k)
{
    Node *CurrPtr = head;
    Node *PrevPtr = NULL;
    Node *NextPtr;

    int count = 0;

    while (CurrPtr != NULL && count < k)
    {
        NextPtr = CurrPtr->next;

        CurrPtr->next = PrevPtr;

        PrevPtr = CurrPtr;
        CurrPtr = NextPtr;

        count++;
    }

    //join them since head(will remain unaffected) and from (k+1)th
    //element call the recursion which will be pointed by nextptr

    if (NextPtr != NULL)
    {
        head->next = Reverse_K(NextPtr, k);
    }

    //bcz prevptr points to last node or the newHead of reversed linked list
    return PrevPtr;
}

int main()
{
    Node *head = NULL;

    insert_End(head, 1);
    insert_End(head, 2);
    insert_End(head, 3);
    insert_End(head, 4);
    insert_End(head, 5);
    insert_End(head, 6);
    insert_End(head, 7);

    display_LL(head);

    int k = 3;
    Node *newHead = Reverse_K(head, k);

    display_LL(newHead);

    return 0;
}