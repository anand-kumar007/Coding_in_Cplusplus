
/*
peak element is one which is greater than it's left and right
immediate elements


*/

#include <iostream>
using namespace std;

int findPeak(int arr[], int n, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if ((mid != 0 && arr[mid] >= arr[mid - 1]) && (mid != n - 1 && arr[mid] >= arr[mid + 1]))
        return mid;

    //check if elements in left half are greater than our mid
    if ((mid > 0 && arr[mid - 1] > arr[mid]))
        return findPeak(arr, n, start, mid - 1);

    else
        return findPeak(arr, n, mid + 1, end);
}

int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    // int arr[] = {10,20,15,2,23,90,67};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = n - 1;

    int peak = findPeak(arr, n, start, end);

    cout << "peak element : " << arr[peak];

    return 0;
}