
/*
problem of checking whether the paranthesis are balanced
[{()}] --> balanced

{[()}] --> unbalanced

*/

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    bool ans = true; //let

    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            st.push(s[i]);
        }

        else
        {
            if (s[i] == ')')
            {
                if (!st.empty() && st.top() != '(')
                {
                    ans = false;
                    break;
                }

                st.pop();
            }

            //

            else if (s[i] == '}')
            {
                if (!st.empty() && st.top() != '{')
                {
                    ans = false;
                    break;
                }
                st.pop();
            }

            //

            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() != '[')
                {
                    ans = false;
                    break;
                }
                st.pop();
            }
        }
    }

    if (!st.empty())
    {
        ans = false;
    }

    return ans;
}

int main()
{
    // string s = "{([])}";
    string s = "{([)]}";

    if (isBalanced(s))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced " << endl;
    }
    return 0;
}