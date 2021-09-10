/*
length of longest substring without repetitive character
"bbbb" ans=1
"pwwkew" ans=3
"abcabcb" ans=3

*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    cout << "Enter a string : ";
    cin >> s;

    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;

    for (int i = 0; i < s.size(); i++)
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];

        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }

    cout << maxLen << endl;
    return 0;
}