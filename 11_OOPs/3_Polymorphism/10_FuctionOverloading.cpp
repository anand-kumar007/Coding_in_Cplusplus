/*
Function Overloading (achieved at compile time)

It provides multiple definitions of the function by changing signature i.e changing number of parameters, change datatype of parameters, return type doesn’t play anyrole. 

It can be done in base as well as derived class.

*/
/*
Function overloading is a feature of object oriented programming 
where two or more functions can have the same name but different parameters.

When a function name is overloaded with different 
jobs it is called Function Overloading.

In Function Overloading “Function” name should be 
the same and the arguments should be different.

Polymorphism is of two types :
(a) compile time --> function overloadin and operator overloading
(b) runtime --> function overriding (virtual funtions)


*/

#include <iostream>
using namespace std;

class ABC
{
public:
    void fun()
    {
        cout << "No arguments" << endl;
    }

    void fun(int x)
    {
        cout << "Int argument" << endl;
    }

    // int fun(); // issue an error cz differ only in return type

    //okay bcz differ in parameters as well
    int fun(double y)
    {
        return y;
    }
};

int main()
{
    ABC obj;
    obj.fun();
    obj.fun(1);
    cout << obj.fun(3.2);
    return 0;
}

/*

How  Function Overloading works?

Exact match:- (Function name and Parameter)

If a not exact match is found:–
               ->Char, Unsigned char, and short are promoted to an int.
               ->Float is promoted to double

If no match found:
               ->C++ tries to find a match through the standard conversion.

ELSE ERROR 🙁

*/