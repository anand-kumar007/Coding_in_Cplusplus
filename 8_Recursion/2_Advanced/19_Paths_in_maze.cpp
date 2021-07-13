/*
Like a matrix but direction of movement could only
be either horizontal or vertical

let nXn where n==3
*/

#include <iostream>
using namespace std;

int countMazePaths(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;

    if (i >= n || j >= n)
        return 0;
    //if diagonal moves are allowed then add func(n,i+1,j+1)
    return countMazePaths(n, i + 1, j) + countMazePaths(n, i, j + 1);
}

int main()
{
    cout << countMazePaths(3, 0, 0) << endl;
    return 0;
}