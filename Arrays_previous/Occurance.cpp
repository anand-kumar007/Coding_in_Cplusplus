// occurance of x in a sorted array with O(logn) time complexity
// #include <map>
// #include <set>
// #include <iterator>
// #include <algorithm>
// #include <cstring>
// #include <climits>
// #include <cstdlib>
// #include <cstdio>
#include<iostream>
using namespace std;
int getI(int arr[], int low, int high, int n, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return getI(arr, mid + 1, high, n, x);
        else
            return getI(arr, low, mid - 1, n, x);
    }
    else
        return -1;
}

int getJ(int arr[], int low, int high, int n, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == n || arr[mid + 1] > x) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return getJ(arr, low, mid - 1, n, x);
        else
            return getJ(arr, mid + 1, high, n, x);
    }
    else
        return -1;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = getI(a, 0, n - 1, n, x);
        if (i == -1)
            cout << "-1";
        else
        {
            int j = getJ(a, 0, n - 1, n, x);
            cout << j - i + 1;
        }
        cout << endl;
    }
    return 0;
}