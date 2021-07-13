
#include <iostream>
using namespace std;
int main()
{
    int a = 10, *pa, &ra;
    pa = &a;
    ra = a;
    cout << "a=" << ra;
    return 0;
}

//this would give an compilation error bcz reference variables need to initialized during the declaration time itself.

//  'ra' declared as reference but not initialized