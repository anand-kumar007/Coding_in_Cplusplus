
// predict the output of following program

#include <iostream>
using namespace std;

class Test
{
protected:
    int x;

public:
    Test(int i) : x(i) {}
    void fun() const
    {
        cout << "fun() const called " << endl;
    }
    void fun()
    {
        cout << "fun() called " << endl;
    }
};

int main()
{
    Test t1(10);
    const Test t2(20);
    t1.fun();
    t2.fun();
    return 0;
}


// output is
// fun() called
// fun() const called

/*
The two methods ‘void fun() const’ and ‘void fun()’ have same signature except that one is const and other is not. Also, if we take a closer look at the output, we observe that, ‘const void fun()’ is called on const object and ‘void fun()’ is called on non-const object.

C++ allows member methods to be overloaded on the basis of const type. Overloading on the basis of const type can be useful when a function return reference or pointer. We can make one function const, that returns a const reference or const pointer, other non-const function, that returns non-const reference or pointer. 

*/