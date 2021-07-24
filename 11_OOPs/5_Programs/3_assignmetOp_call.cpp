/*
assignment operator called! 
assignment operator called! 
*/

#include <iostream>
using namespace std;

class P
{
    int a;
    float b;

public:
    P &operator=(const P &a)
    {
        cout << "assignment operator called! " << endl;
        return *this;
    }
};

class Q
{
    P a[2];
};

int main()
{
    Q q1, q2; 
    // q2 = q1;
    return 0;
}