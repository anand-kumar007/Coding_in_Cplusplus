/*
basic dequeue program 
*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(2);

    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << "size : " << dq.size() << endl;

    dq.pop_back();
    dq.pop_front();

    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << "size : " << dq.size() << endl;

    return 0;
}