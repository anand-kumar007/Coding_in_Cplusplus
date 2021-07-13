/*
count the path from 0 to 3 
    0 1 2 3
    paths from 1--3 + paths from 2--3 + paths from 3--3
    2 + 1 + 1 ===> 4

*/

#include <iostream>
using namespace std;
int countPaths(int start, int end)
{
    if (start >= end)
    return 0;

    int count = 0;
    for(int i=start; i<=end; i++)
    {
        count += countPaths(i+start,end);
    }

    return count;
}
int main()
{
    cout <<countPaths(0,3);
    return 0;
}