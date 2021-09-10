
/* balance paranthesis */
/*
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

Some examples of balanced brackets are []{}(), [({})]{}() and ({(){}[]})[].


STDIN           Function
-----           --------
3               t = 3
{[()]}          first expression
{[(])}          second expression
{{[[(())]]}}    third expression
Sample Output

YES
NO
YES
Explanation

*/
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char, int> symbol_value = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};

string isBalanced(string expression)
{
    stack<char> st;

    for (char bracket : expression)
    {
        if (symbol_value[bracket] < 0)
        {
            st.push(bracket);
        }
        else
        {
            //it is some closing bracket
            if (st.empty())
                return "NO";

            char temp = st.top();
            st.pop();
            if (symbol_value[bracket] + symbol_value[temp] != 0)
            {
                return "NO";
            }
        }
    }

    if (st.empty())
        return "YES";

    else
        return "NO";
}

int main()
{
    // string s = "{{[[(())]]}}";
    // string s = "{[()]}";
    string s = "{[(])}";
    cout << isBalanced(s) << endl;
    return 0;
}