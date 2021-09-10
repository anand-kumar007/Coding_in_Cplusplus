
/* 
Given an array and x value
find the minimum size of the subarray which has sum > x,

brute force approach takes O(N^2) time
we can go for sliding window approach
*/

#include <iostream>
using namespace std;

int SmallestSizeSubArrSumGreaterThanX(int arr[], int n, int x)
{
    int ans = n + 1; //invalid value
    int sum = 0;

    int start = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum > x)
        {
            //we need to remove and update the our ans
            while (sum > x && start < n)
            {

                sum = sum - arr[start];
                ans = min(ans, i - start + 1);
                start++;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    // int x = 30; //limit value
    int x = 51; //limit value
    int minLength = SmallestSizeSubArrSumGreaterThanX(arr, n, x);

    cout << "smallest subarray's size with required conditions :" << minLength << endl;
    return 0;
}