#include <iostream>
#include <climits>
using namespace std;
void SelectionSort(int arr[], int n);

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SelectionSort(arr, n);

    cout << "After Sorting !!\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

void SelectionSort(int arr[], int n)
{
    //sort the array in ascending order

    //like arranging people in a queue of prayer
    //take smallest and put @ beginning

    int minIndex;

    for (int i = 0; i < n-1; i++)
    {
        minIndex = i;

        for(int j=i+1; j<n;j++)
        {
            if(arr[j] <arr[minIndex])
            minIndex = j;
        }

        swap(arr[minIndex],arr[i]);
    }

}

// O(N^2) for all cases so not recommended at all
// not stable also other two (Bubble and Insertion are stable)
// and have O(N^2) as best time complexity Bubble being optimized 
// with noswap flag