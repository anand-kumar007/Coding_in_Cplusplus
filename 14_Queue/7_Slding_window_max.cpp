/*
sliding winodw maximum of the order
O(N) using the deque with space complexity O(k)
where is the window size 

// A Dequeue (Double ended queue) based
// method for printing maximum element of
// all subarrays of size k

 // Create a Double Ended Queue,
    // Q that will store indexes
    // of array elements
    // The queue will store indexes
    // of useful elements in every
    // window and it will
    // maintain decreasing order of
    // values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()]
    // are sorted in decreasing order


*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> find_Maximum_In_Window(vector<int> arr, int k)
{
    deque<int> dq(k);
    vector<int> ans;
    int n = arr.size();

    /* Process first k (or first window)
	elements of array */
    int i;
    for (i = 0; i < k; i++)
    {
        // For every element, the previous
        // smaller elements are useless so
        // remove them from Q
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        // Add new element at rear of queue
        dq.push_back(i);
    }

    // The element at the front of
    // the queue is the largest element of
    // previous window, so store it
    ans.push_back(arr[dq.front()]);

    //repeat the procedure for next k to n elements

    for (i = k; i < n; i++)
    {
        // Remove the elements which
        // are not of current windo ie just the first element of arr
        if (!dq.empty() && (dq.front() == i - k))
        {
            dq.pop_front();
        }

        // Remove all elements
        // smaller than the currently
        // being added element (remove
        // useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        // Add current element at the rear of Qi
        ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main()
{
    // vector<int> a= {1,3,-1,-3,5,3,6,7};
    int n;
    int k;
    cout << "enter size of array and window : ";
    cin >> n >> k;
    vector<int> a(n);

    cout << "enter " << n << " array elements : ";
    for (auto &i : a)
    {
        cin >> i;
    }
    // int k=3;
    vector<int> ans;
    ans = find_Maximum_In_Window(a, k);

    cout << "mixium elements in winodw " << k << "are : \n";
    for (auto i : ans)
        cout << i << " ";
    return 0;
}

// 3 3 5 5 6 7