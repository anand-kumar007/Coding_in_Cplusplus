
/*
namespace variables are not global variables
namespace should be defined in the global scope else it is 
an error
*/

#include <iostream>
using namespace std;
namespace p1
{
    int a = 10;

}

int main()
{
    int a = 10;
    {
        int a = 102;
        cout << p1::a << endl; //namespace a
        cout << a << endl;     //local a

        cout << ::a << endl; //errror since no global a present
    }
    return 0;
}