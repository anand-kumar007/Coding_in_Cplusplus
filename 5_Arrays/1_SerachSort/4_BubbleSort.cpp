#include <iostream>
#include <climits>
using namespace std;
void BubbleSort(int arr[], int n);

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BubbleSort(arr, n);

    cout << "After Sorting !!\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

void BubbleSort(int arr[], int n)
{
    bool noswap = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                noswap = true;
            }
        }

        //after first iteration maxm will be 
        //placed at its right postion
        //so till n-i-1 only
        if (i == 0)
        {
            cout << arr[n - 1] << endl;
        }
        if (!noswap)
            return;
    }

    cout << "\n------------\n";
}


// using noswap condition best case complexity become O(N) 
// like Insertion sort
// avg and worst are still O(n^2)
/*
Bubble sort is a stable algorithm. (selection is unstable) 
(insertion is stable)

A sorting algorithm is said to be stable 
if two objects with equal keys appear in 
the same order in sorted output as they 
appear in the input array to be sorted.
*/

/*  IN SHORT   */
/*
    best case O(N) rest case O(N ^ 2)--->Bubble      | stable
    best case O(N) rest case O(N ^ 2)--->Insertion   | stable
    best case O(N^2) rest case O(N ^ 2)--->Selection | unstable
*/