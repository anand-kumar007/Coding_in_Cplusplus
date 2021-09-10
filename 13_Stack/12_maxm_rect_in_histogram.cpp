/*
 largest rectange that can be fitted in a histogram
{1, 2, 3, 2}; //6
{6,2,5,4,5,1,6}; //12
{4,5,6,7}; //16


if stack is emtpy
area = arr[st.top()] * i

if stack is not empty
area = arr[st.top] * (i - st.top() - 1)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int using_stack(vector<int> arr);        //O(n)
int brute_force(vector<int> arr);        //O(n^2)
int divide_and_conquer(vector<int> arr); //O(nlogn)

int main()
{
    int n;
    cout << "enter size of array : ";
    cin >> n;
    vector<int> arr(n);

    cout << "enter " << n << " bar's height : ";

    for (auto &i : arr)
    {
        cin >> i;
    }

    // int ans = brute_force(arr);
    int ans = using_stack(arr);
    // int ans = divide_and_conquer(arr);

    cout << "maxm area that can be fitted is : ";
    cout << ans << endl;
    return 0;
}

int brute_force(vector<int> arr)
{
    int n = arr.size();
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int height = arr[i];
        int width = 1;
        for (int j = i + 1; j < n; j++)
        {
            height = min(height, arr[j]);
            width++;
            area = max(area, height * width);
        }
    }
    return area;
}

int using_stack(vector<int> arr)
{
    int n = arr.size();

    int ans = 0;
    int width = 1;
    int height = 0;

    // Create an empty stack. The stack holds indexes
    // of arr[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<int> st;

    int i = 0;
    while (i < n)
    {
        //if smaller bar comes
        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'

        while (!st.empty() && arr[st.top()] > arr[i])
        {

            height = arr[st.top()];
            st.pop();

            width = st.empty() ? i : i - st.top() - 1;

            ans = max(ans, (height * width));
        }

        //else keep pushing simply until you get any smaller bar
        st.push(i);
        i++;
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (st.empty() == false)
    {
        height = arr[st.top()];
        st.pop();

        width = st.empty() ? i : i - st.top() - 1;

        ans = max(ans, height * width);
    }

    return ans;
}