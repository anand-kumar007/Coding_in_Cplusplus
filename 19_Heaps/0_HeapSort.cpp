
/* 
Heap sort 
Get a better explanation on programiz if you couldn't grasp
the idea better here 

*/

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);

        heapify(arr, n, largest);
    }

    return;
}

void HeapSort(int arr[], int n)
{
    //first build the maxheap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        // Heapify root element to get highest element at root again
        //n=i(passing bcz size gets reduced evertime)
    }

    return;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {10, 20, 5, 4, 22, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, n);

    printArr(arr, n);

    return 0;
}

/* 
since an array represenataion can be understood
as representation of a complete binary tree

[1,12,9,5,6,10]

        1
       /  \
      12   9
    /  \  /
   5   6  10

   the first non-leaf of this binary tree would be
   at (n/2-1) where n here is 6 so @ 2
   ie 9
   we start heapifying from there and go uptil 0

   so we'll get a complete maxheap 


   =====HeapSort========
   [12,6,10,5,1,9]

            12
           /  \
          6    10
        /  \   / 
       5    1  9
   we first remove the top(ie arr[0] with arr[n-1] ie 9 here)
   then apply heapify to root(newlyformed) so as to preserve maxheap

   keep on repating this step until we get size=0

   */