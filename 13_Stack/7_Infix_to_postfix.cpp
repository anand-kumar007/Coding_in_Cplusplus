
/*
infixToPostfix 

"(a-b/c)*(a/k-l)";

then apply the  algorithm of Infix To postfix

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

string Infix_to_postfix(string s)
{
    stack<char> st;
    string res = "";

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

    return res;
}

int main()
{
    string s = "(3*2)-(3+1)";
    // string s = "(a-b/c)*(a/k-l)";
    cout << Infix_to_postfix(s) << endl;

    return 0;
}

// abc/-ak/l-*
// 32*31+-