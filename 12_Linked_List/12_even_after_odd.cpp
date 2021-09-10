/*
 even position elements after the odd position elements

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

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *n = new Node(val);

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

void Even_after_Odd(Node *&head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *even_start = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_start;

    //means even->next is not NULL
    //but we need that
    if (odd->next == NULL)
    {
        even->next = NULL;
    }
    else
    {
        ;
    }
    return;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    // int arr1[] = {1, 2, 3, 4, 5, 6,7};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        insert_End(head, arr1[i]);
    }

    display_LL(head);

    Even_after_Odd(head);

    display_LL(head);
    return 0;
}

/*
1->4->6->10->NULL
2->3->11->30->NULL
1->2->3->4->6->10->30->NULL

*/