/*
reverse a stack without using the another stack explicitly

Note it is not like take 5 from the top and call insert at bottom
while it is like empty the stack and one by one insert each element
stored in call stack @ the bottom
like
1
now comes 2 store it in bottom of 1 and so on
*/

#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();

    insert_at_bottom(st, element);

    st.push(topElement);
}

void reverse_stack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();
    reverse_stack(st);
    // Insert all the items held
    // in Function Call Stack
    // one by one from the bottom
    // to top. Every item is
    // inserted at the bottom
    insert_at_bottom(st, element);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // reverse_stack(st);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}