
/*

Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. 

To correct this situation, the base class should be defined with a virtual destructor. For example, following program results in undefined behavior.


There is no concept of virtual constructor in c++.
If we make constructor virtual, compiler flags an error. 

In fact, except inline, no other keyword is allowed in 
 declaration of the constructor.



*/

// CPP program without virtual destructor
// causing undefined behavior
#include <iostream>

using namespace std;

class base
{
public:
    base()
    {
        cout << "Constructing base \n";
    }
    ~base()
    {
        cout << "Destructing base \n";
    }
    // virtual ~base()
    // {
    //     cout << "Destructing base \n";
    // }
};

class derived : public base
{
public:
    derived()
    {
        cout << "Constructing derived \n";
    }
    ~derived()
    {
        cout << "Destructing derived \n";
    }
};

int main(void)
{
    derived *d = new derived();
    base *b = d;
    delete b;
    getchar();
    return 0;
}

/*
Constructing base    
Constructing derived 
Destructing base

but that's not what is expected !!
*/

/*
just use 
virutal ~Base() { ------------ }

to avoid any this!!!

*/

/*

Any class that is inherited publicly, polymorphic or not, should have a virtual destructor. 

To put another way, if it can be pointed to by a base class pointer, 
its base class should have a virtual destructor. If virtual,
the derived class destructor gets called and then the base class destructor.

*/