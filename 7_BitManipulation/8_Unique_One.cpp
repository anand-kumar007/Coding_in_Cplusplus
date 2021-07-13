/*
find the unique number in array where each element is 
present twice except one
*/
#include<iostream>
using namespace std;

int UniqueUsingBit(int arr[],int n)
{
    int xorsum = 0;
    for(int i=0; i<n; i++) {
       xorsum = xorsum ^ arr[i];
    }

    return xorsum;
}
int main()
{
    int arr[] = {1,2,3,4,1,2,3};
    
    cout << UniqueUsingBit(arr, 7) << endl;

    return 0;
}
