#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter N : ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" array elements : ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int minNo = INT_MAX;
    int maxNo = INT_MIN;

    for(int i=0; i<n; i++)
    {
        // if(arr[i]<minNo)
        //     minNo = arr[i];
        // if(arr[i]>maxNo)
        //     maxNo = arr[i];   

        //using built in functions
        minNo = min(minNo, arr[i]);
        maxNo = max(maxNo, arr[i]);
    }

    cout << "maximum element is : " << maxNo;
    cout << "\nminimum element is : " << minNo;
    return 0;
}