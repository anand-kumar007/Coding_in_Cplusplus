/*
make two linked list intersect and find the instersection point
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

void make_intersect(Node *&head1, Node *&head2, int pos)
{
    pos--;
    Node *temp1 = head1; //being the larger Linked list

    while (pos != 0)
    {
        temp1 = temp1->next;
        pos--;
    }

    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;

    return;
}

int LL_length(Node *head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }

    return l;
}

bool find_Intersection(Node *head1, Node *head2)
{
    int L1 = LL_length(head1);
    int L2 = LL_length(head2);

    int d = 0;
    Node *ptr1 = NULL;
    Node *ptr2 = NULL;

    if (L1 > L2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = L1 - L2;
    }

    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = L2 - L1;
    }

    while (d-- && ptr1 != NULL)
    {
        ptr1 = ptr1->next;
    }

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            cout << ptr2->data << endl;
            return true;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return false;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {9, 10};

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

    int pos = 5;
    // make_intersect(head1,head2,pos);

    if (find_Intersection(head1, head2))
    {
        cout << "Has intersecton !!" << endl;
    }
    else
    {
        cout << "No intersection !!" << endl;
    }
    return 0;
}

/*

1->2->3->4->5->6->7->NULL
9->10->NULL
5
Has intersecton !!

*/