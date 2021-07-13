/*
"AB"
""
"B"
"66"
*/

#include <iostream>
using namespace std;
void subseq2(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    int code = ch;

    //adding, not adding, adding the code to empty str
    subseq2(ros, ans);
    subseq2(ros, ans + ch);
    subseq2(ros, ans + to_string(code));
}
int main()
{
    subseq2("AB", "");
    return 0;
}