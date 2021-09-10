/*
implementing stack using the array
*/

#include <iostream>
using namespace std;
#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val);
    void pop();
    int Top();
    bool empty();
};

void stack::push(int val)
{
    if (top == n - 1)
    {
        cout << "stack overflow !!" << endl;
        return;
    }

    top++;
    arr[top] = val;

    return;
}

void stack::pop()
{
    if (top == -1)
    {
        cout << "No element to pop " << endl;
        return;
    }

    top--;
    return;
}

int stack::Top()
{
    if (top == -1)
    {
        cout << "No element in stack" << endl;
        return -1;
    }

    return arr[top];
}

bool stack::empty()
{
    return top == -1;
}

int main()
{
    stack st;

    st.push(10);
    st.push(90);
    st.push(40);
    st.push(60);

    cout << st.Top() << endl;

    st.pop();
    st.pop();
    cout << st.Top() << endl;

    if (st.empty())
    {
        cout << "Empty stack" << endl;
    }
    else
        cout << "stack is not empty" << endl;

    st.pop();
    st.pop();
    st.pop();

    cout << st.Top() << endl;

    return 0;
}