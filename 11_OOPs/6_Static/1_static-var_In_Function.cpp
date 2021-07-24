
/* static variables
Static duration means that the object or variable 
is allocated when the program starts and is deallocated when the program ends.

1. only one copy is created and available throughout the program
   (unlike the others just for the end of block)
2. defualt initialized to 0 or null when first object of class
    is created.
*/

/*

Static variables in a Function: 

When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call. This is useful for implementing coroutines in C/C++ or any other application where previous state of function needs to be stored.

*/
#include <iostream>
using namespace std;
void print()
{
    int count = 0;
    // static int count ;
    cout << count++;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        print();
    }

    return 0;
}