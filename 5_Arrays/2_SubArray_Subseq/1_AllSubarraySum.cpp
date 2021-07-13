//find some of all the subarrays 
// and output some of each subarray

#include<iostream>
using namespace std;
int FindSum(int arr[],int n);

int main()
{
    int n;
    cout<<"Enter N : ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements :\n";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    cout<<"sum of all subarray is : "<<FindSum(arr,n);
    return 0;
}

int FindSum(int arr[], int n)
{
    int current;
    int total=0;

    for(int i=0; i<n; i++)
    {
        current=0;
        for(int j=i; j<n; j++)
        {
            current += arr[j];
            cout<<current<<" ";
            total += current;
        }
        cout<<"\n";
    }
    cout<<"------";
    return total;
}
