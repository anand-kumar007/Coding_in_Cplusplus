/*
infixToPrefix 

"(a-b/c)*(a/k-l)";

reverse it and make the same ( , )
and all

then apply the same algorithm of Infix To postfix

1. if operand
    print
2. if '(' 
    push to stack
3. if ')'
    pop from stack and print until
    '(' is found
4. if operator
    pop from stack and print until an
    operator with less precedence is found

    push(currElement)
*/

#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return -1;
}

string Reverse(string &str)
{
    int n = str.size();
    char temp_ch;
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
        // temp_ch = str[i];
        // str[i] = str[n-i-1];
        // str[n-i-1] = temp_ch;
    }

    return str;
}

string Infix_to_prefix(string s)
{
    stack<char> st;
    string res = "";
    //reverse the str and then get back the same brackets
    // finally apply same algo as of infix to postfix
    s = Reverse(s);

    // reverse(s.begin(),s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            s[i] = '(';
        }
        else if (s[i] == '(')
        {
            s[i] = ')';
        }
    }

    //apply the algo

    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            //pop until a matching ')' is found
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }

            //finally remove the '('

            if (!st.empty())
                st.pop();
        }

        else
        {
            //we encounter an operator

            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                //keep popping
                res += st.top();
                st.pop();
            }

            //finally push the operator
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }


    // reverse(res.begin(), res.end());

    res = Reverse(res);
    return res;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << Infix_to_prefix(s) << endl;

    return 0;
}