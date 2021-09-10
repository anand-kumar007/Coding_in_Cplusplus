/*
Redundant paranthesis in a valid maths exprsn
((a+b)) --> yes
(a+(b+c)) --> no

procedure is simple
ignore all characters simply except

if '(' comes or '+','/','-','*' comes 
push them to stack

when ')' closing bracket comes simply
check

1.stack has some operator in it
    pop() operator
    pop() corresponding '(' bracket
2. stack is not empty of operator

if stack is empty of operator then it has
redundant paranthesis

*/

#include <iostream>
#include <stack>
using namespace std;

bool Redundant_Paranthesis(string s);

int main()
{
    // string s = "((a+b))"; //Yes
    // string s = "(c+(a+b))"; //No
    string s = "(a*b-(c+d))"; //No
    // string s = "(a/b*((c-d)))"; //yes

    if (Redundant_Paranthesis(s))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    return 0;
}

bool Redundant_Paranthesis(string s)
{
    stack<char> st;
    bool ans = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            //
            if (st.top() == '(')
            {
                ans = true;
                break;
            }

            //pop operator and correspoing '('
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                st.pop();
            }

            st.pop(); //corresponding open bracket is popped
        }
    }

    return ans;
}