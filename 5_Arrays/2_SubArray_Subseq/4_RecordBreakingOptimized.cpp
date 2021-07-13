//find the count of record breaking days
//and print each record breaking day from the array

// enter N : 8
// 1 2 0 7 2 0 2 2
// output : 2 7 Total count is : 2

#include <iostream>
using namespace std;

void FindRecordBreakingDay(int arr[], int n);

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;
    int arr[n + 1];  //BOOM
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    FindRecordBreakingDay(arr, n);
    return 0;
}

void FindRecordBreakingDay(int arr[], int n)
{
    int counter = 0;
    int mx = -1;
    //max till i
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            counter++;
            cout << arr[i] << " ";
        }
        mx = max(mx, arr[i]);
    }
    cout << "Total count is : " << counter;
}
