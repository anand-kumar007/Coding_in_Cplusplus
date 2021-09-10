/*
Merge two linked list which are sorted 
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

Node *merge_LL(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;

    Node *dummy_node = new Node(-1);
    Node *p3 = dummy_node;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }

        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
    }

    //look
    return dummy_node->next;
}

Node *merge_Recursive(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head2;
    }

    Node *result;

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge_Recursive(head1->next, head2);
    }

    else
    {
        result = head2;
        result->next = merge_Recursive(head1, head2->next);
    }

    return result;
}

int main()
{
    int arr1[] = {1, 4, 6, 10};
    int arr2[] = {2, 3, 11, 30};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head1 = NULL;
    Node *head2 = NULL;

    for (int i = 0; i < n1; i++)
    {
        insert_End(head1, arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        insert_End(head2, arr2[i]);
    }

    display_LL(head1);
    display_LL(head2);

    // Node *newHead = merge_LL(head1, head2);
    Node *newHead = merge_Recursive(head1, head2);

    display_LL(newHead);
    return 0;
}

/*
1->4->6->10->NULL
2->3->11->30->NULL
1->2->3->4->6->10->30->NULL

*/