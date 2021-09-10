
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool brute_force(vector<int> arr, int target);
bool Two_pointer_approach(vector<int> arr, int target);

void merge(vector<int> arr, int start, int mid, int end);
void merge_sort(vector<int> arr, int start, int end);

int main()
{
    vector<int> arr = {1, 3, 6, 7, 9, 12};
    // int target = 24;
    int target = 5;

    // bool ans = brute_force(arr, target);
    bool ans = Two_pointer_approach(arr, target);

    if (ans)
    {
        cout << "Yes exists!!" << endl;
    }
    else
    {
        cout << "Doesn't exists!!" << endl;
    }
    return 0;
}

bool brute_force(vector<int> arr, int target)
{
    int flag = false;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }

    return flag;
}

bool Two_pointer_approach(vector<int> arr, int target)
{
    int n = arr.size();

    merge_sort(arr, 0, n - 1); //now the array is sorted
    // sort(arr.begin(), arr.end());

    bool flag = false;
    int curr = 0;
    // 1, 3, 6, 7, 9, 12
    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;

        while (low < high)
        {
            curr = arr[i] + arr[low] + arr[high];

            if (curr == target)
            {
                flag = true;
                break;
            }

            else if (curr < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        if (flag)
            break;
    }

    return flag;
}

void merge(vector<int> arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    //since we have two sorted arrays just merge them

    vector<int> arr1(n1);
    vector<int> arr2(n2);
    // copy two subarrays

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[i + start];
    }
    for (int i = 0; i < n1; i++)
    {
        arr2[i] = arr[i + mid + 1];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < arr.size())
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }

    while (j < n2)
    {
        arr[k++] = arr2[j++];
    }

    return;
}
void merge_sort(vector<int> arr, int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}