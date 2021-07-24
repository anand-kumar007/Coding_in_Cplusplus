
/*
we can make a class to be our friend
even if it doesn't exists!!!

bcz we may need to define it sometimes later

same is true for friend function !!
*/

#include <iostream>
using namespace std;

class Test
{
    friend class M1;

    public:
    void fun()
    {
        cout<<"I love C++"<<endl;
    }
};

int main()
{
    Test t1;
    t1.fun();
    return 0;
}

// OK will give no error and will display appropriate output
