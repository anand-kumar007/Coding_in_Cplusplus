
/*
array of obj creation requires one default const
user defined always if you have a parameterized one
*/

#include <iostream>
using namespace std;

class ABC
{
    int a;

public:
    ABC()
    {
        cout << "default constructor calld" << endl;

    } //otherwise error
    ABC(int x)
    {
        // ABC::a = x; //or
        // this->a = x; //or
        a = x;
        cout << "parameterized constructor calld" << endl;
    }
};

int main()
{
    // ABC arr[4] = {1, 2, 4, 5};
    ABC arr[4];
    return 0;
}