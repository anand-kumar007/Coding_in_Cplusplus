/*
each block should be transferrd from AtoC such that
larger block always comes below the smaller one
given a helper rod B also but rule is applicable
to rod B as well.
N=3

Move from A to C
Move from A to B
Move from C to B
Move from A to C
Move from B to A
Move from B to C
Move from A to C

*/

#include <iostream>
using namespace std;
void TOH(int n, char src, char dest, char helper);

int main()
{
    TOH(4, 'A', 'C', 'B');
    return 0;
}
void TOH(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;
    TOH(n - 1, src, helper, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    TOH(n - 1, helper, dest, src);
}