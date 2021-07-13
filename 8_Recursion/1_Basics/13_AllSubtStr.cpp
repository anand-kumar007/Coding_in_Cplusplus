/*
print all the substring of a string
"ABC"
""
A
B
AB
C
AC
BC
ABC
totall 2^N for N ie 8 here for n=3
*/

#include <iostream>
using namespace std;
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    //one time adding and other time not
    subseq(ros, ans);
    subseq(ros, ans + ch);
}
int main()
{
    subseq("ABC", "");
    return 0;
}