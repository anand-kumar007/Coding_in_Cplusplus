/* 
Given n size array and you are supposed to find out the
set of k elements from this array such that the minimum distnace btwn
any pair of set is maxm possible distance in the array

ex: {1,2,3} k = 2
sol : {1,3} and ans = 2 dist

{11,2,7,5,1,12}

ans = {1,7,12} and ans= 5 dist
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int k, int mid)
{
    int element = 0;
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - temp >= mid)
        {
            element++;
            if (element == k)
                return true;
        }
    }
    return false;
}

int LargestMinmDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int left = 1, right = arr[n - 1]; //range initially
    int result = -1;

    //kinda binary search
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            //try to maximize the result
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }

    return result;
}

int main()
{
    // int arr[] = {11, 2, 7, 5, 1, 12}; // 6 {1,7,12} only
    int arr[] = {1, 2, 8, 4, 9}; //3 {1,4,9} or {1,4,8}
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3; //set size

    int ans = LargestMinmDist(arr, n, k);
    cout << ans << endl;

    return 0;
}

/* 
approach 1:
find all the subsets of array of size k and compare minimum dist 
btwn all of them and return the Largest minimum possible distance

approach 2 :
we can you binary search kinda approach
1. sort the array
2. maintain a range left=1 to right = arr[n-1] //after sorting
3. if the range is feasible(means we could find values >= k
    which satisfies the answer then increase the ans value by
    searching in right half of the array)
4. else we need to shrink our ans and search in the left half itself.


*/