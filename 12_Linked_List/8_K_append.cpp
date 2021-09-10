/*
k append program in linked list

k=3

1->2->3->4->5->6->NULL

last k items should be placed in the beginning

4->5->6->1->2->3

soln :
put threee pointers
newHead @ 4
newTail @ 3
and tail @ 6
then modify these pointers
newHead->next = NULL;
tail->next = head;
head = newHead;

done
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

int LL_length(Node *head)
{
    int l = 0;
    while (head->next != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}

Node *K_appned(Node *&head, int k)
{
    Node *newHead;
    Node *newTail;
    Node *tail = head;

    int L = LL_length(head);
    k = k % L;
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == L - k)
        {
            newTail = tail;
        }

        if (count == L - k + 1)
        {
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }

    //modify the links now

    newTail->next = NULL;
    tail->next = head;
    head = newHead;

    return head;
}

int main()
{
    Node *head = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        insert_End(head, arr[i]);
    }
    cout << LL_length(head) << endl;
    display_LL(head);

    int k = 1;

    head = K_appned(head, k);
    display_LL(head);

    return 0;
}