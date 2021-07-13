#include <iostream>
#include <climits>
using namespace std;
void InsertionSort(int arr[], int n);

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    InsertionSort(arr, n);

    cout << "After Sorting !!\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

void InsertionSort(int arr[], int n)
{
    //sort the array in ascending order

    //like first card no need to check
    // next card comes compare it with firstly arranged cards and insert appropriately

    // initially 20 then 40 and 15 comes analyze 

    int j;
    int key;

    for(int i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && key<arr[j])
        {
            //shift the elements 
            arr[j+1] = arr[j];
            j--;
        }

        //insert the element at its right position
        arr[j+1]= key;
    }
}


