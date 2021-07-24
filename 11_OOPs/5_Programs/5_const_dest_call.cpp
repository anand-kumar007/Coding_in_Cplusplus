/*
order of constructor calling
*/

#include <iostream>
using namespace std;

class Test
{
    int x;
    static int count;

public:
    Test()
    {
        x = ++count;
        cout << "Constructor called " << x << endl;
    }
    ~Test()
    {
        cout << "Destructor called " << x << endl;
    }
};

//initializing static data
int Test ::count = 0;

int main()
{
    Test a[3];

    //similarly
    // Test t1;
    // Test t2; //t2 will be destroyed first and then t1
    return 0;
}

/*
Constructor called 1
Constructor called 2
Constructor called 3
Destructor called 3
Destructor called 2
Destructor called 1
*/