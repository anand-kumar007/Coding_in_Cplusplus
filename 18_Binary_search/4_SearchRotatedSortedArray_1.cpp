
#include <iostream>
#include<vector>
using namespace std;

int SearchArrayRotated(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;

    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return SearchArrayRotated(arr, l, mid - 1, key);

        return SearchArrayRotated(arr, mid + 1, h, key);
    }

    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return SearchArrayRotated(arr, mid + 1, h, key);

    return SearchArrayRotated(arr, l, mid - 1, key);
}

//
int search(vector<int> &nums, int target)
{

    int n = nums.size(), low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = (low + high) >> 1;

        if (nums[mid] == target)
            return mid;

        //check if left half is sorted
        if (nums[low] <= nums[mid])
        {

            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }

            //call for other part thought unsorted
            else
                low = mid + 1;
        }

        //right half is sorted
        else
        {

            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            //call for other part thought unsorted
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {40, 50, 10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 10;
    // int key = 40;
    int idx = SearchArrayRotated(arr, 0, n - 1, key);
    cout << idx << endl;
    return 0;
}

/* 
Approach: Instead of two or more pass of binary search the result can be found in one pass of binary search. The binary search needs to be modified to perform the search. The idea is to create a recursive function that takes l and r as range in input and the key.


1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..h]
4) Else (arr[mid+1..h] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[h], recur for arr[mid+1..h].
    b) Else recur for arr[l..mid] 


*/