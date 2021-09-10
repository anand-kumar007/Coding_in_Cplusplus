/*
Queue data structure using the LL !! 

array implementation has following limitations
which are resolved in LL implementation 

1. static size
2. mostly part goes unused so memory wastage

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

class queue
{
    Node *front;
    Node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void Enqueue(int val);
    void Dequeue();
    int Peek();
    bool Empty();
};

void queue::Enqueue(int val)
{
    Node *n = new (nothrow) Node(val);

    //if for the first time insertion
    if (front == NULL)
    {
        back = n;
        front = n;
        return;
    }

    back->next = n;
    back = n;
}

void queue::Dequeue()
{
    if (front == NULL)
    {
        cout << "Queue underflow !!" << endl;
        return;
    }

    Node *to_delete = front;
    front = front->next;

    delete to_delete;
    return;
}

int queue::Peek()
{
    if (front == NULL)
    {
        cout << "Queue is empty !!" << endl;
        return -1;
    }

    return front->data;
}

bool queue::Empty()
{
    return (front == NULL);
}

int main()
{
    queue q1;

    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);

    cout << q1.Peek() << endl;

    q1.Dequeue();
    cout << q1.Peek() << endl;

    if (q1.Empty())
    {
        cout << "yes empty queue !!" << endl;
    }
    else
    {
        cout << "no queue is not empty !!" << endl;
    }

    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    return 0;
}