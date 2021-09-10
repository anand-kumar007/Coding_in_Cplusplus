/*
Queue data structure using the call stack and single stack

1. enqueue 
    always push to stack
2. dequeue_&_peek
    costly O(N) operation in case of worst time
    (i) if stack is empty return error
    (ii) if stack has only one element then return it
        
    (iii) else 
            recursively call the same function and get the ans
            which will store the prev elements to some temp
            push these values again to stack and finally return the ans
3. empty
    as usual

*/

#include <iostream>
#include <stack>
using namespace std;

class QUEUE
{
public:
    stack<int> s;
    int N;
    void PUSH(int val);
    int DEQUEUE_PEEK();
    int SIZE();
    bool EMPTY();
};

void QUEUE::PUSH(int val)
{
    s.push(val);
    N++;
    return;
}

int QUEUE::DEQUEUE_PEEK()
{
    if (s.empty())
    {
        cout << "nothing to pop from the queue ";
        return -1;
    }
    int ans = s.top();
    s.pop();

    //if stack had only one element
    if (s.empty())
    {
        return ans;
    }

    //else recurse for the rest of the stack
    //and find our final answer
    
    else
    {
        int ourAns = DEQUEUE_PEEK();
        s.push(ans);

        return ourAns;
    }
}

bool QUEUE::EMPTY()
{
    return s.empty();
}

int main()
{
    QUEUE q;
    q.PUSH(10);
    q.PUSH(20);
    q.PUSH(30);
    q.PUSH(40);

    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    cout << q.DEQUEUE_PEEK() << endl;
    return 0;
}