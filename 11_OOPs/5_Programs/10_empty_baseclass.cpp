/*
size of empty class in C++ is 1 bytes while in C it is 0 bytes.

Size of an empty class is not zero. It is 1 byte generally. 
It is nonzero to ensure that the two different objects 
will have different addresses

*/

#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    Base(int x, int y) {}
    Base(int a, int b, int c) {}
};

int main()
{
    cout << sizeof(Base) << endl;
    return 0;
}

/*

for same reason the new operator always allocate 
different memory address to two class
*/
#include <iostream>
using namespace std;
#pragma pack(1)
//telling that don't use padding


class Empty
{
    char ch;
};

int main()
{
    Empty *p1 = new Empty;
    Empty *p2 = new Empty;

    if (p1 == p2)
        cout << "impossible " << endl;
    else
        cout << "Fine " << endl;

    return 0;
}
