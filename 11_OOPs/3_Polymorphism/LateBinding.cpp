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
    obj->print(); // or (*obj).print(); both are same
    d1.print();  //derived class
    
    d1.A::print(); //base class
    obj->A::print();

    return 0;
}


// Derived *d1,d2;
//     A obj;
//     d1 = &obj;  --> this is an error bcz base class pointer can point to derived not the vice versa
/*
Output :
Derived class
Derived class
Base class
Base class
*/
