/*
given a sum = sum find subarray with sum equal to it.
enter N : 5
1 2 3 7 5                                             s>
enter sum : 12
start 1
end 3
*/
#include <iostream>
#include <climits>
using namespace std;
void FindSubarray(int arr[], int, int);

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cout << "enter sum : ";
    cin >> sum;

    FindSubarray(arr, n, sum);
    return 0;
}

void FindSubarray(int arr[], int n, int sum)
{
    //i,j are two pointers
    int i=0, j=0, st=-1,en=-1, currSum=0;

    while(j<n && currSum+arr[j] >=sum)
    {
        currSum += arr[j];
        j++;
    }
    //now currsum is either greater or lesser
    if(currSum == sum)
    {
        cout << "start " << i<<endl;
        cout << "end " << j;
        return ;
    }

    while(j<n)
    {
        //add arr[j] to currsum
        currSum += arr[j]; 

        while(currSum > sum)
        {
            currSum -= arr[i];
            i++;
        }  

        if(currSum == sum)
        {
            st = i;
            en = j;
            break;
        }
        j++;
    }

    cout << "start " << st << endl;
    cout << "end " << en<< endl;
}
    
   

//using two pointer algorithm we can make it O(N)