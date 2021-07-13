
#include <iostream>
#include <climits>
using namespace std;
void MaxSubArraysum(int arr[], int n);
int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MaxSubArraysum(arr, n);
    return 0;
}
void MaxSubArraysum(int arr[], int n)
{
    int currSum;  //this will hold the sum of each subarry
    // that's why compairing 
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum = 0;
        for (int j = i; j < n; j++)
        {
           currSum += arr[j];
           ans = max(currSum,ans);  
        }
    }

    cout<<ans;
}