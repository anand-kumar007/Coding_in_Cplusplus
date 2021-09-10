

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == key)
        return mid;
    if (key < arr[mid])
        return BinarySearch(arr, mid + 1, end, key);

    return BinarySearch(arr, 0, mid - 1, key);
}

int findPivot(int arr[], int start, int end)
{
    if (start > end)
        return -1;
    if (start == end)
        return start;

    int mid = (start + end) / 2;
    //i m greater than you so i am the pivot
    if (mid < end && arr[mid] > arr[mid + 1])
        return mid;
    //i m lesses than you so you are the pivot
    if (mid > start && arr[mid] < arr[mid - 1])
        return (mid - 1);

    if (arr[start] <= arr[mid])
        return findPivot(arr, 0, mid - 1);

    return findPivot(arr, mid + 1, end);
}

int SearchArrayRotated(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
    cout << "PIVOT :  " << pivot << endl;
    //if no pivot then there is no rotation in array
    if (pivot == -1)
        return BinarySearch(arr, 0, n - 1, key);

    //if pivot exists
    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return BinarySearch(arr, 0, pivot - 1, key);

    return BinarySearch(arr, pivot + 1, n - 1, key);
}

int main()
{
    int arr[] = {40, 50, 10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int key = 10;
    int key = 40;
    int idx = SearchArrayRotated(arr, n - 1, key);
    cout << idx << endl;
    return 0;
}

/* 
Time Complexity: O(log n). 
Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
Space Complexity:O(1), No extra space is required.

*/