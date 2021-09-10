
// How compiler know that 467 is 46, 7 not 4, 67, 
// you have to include blank spaces, didi already 
// mentions that this code is for single digit integers.
// if you want for any no of digits, you can try this:

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int PostfixSolver(string str);
int main()
{
    string str;
    getline(cin, str);
    cout << PostfixSolver(str) << endl;
    return 0;
}
int PostfixSolver(string str)
{
    int o1, o2, sum = 0;
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum = sum * 10 + (str[i] - '0');
        }
        else if (str[i] == ' ')
        {
            s.push(sum);
            sum = 0;
        }
        else
        {
            o2 = s.top();
            s.pop();
            o1 = s.top();
            s.pop();
            switch (str[i])
            {
            case '+':
                s.push(o1 + o2);
                break;
            case '-':
                s.push(o1 - o2);
                break;
            case '*':
                s.push(o1 * o2);
                break;
            case '/':
                s.push(o1 / o2);
                break;
            case '^':
                s.push(pow(o1, o2));
                break;
            }
            i++;
        }
    }
    return s.top();
}

// While taking input, use blank spaces b / w every integers and opeators.
