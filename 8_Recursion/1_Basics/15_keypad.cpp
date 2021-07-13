/*
print all possible combinations using the 
keypad words

"23" is the number combinations

ad  
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
using namespace std;
string arr[] = {" ", "./", "abc", "def", "ghi", "jkl", "mno", "pqrst", "uvw", "xyz"};

void keypad(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string code = arr[ch - '0'];
    //now i have abc in code string
    string ros = s.substr(1);

    for (int i = 0; i < code.size(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}

int main()
{
    keypad("23", "");
    return 0;
}