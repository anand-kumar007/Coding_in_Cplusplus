
/*

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
    namespace p2
    {
        int a =10;  
    } // namespace p2
    
    cout<<p2::a<<endl;
    return 0;
}