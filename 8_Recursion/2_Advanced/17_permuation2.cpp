/*
print all the permutations of given distinct integers
*/

#include <iostream>
using namespace std;

// using backtracking
void permute(string s, int start, int end)
{
    if (start == end)
    {
        cout << s << endl;
        return;
    }

    //actually swapping with next idx items in string
    for (int i = start; i <= end; i++)
    {
        //swap
        swap(s[start], s[i]);
        //recursion
        permute(s, start + 1, end);
        //backtrack
        swap(s[start], s[i]);
    }
}
int main()
{
    string str = "12";
    int n = str.size();

    permute(str, 0, n - 1);
    return 0;
}

// backtracking
// O(n*n!) Note that there are n! permutations 
// and it requires O(n) time to print a permutation.
