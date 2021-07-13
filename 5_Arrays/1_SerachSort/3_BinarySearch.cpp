#include <iostream>
#include <climits>
using namespace std;
int BinarySearch(int arr[], int n, int key);

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "enter key to search : ";
    cin >> key;

    int index = BinarySearch(arr, n, key);

    if (index != -1)
        cout << "element found at index : " << index;
    else
        cout << "Element is not present in array ";

    return 0;
}

int BinarySearch(int arr[], int n, int key)
{
    int index = -1;

    int start=0, end = n-1;
    int mid;

    while(start <= end)
    {
        mid = (start+end)/2;
        if(arr[mid] == key)
        {
            index = mid;
            break;
        }
        else if(arr[mid] > key)
        {
            end = mid-1;
        }
        else 
        start = mid+1;
    }

    return index;
}