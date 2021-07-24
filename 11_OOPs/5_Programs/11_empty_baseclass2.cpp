
/*
Note that the output is not greater than 4. 
There is an interesting rule that says that an empty base class need not be represented by a separate byte. So compilers are free to make optimization in case of empty base classes.
*/

#include <iostream>
using namespace std;

class Empty
{
};

class Derived : Empty
{
    int a;
};

int main()
{
    cout << sizeof(Derived);
    return 0;
}

// 4 