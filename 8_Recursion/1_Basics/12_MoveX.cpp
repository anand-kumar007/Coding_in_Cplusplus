/*
move all x to end of the string
anbxdxjdx
anbdjdxxx
*/

#include <iostream>
using namespace std;
string moveX(string s);

int main()
{
    cout << moveX("abxdjxldjxlls");
    return 0;
}

string moveX(string s)
{
    if (s.size() == 0)
        return "";

    char ch = s[0];
    string ans = moveX(s.substr(1));

    //if that is x
    if (ch == 'x')
    {
        return ans + ch;
    }

    return ch + ans;
}