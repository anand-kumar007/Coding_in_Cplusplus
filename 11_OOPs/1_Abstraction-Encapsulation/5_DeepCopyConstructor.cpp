/*
    without copy constructor
    
Before
data1   data2   ptr
10      20      300
10      20      300
After
data1   data2   ptr
10      20      400
10      20      400

    with copy constructor

Before
data1   data2   ptr
10      20      300
10      20      300
After
data1   data2   ptr
10      20      400
10      20      300

*/

#include <iostream>
using namespace std;

class demo
{
    int data1, data2;
    int *ptr;

public:
    //constructor
    demo()
    {
        ptr = new int;
    }
    demo(int num1, int num2, int c)
    {
        this->data1 = num1;
        this->data2 = num2;
        *ptr = c;
    }

    //copy constructor
    demo(const demo &d);
    void setData(int a, int b, int c);
    void printInfo();
    void changeData(int);
};

void demo ::changeData(int x)
{
    *(this->ptr) = x;
}

void demo ::setData(int a, int b, int c)
{
    data1 = a;
    data2 = b;
    *ptr = c;
}

void demo ::printInfo()
{
    cout << data1 << "\t" << data2 << "\t" << *ptr << endl;
}
//copy constructor(to perform deep copying)
demo ::demo(const demo &d)
{
    data1 = d.data1;
    data2 = d.data2;

    ptr = new int;
    *ptr = *(d.ptr);
}

int main()
{
    demo d1;
    d1.setData(10, 20, 300);
    demo d2 = d1;

    cout << "Before\n";
    cout << "data1\tdata2\tptr" << endl;

    d1.printInfo();
    d2.printInfo();

    d1.changeData(400);

    cout << "After\n";
    cout << "data1\tdata2\tptr" << endl;

    d1.printInfo();
    d2.printInfo();

    return 0;
}

/*
____________________________________________________________
When is a user-defined copy constructor needed? 
_____________________________________________________________
If we don’t define our own copy constructor, the C++ compiler 
creates a default copy constructor for each class which does 
a member-wise copy between objects. The compiler created copy 
constructor works fine in general. We need to define our own 
copy constructor only if an object has pointers or any runtime 
allocation of the resource like filehandle, a network connection..etc.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The default constructor does only shallow copy. 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Deep copy is possible only with user defined copy constructor. 
In user defined copy constructor, we make sure that pointers 
(or references) of copied object point to new memory locations. 
___________________________________________________________________

*/