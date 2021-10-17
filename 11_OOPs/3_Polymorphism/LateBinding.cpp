#include<bits/stdc++.h>
using namespace std;

class A
{
    public :
    virtual void print()
    {
        cout<<"Base class"<<endl;
    }
};


class Derived : public A
{
    public :
    void print()
    {
        cout<<"Derived class"<<endl;
    }
};


int main()
{
    Derived d1,d2;
    A *obj = &d1;
    obj->print();
    d1.print();  //derived class
    
    d1.A::print(); //base class
    obj->A::print();

    return 0;
}


/*
Output :
Derived class
Derived class
Base class
Base class
*/
