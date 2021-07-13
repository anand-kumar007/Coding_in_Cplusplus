/*
replace pi with 3.14 in string
piisgoodpiisnotgoodpiisforallpiok
--
3.14isgood3.14isnotgood3.14isforall3.14ok
--
*/
#include <iostream>
using namespace std;
void replace(string str);
void replacePi(string s);

int main()
{
    string s = "piisgoodpiisnotgoodpiisforallpiok";
    // replace(s);
    replacePi(s);
    return 0;
}

void replacePi(string s)
{
    if (s.length() == 0)
        return;

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

void replace(string s)
{
    for (int i = 0; i <= s.length() - 1;)
    {
        if (s[i] == 'p' && s[i + 1] == 'i')
        {
            // s[i]="3.1";  //multichar assignment not possible
            // s[i+1]='4';
            cout << "3.14";
            i += 2;
        }
        else
        {
            cout << s[i];
            i++;
        }
    }
}