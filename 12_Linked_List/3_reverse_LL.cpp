/*
program to reverse the linked list
there are two methods of it
1.iterative way (need three pointers)
2.recursive way (little simpler)
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

Node *Reverse_iterative(Node *&head)
{

    Node *PrevPtr = NULL;
    Node *CurrPtr = head;
    Node *NextPtr;

    while (CurrPtr != NULL)
    {
        NextPtr = CurrPtr->next;

        //apply the algo
        CurrPtr->next = PrevPtr;

        PrevPtr = CurrPtr;
        CurrPtr = NextPtr;
    }

    //new head will be PrevPtr

    return PrevPtr;
}

Node *Reverese_recursive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = Reverese_recursive(head->next);

    //just change the links of first two nodes

    head->next->next = head;

    head->next = NULL;

    return newHead;
}

void Insert_Begin(Node *&head, int val)
{
    Node *n = new Node(val);

    n->next = head;
    head = n;
}

void Insert_End(Node *&head, int val)
{
    if (head == NULL)
    {
        Insert_Begin(head, val);
        return;
    }

    Node *n = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
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

int main()
{
    Node *head = NULL;

    Insert_Begin(head, 10);
    Insert_Begin(head, 5);
    Insert_Begin(head, 2);
    Insert_End(head, 20);
    Insert_End(head, 30);
    Insert_End(head, 40);

    display_LL(head);

    // Node *newHead = Reverse_iterative(head);
    Node *newHead = Reverese_recursive(head);
    cout << "Reversed LinkedList : " << endl;
    display_LL(newHead);

    return 0;
}

// the best solution same as iterative one
Node* Reverse(Node* head, Node* prev)
    {
        if(head == nullptr)
            return prev;
        
        //just follow the same approach as of iterative soln
        Node* adv = head->next;
        head->next = prev;
        
        prev = head;
        head = adv;
        
        return Reverse(head,prev);
    }
    Node* reverseList(Node* head) {
        
        return Reverse(head,NULL);
    }
