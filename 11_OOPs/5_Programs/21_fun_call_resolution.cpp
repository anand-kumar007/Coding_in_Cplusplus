
/*
function call resolution.
it always checks in the hierarchy !!

A --> call()

B : from A publc 
B --> its own call() also

now 
C : from B public

*/

#include <iostream>
using namespace std;

class A
{
public:
    void call()
    {
        cout << "Its A" << endl;
    }
};

class B : public A
{
public:
    void call()
    {
        cout << "its B" << endl;
    }
};

class C : public B
{
};

int main()
{
    C temp;
    temp.call(); //this will look upside in the hierarchy
                 // and would findout the call() whichever comes first
                 //here B's call would be called!!
                 // its B
    return 0;
}