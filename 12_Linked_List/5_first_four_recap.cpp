/* all recap of whatever you have learnt in the last day */

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

bool search(Node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

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

void delete_head(Node *&head)
{
    Node *todelete;
    todelete = head;

    delete todelete;
    head = head->next;

    return;
}
void delete_node(Node *&head, int val)
{
    //traverse till (n-1)th node

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL || head->data == val)
    {
        delete_head(head);
        return;
    }

    Node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

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

Node *reverse_LL(Node *&head)
{
    //itertaive way!!
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *NextPtr;

    while (curr != NULL)
    {
        NextPtr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = NextPtr;
    }

    //head of the new LL
    return prev;
}

Node *Recursive_reverse_LL(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = Recursive_reverse_LL(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

Node *ReverseK_LL(Node *&head, int k)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *NextPtr;

    int count = 0;

    while (curr != NULL && count < k)
    {
        NextPtr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = NextPtr;
        count++;
    }

    //call the recursion from (k+1)th element
    //and join these two (head woun't change from above code)

    if (NextPtr != NULL)
    {
        head->next = ReverseK_LL(NextPtr, k);
    }

    //return  the new head
    return prev;
}

int main()
{
    Node *head = NULL;

    insert_End(head, 10);
    insert_End(head, 20);
    insert_End(head, 30);
    insert_End(head, 40);
    insert_End(head, 50);
    insert_End(head, 60);

    display_LL(head);

    // delete_head(head);
    delete_node(head, 60);
    display_LL(head);

    if (search(head, 40))
    {
        cout << "found!!" << endl;
    }

    else
        cout << "Not found!!" << endl;

    // Node *newHead = reverse_LL(head);
    // Node *newHead = Recursive_reverse_LL(head);
    // display_LL(newHead);

    int k = 2;
    Node *newHead = ReverseK_LL(head, k);

    display_LL(newHead);
    return 0;
}