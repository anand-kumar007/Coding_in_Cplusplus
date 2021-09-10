
// stock span problem

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> brute_force(vector<int> arr)
{
    int n = arr.size();
    vector<int> temp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                temp[i]++;
            }
        }
    }

    return temp;
}

vector<int> stock_span_using_stack(vector<int> arr);
vector<int> stock_span_using_stack2(vector<int> arr);

int main()
{
    // vector<int> arr = {100, 80, 60, 70, 60, 75, 85}; // stock span is : 1 1 1 2 1 4 6
    vector<int> arr = {100, 90, 20, 200, 300}; // stock span is : 1 1 1 4 5

    // arr = brute_force(arr);
    // arr = stock_span_using_stack(arr);
    arr = stock_span_using_stack2(arr);

    cout << "stock span is : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}

//  When we go from day i-1 to i, we pop the days when the price of the stock was less than or equal to price[i] and then push the value of day i back into the stack.
vector<int> stock_span_using_stack(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> stock_span(n, 0);
    stock_span[0] = 1; //first item will have span 1 always

    st.push(0); //push the first element to the stack

    for (int i = 1; i < n; i++)
    {
        //if element in stack has lower value than next coming item
        //keep popping items until then

        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        stock_span[i] = st.empty() ? (i + 1) : (i - st.top());

        st.push(i);
    }

    return stock_span;
}

vector<int> stock_span_using_stack2(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> stock_span;

    int days;

    for (auto price : arr)
    {
        days = 1;
        while (!st.empty() && st.top().first <= price)
        {
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, days));

        stock_span.push_back(days);
    }
    return stock_span;
}