/*
Queue data structure using the two stack !! 


1.dequeue operation costly

1. enqueue 
    always push to stack1
2. dequeue_&_peek
    costly O(N) operation in case of worst time
    (i) if s1 and s2 both stack are empty return error
    (ii) if s2 stack is empty 
        while(s1) is not empty pop all element from the
        stack s1 and push to stack s2
    (iii) return the top element of s2 and pop s2

3. empty
    return if both the stacks are empty
*/

#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void Enqueue(int val);
    int Dequeue_Peek();
    bool Empty();
};

void queue::Enqueue(int val)
{
    s1.push(val);
    return;
}

int queue::Dequeue_Peek()
{
    if (s1.empty() and s2.empty())
    {
        cout << "queue is empty !!" << endl;
        return -1;
    }

    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int ans = s2.top();
    s2.pop();
    return ans;
}

bool queue::Empty()
{
    return (s1.empty() && s2.empty());
}

int main()
{
    queue q1;

    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);

    cout << q1.Dequeue_Peek() << endl;
    cout << q1.Dequeue_Peek() << endl;

    if (q1.Empty())
    {
        cout << "yes empty queue !!" << endl;
    }
    else
    {
        cout << "no queue is not empty !!" << endl;
    }

    return 0;
}