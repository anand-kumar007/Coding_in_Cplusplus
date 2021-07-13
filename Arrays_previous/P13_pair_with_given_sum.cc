// {1,5,7,-1} ==> sum = 6 ==>o/p = 2 pairs
// {1,1,1,1}  ==> sum = 2 ==>o/p = 3! or 6 pairs

// expected time complexity is O(N)

#include <bits/stdc++.h>
using namespace std;
int findPairs(int arr[], int,int);
int main()
{
    int n;
    cout << "size : ";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " numbers : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum=0;
    cout<<"sum : ";
    cin>>sum;

    cout << "total pairs are : " << findPairs(arr, n,sum) << endl;

    return 0;
}

int findPairs(int arr[], int n, int sum)
{
    //naive approach traverse each element and find if there
    //is another element which form the given sum

    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j] == sum)
            {   
                cout<<arr[i]<<" "<<arr[j]<<",";
                count++;
            }
        }
    }

    cout<<endl;
    return count;
}

//O(N) complexity algorithm

// Create a map to store frequency of each number in the array. (Single traversal is required)

// In the next traversal, for every element check if it can be combined with any other 
// element (other than itself!) to give the desired sum. Increment the counter accordingly.

// After completion of second traversal, we’d have twice the required value
//  stored in counter because every pair is counted two times. Hence divide count by 2 and return.



int countPairs(int arr[],int n, int sum)
{
    unordered_map<int, int> m;

    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int twice_count = 0;

    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++)
    {
        twice_count += m[sum - arr[i]];

        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (sum - arr[i] == arr[i])
            twice_count--;
    }

    // return the half of twice_count
    return twice_count / 2;
}