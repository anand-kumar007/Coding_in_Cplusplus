#include <iostream>
using namespace std;
void permutation(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    //fix one char and permutate all other
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        //rest of the string just leaving the ith character
        string ros = s.substr(0, i) + s.substr(i + 1);

        permutation(ros, ans + ch);
    }
}
int main()
{
    permutation("121", "");
    return 0;
}

/*

O(n*n!) The time complexity is the same as the above approach, 
i.e. there are n! permutations and 
it requires O(n) time to print a permutation.

*/