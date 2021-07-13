/*
Given  a board of size 2xN size and tile of size 1x2 find 
possible ways of tiling the board using the given tiles.

Eg: N=4 ans = 4

*/
#include <iostream>
using namespace std;
int Tiling(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    //tile horizontally and vertically
    //in case of horizontally placing problem reduces to n-2
    // in later case reduces to n-1 .
    return Tiling(n-1) + Tiling(n-2);
}
int main()
{
    cout <<Tiling(4)<<endl;
    return 0;
}