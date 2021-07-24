/*
Merge sort Time complexity O(nlog(n))
Auxiliary Space: O(n)
===========================
enter array size : 8
enter array elements : 6 3 9 5 2 8 7 1
sorted arrys is : 1 2 3 5 6 7 8 9 
============================
*/

#include <iostream>
using namespace std;
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);

int main()
{
    int n;
    cout << "enter array size : ";
    cin >> n;
    int arr[n];
    cout << "enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //since l and r so n-1 must be passed
    mergeSort(arr, 0, n - 1);

    cout << "sorted arrys is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // int mid = (l + r) / 2;
        int mid = l + (r - l) / 2;  //avoids int overflow

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        //merge finally
        merge(arr, l, mid, r);
    }

    //done
    return;
}
void merge(int arr[], int l, int mid, int r)
{
    int n1 = (mid - l + 1);
    int n2 = (r - mid);

    int a[n1], b[n2]; //temp arrays

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[i + l];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[i + mid + 1];
    }

    //apply the merging algo
    int i = 0, j = 0;
    int k = l;

    while ((i < n1) && (j < n2))
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    // remaining items
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }

    //done

    return;
}

/*
drawback of merge sort
======================
Slower comparative to the other sort algorithms for smaller tasks.

Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.

It goes through the whole process even if the array is sorted.

*/