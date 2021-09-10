
// implmenting the queue using two stack

// 2.making enqueue operation costly

// until stack1 is empty push to stack2
// insert to stack one
// bring back all the elements to stack one

// this way stack one will always hold the queue form
// of the data structure that we wanted to implement

#include <iostream>
#include <stack>
using namespace std;

class QUEUE
{
public:
    stack<int> st1;
    stack<int> st2;

    int N;
    QUEUE()
    {
        N = 0;
    }
    void PUSH(int val);
    int DEQUEUE_PEEK();
    bool EMPTY();
    int SIZE();
};

void QUEUE::PUSH(int val)
{
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }

    st1.push(val);

    //bring back all the elements to stack1
    while (!st2.empty())
    {
        st1.push(st2.top());
        st2.pop();
    }
    N++;

    return;
}

int QUEUE::DEQUEUE_PEEK()
{

    if (st1.empty())
    {
        cout << "Nothing to pop ";
        return -1;
    }

    int ans = st1.top();
    st1.pop();
    N--;
    return ans;
}

bool QUEUE::EMPTY()
{
    return (st1.empty());
}

int QUEUE::SIZE()
{
    return N;
}

int main()
{
    QUEUE q;

    cout << q.EMPTY() << endl;

    q.PUSH(10);
    q.PUSH(20);
    q.PUSH(30);
    q.PUSH(40);
    q.PUSH(50);

    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;

    cout << q.SIZE() << endl;

    return 0;
}