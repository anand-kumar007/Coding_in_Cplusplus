/*
quick sort method
select and element(called pivot element) place it at its right position
recurse the method for left and right elements to it.

Divide and Conquer method
*/

#include <iostream>
using namespace std;
void QuickSort(int arr[], int l, int r);
int Partition(int arr[], int l, int r);

int main()
{
    int arr[] = {10, 23, -232, -3, 21, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    cout << "sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivotIndex = Partition(arr, l, r);

        //recurse for left and right half
        QuickSort(arr, l, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, r);
    }
}

int Partition(int arr[], int l, int r)
{
    int pivot = arr[r]; //let us assume
    int i = l - 1;      //will point to last smallest element than pivot

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            if (i != j)
                swap(arr[i], arr[j]);
        }
    }
    //now i points to last smallest element than pivot

    swap(arr[i + 1], arr[r]); //arr[r] is pivot element

    return i + 1;
    //returned the index of pivot element's right position
}

/*
Although the worst case time complexity of QuickSort is O(n2) 
which is more than many other sorting algorithms like Merge Sort and Heap Sort, 
QuickSort is faster in practice, because its inner loop can be 
efficiently implemented on most architectures, and in most 
real-world data. QuickSort can be implemented in different 
ways by changing the choice of pivot, 
so that the worst case rarely occurs for a given type of data. 
However, merge sort is generally considered better when data is 
huge and stored in external storage. 

==============
best and avg case time complexity is O(nlogn)
default implementation is not stable but we can make it stable as we have done above

it is inplace 

As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function calls but not for manipulating the input. 

 
*/