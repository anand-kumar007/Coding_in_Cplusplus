/*
make , detect and remove the cycles from the linked list

detection :
hare, tortoise algorithm (hare moves two steps and tortoise moves one step)

also called flyod's algorithm (one slowptr and other is fastptr)

removal :

same let the two pointer meets first and then bring back one of them
to beginning(say to the fast ptr) and move each by 1 step

if both ptr->next comes same then that is the point to cycle make
slowptr->next NULL

done!!

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

    return;
}

void make_cycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *cycle_start = NULL;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cycle_start = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = cycle_start;

    return;
}

bool detect_cycle(Node *head)
{

    Node *slow = head;
    Node *fast = head;

    //just the conditions of normal without cycle LL
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

void remove_cycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;

    } while (fast != slow);

    fast = head;

    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;

    //done

    return;
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

    int pos = 4;
    make_cycle(head, pos);

    // display_LL(head);

    if (detect_cycle(head))
    {
        cout << "has a cycle" << endl;

        cout << "removing the cycle" << endl;
        remove_cycle(head);

        display_LL(head);
    }

    else
        cout << "No cycle found!!" << endl;
    return 0;
}