//print all the subarray of an array

#include<iostream>
using namespace std;
void PrintSubarrays(int arr[],int n);
int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }

    PrintSubarrays(arr,n);
    return 0;
}
void PrintSubarrays(int arr[], int n)
{

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k=i; k<=j; k++)
              cout<<arr[k]<<" ";
               
              cout<<endl;
        }
    }
}