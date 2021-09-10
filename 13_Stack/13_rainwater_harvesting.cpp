

/*
rainwater storing problem 

given non-negative array of integers where
each element represent height of the bar

Tell how much water we can store 

=============================
1. Brute force 

Approach: The idea is to traverse every array element and find the highest bars on the left and right sides. Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element.

Algorithm: 

Traverse the array from start to end.

For every element, traverse the array from start to that index and find the maximum height (a) and traverse the array from the current index to end, and find the maximum height (b).

The amount of water that will be stored in this column is min(a,b) – array[i], add this value to the total amount of water stored

Print the total amount of water stored.

basically we are checking at each tile how much water can stay

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int rain_water(vector<int> arr);   //O(n) + space O(2N) using stack
int brute_force(vector<int> arr);  //O(n^2)
int brute_force2(vector<int> arr); //O(n)

int main()
{
    // vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    //6 units
    vector<int> arr = {1, 2, 0, 3, 2, 1, 0, 2};
    // 5 units

    // int total_water = rain_water(arr);
    int total_water = brute_force(arr);

    cout << "total water stored : ";
    cout << total_water << endl;
    //6 in this case
    return 0;
}

// Instead of maintaining two arrays of size n for storing the left and a right max of each element, maintain two variables to store the maximum till that point. Since water trapped at any element = min(max_left, max_right) – arr[i]. Calculate water trapped on smaller elements out of A[lo] and A[hi] first and move the pointers till lo doesn’t cross hi.

int brute_force2(vector<int> arr)
{
    int n = arr.size();
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int lo = 0, hi = n - 1;

    while (lo <= hi)
    {
        if (arr[lo] < arr[hi])
        {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else
        {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;
}

int brute_force(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();

    for (int i = 1; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }

        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, arr[j]);
        }

        ans = ans + (min(left, right) - arr[i]);
    }

    return ans;
}

int rain_water(vector<int> arr)
{
    int ans = 0, height = 0, width = 0;
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        //as soon as we get some higher bar
        //a container gets formed (may be)
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int curr = st.top();
            st.pop(); //move back to previous block

            //only ascending bars means no left wall
            if (st.empty())
            {
                break;
            }

            width = i - st.top() - 1;
            height = min(arr[i], arr[st.top()]) - arr[curr];

            ans += width * height;
        }
        st.push(i);
    }

    return ans;
}