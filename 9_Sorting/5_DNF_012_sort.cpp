/*
Dutch national flag
red white blue
0   1      2

used for only 0,1,2 sorting
O(n) time complexity since either mid++,or high--
and initally they were n distant apart

sorted array is :
0 0 0 0 1 1 1 1 1 1 1 2 2 2 2 
*/

#include <iostream>
using namespace std;
void DNF_sort(int arr[], int n);

int main()
{
    int arr[] = {1, 1, 0, 2, 1, 0, 1, 2, 1, 0, 0, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    DNF_sort(arr, n);

    cout << "sorted array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

void DNF_sort(int arr[], int n)
{
    //maintain three pointers
    int low = 0;
    int mid = 0;
    int high = n - 1;

    //once unknown region length = 0 
    //we'll have our array sorted
    //and region is btwn mid and high

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            //if arr[mid] ==2
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    //done
    return;
}

/*
    maintain three pointers

    low = 0;      //starting of ones
    int mid = 0;      //starting of unknown region
    int high = n - 1; //starting of two

*/