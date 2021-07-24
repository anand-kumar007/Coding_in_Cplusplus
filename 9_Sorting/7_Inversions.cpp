/*
count total inversions in an array
ie a[i] > a[j] and i < j then it's an inversion

*/

#include <iostream>
using namespace std;
#define LL long long

LL merge(int arr[], int l, int mid, int r);
LL mergeSort(int arr[], int l, int r);

LL BruteForce(int arr[], int n);

int main()
{
    // int arr[] = {3, 2, 1}; //3

    int arr[] = {3, 6, 9, 5, 2, 8, 7, 1}; //16
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total Inversions are : ";
    // cout << BruteForce(arr, n) << endl;

    cout << mergeSort(arr, 0, n - 1) << endl;

    return 0;
}

LL mergeSort(int arr[], int l, int r)
{
    LL inv = 0;
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }

    return inv;
}

LL merge(int arr[], int l, int mid, int r)
{
    LL inv = 0;

    int n1 = mid - l + 1;
    int n2 = r - (mid + 1) + 1;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[i + l];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[i + mid + 1];
    }

    //apply the merge sort
    int i = 0, j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            //Ok no inversion
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            //There are inversions

            //a[i],a[i+1],a[i+2] etc will also be
            //greater than b[j] since sorted
            inv += (n1 - i);

            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }

    //return the total inversions

    return inv;
}
LL BruteForce(int arr[], int n)
{
    LL inv = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            //since i<j and arr[i] > arr[j]
            if (arr[i] > arr[j])
                inv++;
        }
    }
    //O(N^2) time complexity
    return inv;
}
