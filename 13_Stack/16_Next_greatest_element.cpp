
/* 
next-greatest-element using stack since it gives O(N) time ccomplexity
*/

/*
enter n : 6
enter 6 values : 4 5 2 25 7 8
NGE is :
4 -->5
5 -->25
2 -->25
25 -->-1
7 -->8
8 -->-1

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NGE(vector<int> v);

int main()
{
    int n;
    cout << "enter n : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter " << n << " values : ";
    for (auto &i : v)
    {
        cin >> i;
    }

    vector<int> nge = NGE(v);

    cout << "NGE is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " -->" << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
    }

    return 0;
}

vector<int> NGE(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}