/*
// C++ program in-place Merge Sort
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation

*/

/*
merge sort inPlace
*/
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r);

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        //merge both arrays
        merge(arr, l, mid, r);
    }

    return;
}
int main()
{
    int arr[] = {10, -4, 40, -34, 23, 21, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

void merge(int arr[], int l, int mid, int r)
{
    int start2 = mid + 1;

    while (l <= mid && start2 <= r)
    {
        if (arr[l] < arr[start2])
            l++;
        else
        {

            int value = arr[start2];

            //shift (happens from end) [element1,element2)
            for (int i = start2; i != l; i--)
            {
                arr[i] = arr[i - 1];
            }

            //place element2 @ previous place of element1
            arr[l] = value;

            start2++;
            l++;
            mid++;
        }
    }

    //done
    return;
}

// maintain two pointer @ start of both the sorted array
// if (element1 < element2) then its in order increase pointer1
// else shift all elements [pointer1,pointer2) towardsa right
// and place value of pointer2 at the previous place of pointer1
// increase all three pointers including mid also


/*
Maintain two pointers that point to the start of the segments which have to be merged.
Compare the elements at which the pointers are present.

If element1 < element2 then element1 is at right position, simply increase pointer1.

Else shift all the elements between element1 and element2(including element1 but excluding element2) right by 1 and then place the element2 in the previous place(i.e. before shifting right) of element1. Increment all the pointers by 1.

================================
Time complexity : O(log n*nlog n)

*/