

/*
Static Members of Class

Class objects as static: 
Just like variables, objects also when declared as 
static have a scope till the lifetime of program.

Consider the below program where the object is non-static.

*/

#include <iostream>
using namespace std;

class ABC
{

public:
    ABC()
    {
        cout << "inside constructor" << endl;
    };

    ~ABC()
    {
        cout << "inside destructor" << endl;
    }
};

// int main()
// {
//     {
//         ABC obj1;
//     }

//     cout<<"end of main function";
//     return 1;
// }

// inside constructor
// inside destructor
// end of main function

int main()
{
    {
        static ABC obj1;
    }

    cout << "end of main function" << endl;
    return 1;
}

// inside constructor
// end of main function
// inside destructor