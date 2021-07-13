
#include <iostream>
using namespace std;
int FirstOccurance(int arr[], int n, int key, int i)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    //just incrementing the index to seach
    return FirstOccurance(arr, n, key, i + 1);
}
int LastOccurance(int arr[], int n, int key, int i)
{
    if (i == n)
        return -1;

    int restArr = LastOccurance(arr, n, key, i + 1);

    if (restArr != -1)
        return restArr;

    //if we could not find our key in rest array
    //then just checking for the ith index

    //But here first we are checking in the rest array
    if (arr[i] == key)
        return i;

    return -1;
}
int main()
{
    int arr[7] = {4, 90, 1, 2, 5, 2, 7};
    cout << FirstOccurance(arr, 7, 2, 0) << endl;
    cout << LastOccurance(arr, 7, 2, 0) << endl;
    return 0;
}
