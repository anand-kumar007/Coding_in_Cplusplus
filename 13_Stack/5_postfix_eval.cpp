/*
evaluating the postfix expression 


================>  <==============================
23^ ==> 2^3

stack will have
3
2
since L-R evalutation
so 3 wiill pop first and then 2

op2 comes out of stack first

op1 opereator op2

===========>In case of prefix eval<==================




*/

#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int postfix_Eval(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            default:
                break;
            }
        }
    }

    return st.top();
}
int main()
{
    // string s = "2*3+4";
    // string s = "23*4+";
    // string s = "236*+82/-"; //postfix string
    string s = "46+2/5*7+";

    cout << postfix_Eval(s) << endl;

    return 0;
}

