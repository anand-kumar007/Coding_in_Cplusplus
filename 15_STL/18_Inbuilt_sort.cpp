
/* 
    inbuilt sorting method
    sort() takes two iterator as arg and one comparator function

    itr1 => statrting index
    itr2 => ending index 
    NOTE : [itr1, itr2)  while sorting

    nlog(n) time complexity for sorting in worst case
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Array()
{
    int arr[] = {1, -4, 34, -29, 4, 20, 300};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort(arr, arr + n);
    // sort(arr, arr + n-3); //leaves last 3 elements
    sort(arr + 2, arr + n); //leaves first 2 elements
    cout << "sorted array : " << endl;

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
void Vector();

int main()
{
    // Array();
    Vector();
    return 0;
}

void Vector()
{
    vector<int> v = {10, -24, 100, 56, 77, 43};
    int n = sizeof(v) / sizeof(v[0]);

    // sort(v.begin(),v.end());
    sort(v.begin(), v.end(), greater<int>()); //descending order
    cout << "sorted vector : " << endl;

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
/*
sort() method is implemented using introsort()

which is a combo of three sorting techniques viz.
1. quicksort()
2. heapsort()
3. insertionsort()

starts with quicksort and if depth of recursion turns out
to be more it shifts to heap sort 
and if no of elements are less (quite low) it uses insertion sort

*/