

/* 
Given n size array and k and x 
k is size of the subarray and x is limit of sum of subarry

you need to find the maxm sum subarray of size k Having
sum less thann X.


Approach 1 :
find sum of all subarray of size k and check sum of each of them
to be lesser than x Now find the maxm sum out of them.

O(n*k) time complexity

Approach 2 :
sliding window maxm approach

find sum of first k element if sum < x put it into the ans
iterate form k to n-1 now
keep adding ith index element to sum and removing the first element each time
increment the start 

if sum < x the put max(ans,sum) into the ans

Over.

*/

#include <iostream>
using namespace std;

int SlidingWindowMaxm(int arr[], int n, int k, int x)
{
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];
    if (sum < x)
        ans = sum;

    int start = 0;
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[start++];
        sum = sum + arr[i];

        if (sum < x)
            ans = max(ans, sum);
    }

    return ans;
}

int main()
{
    // int arr[] = {73, 5, 4, 6, 8, 9};
    int arr[] = {3, 5, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    int x = 20;

    int ans = SlidingWindowMaxm(arr, n, k, x);

    cout << "ans : " << ans << endl;
    return 0;
}