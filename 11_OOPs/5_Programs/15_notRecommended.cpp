/*
this program though works fine
but this notation of calling is not recommended
*/

#include <iostream>
using namespace std;

class Number
{
    int x, y;

public:
    Number() : Number(0, 0) { cout << 0; }
    Number(int a) : Number(a, 0) { cout << 1; }
    Number(int a, int b) : x{a}, y{b} { cout << 2; }
};

int main()
{
    Number n1;
    Number n2 = 10;
    Number n3 = {10, 20}; //above two notations!!
    return 0;
}
// 20212