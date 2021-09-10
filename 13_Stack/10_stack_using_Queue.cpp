
/*
stack using the two queues
1. push method costly
2. pop method costly

Let's see 
1. push method costly firstly 

Algorithm :
push method
1. add to q2
2. whlile(q1) is not empty
   takes all values of q1 into q2
3. swap q2 and q1

done

pop()
remove from the q1 always
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int val);
    void pop();
    int top();
    int size();
};

//push method costly
void Stack::push(int val)
{
    q2.push(val);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    //swap both the queues
    queue<int> temp;
    temp = q1;
    q1 = q2;
    q2 = temp;

    N++;
    //done
    return;
}

void Stack::pop()
{
    if (q1.empty())
    {
        cout << "stack is empty" << endl;
        return;
    }
    // pop from queue1
    q1.pop();

    N--;

    return;
}

int Stack::top()
{
    return q1.front();
}

int Stack::size()
{
    return N;
}

int main()
{
    Stack s;
    // cout<<s.q1.front()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << s.size() << endl;

    return 0;
}