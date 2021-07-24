/*
static varibales dosent contribute to 
size of the class although they belongs to
the class
*/

#include <iostream>
using namespace std;

class base
{
    int x;
    static int stk;
};

int base ::stk = 0;
int main()
{

    cout << sizeof(base);
    // 4 only
    return 0;
}