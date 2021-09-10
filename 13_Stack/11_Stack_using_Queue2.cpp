
/*
stack using the two queues
1. push method costly
2. pop method costly

Let's see 
2. pop method costly firstly 

Algorithm :
pop method, top method
1. let add to q2 always
2. while q2.size() != 1 pop its element and add to q1
3. return this last element

done

push()
add to q2 always

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

//pop method costly
void Stack::push(int val)
{
    q2.push(val);
    N++;
}

int Stack::top()
{
    if (q2.empty())
    {
        cout << "stack underflow !!" << endl;
        return -1;
    }

    while (q2.size() != 1)
    {
        q1.push(q2.front());
        q2.pop();
    }

    int ans = q2.front();

    //need to add this element also to q1 an then swap

    q1.push(ans);
    //swap
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;

    return ans;
}

void Stack::pop()
{
    if (q2.empty())
    {
        cout << "stack underflow !!" << endl;
        return;
    }

    while (q2.size() != 1)
    {
        q1.push(q2.front());
        q2.pop();
    }
    q2.pop();
    //swap
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;

    N--;
    return;
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
    s.pop();

    cout << s.size() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.size();
    return 0;
}