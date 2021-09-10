/*
Queue data structure using the array !! 
*/

#include <iostream>
using namespace std;
#define n 100

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new (nothrow) int[n];
        front = -1;
        back = -1;
    }

    void Enqueue(int val);
    void Dequeue();
    int Peek();
    bool Empty();
};

void queue::Enqueue(int val)
{
    if (back != n - 1)
    {
        arr[++back] = val;
    }
    else
    {
        cout << "Queue is full !!" << endl;
        return;
    }

    //if first time insertion then this step is must
    if (front == -1)
    {
        front++;
    }

    return;
}

void queue::Dequeue()
{
    if (front > back || front == -1)
    {
        cout << "Queue is already empty !!" << endl;
        return;
    }

    front++;

    return;
}

int queue::Peek()
{
    if (front > back || front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    return arr[front];
}

bool queue::Empty()
{
    if (front > back || front == -1)
    {
        return true;
    }

    return false;
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