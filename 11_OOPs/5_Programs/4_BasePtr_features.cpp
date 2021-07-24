
/*
Difference of calling through pointer
only those data memeber and functions of 
derived calss can be called using base class
pointer which are there in base as well as
derived class both.
*/

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base :: show() " << endl;
    }
};

class Derived : public Base
{
    int x;

public:
    void show()
    {
        cout << "Derived :: show() " << endl;
    }
    Derived() { x = 10; }
    int getX() const
    {
        return x;
    }
};

int main()
{
    Derived d;
    Base *bp = &d;

    bp->show(); //ok
    // bp->getX(); //error
    return 0;
}e