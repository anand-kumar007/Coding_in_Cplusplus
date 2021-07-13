// given an array of N integers including 0
//task is to find the smallest positive number missing in  array

// constrains
// 1<=N<=10^6
// 10^-6 <=arr[i]<<10^6

// time complexity is lesser than O(N2)
// you may use extra space upto O(N)

#include<iostream>
using namespace std;
void findFirstMissing(int arr[],int);

int main()
{
    int n;
    cout<<"enter N ";
    cin>>n;
    int arr[n]; 
    for(int i=0; i<n; i++)
    cin>>arr[i];

    findFirstMissing(arr,n);
    return 0;
}

void findFirstMissing(int arr[], int n)
{
    const int N = 1e6;
    bool check[N];
    for(int i=0; i<N; i++)
    check[i] = false;

    for(int i=0; i<n; i++)
    {
        if(arr[i] >=0)
        {
            check[arr[i]]=true;
        }
    }

    for(int i=0; i<N; i++)
    {
        if(check[i]==false)
        {
            cout<<"first Positive Int missing is : "<<i;
            break;
        }
    }
    
    return ;
}