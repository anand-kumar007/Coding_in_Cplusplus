/*
Function Overloading (achieved at compile time)

It provides multiple definitions of the function by changing signature i.e changing number of parameters, change datatype of parameters, return type doesn’t play anyrole. 

It can be done in base as well as derived class.
*/

/*
In C++ and Java, functions can not be overloaded 
if they differ only in the return type.

Polymorphism is of two types :
(a) compile time --> function overloadin and operator overloading
(b) runtime --> function overriding (virtual funtions)

*/

#include <iostream>
using namespace std;

int foo()
{
    return 10;
}

// char foo()
// { // compiler error; new declaration of foo()
//     return 'a';
// }

int main()
{
    char x = foo();
    cout << x << endl;
    return 0;
}
