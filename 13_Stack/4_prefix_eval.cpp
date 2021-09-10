/*
evaluating the prefix expression 

from R to L we can see and then do accordingly

================>  <==============================
^23 ==> 2^3

stack will have
2
3
since R-L evalutation

so 2 wiill pop first and then three

so 
op1 opereator op2

===========>In case of prefix eval<==================

*/

#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int prefix_Eval(string s)
{
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        
        else
        {
            //it must be an operator or bracket
            //if there would have been paranthesis then we'll
            //simply ignore them
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
    string s = "-+7*45+20";

    cout << prefix_Eval(s) << endl;

    return 0;
}