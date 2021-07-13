// Move all negative numbers to beginning and positive to end with constant extra space

//approach is simple to use partition process of quick sort

#include<bits/stdc++.h>
using namespace std;

void doTheTask(int arr[],int n);

int main()
{
    int n;
    cout<<"size : "; cin>>n;
    int arr[n];

    cout<<"enter "<<n<<" numbers : ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    doTheTask(arr,n);

    cout<<"the required form of arry is : "<<endl;
    
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

    return 0;

}

void doTheTask(int arr[], int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            if(i != j)
            {
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }

}

// 10,20,-12,-23,90,-233