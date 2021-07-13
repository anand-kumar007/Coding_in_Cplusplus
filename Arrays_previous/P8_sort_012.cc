//sort an array consitiong of 0,1,2 only with O(n) time and O(1) space complexity.

// simple algorithm it is : count 0,1,2 and then append those many numbers of each of them.

#include<bits/stdc++.h>
using namespace std;

void sort_012(int arr[], int );
int main()
{
    int n;
    cout<<"size : "; cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    sort_012(arr,n);

    cout<<"sorted array is :";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}

void sort_012(int arr[], int n)
{
    int c0,c1,c2;
    c0 = c1 = c2 = 0;

    for(int i=0; i<n; i++)
    {
        switch (arr[i])
        {
        case 0 :
            c0++;
            break;
        case 1 :
            c1++;
            break;
        case 2 :
            c2++;
            break;        
        
        default:
            break;
        }
    }

    //now store the those many 0,1,2 in array
    int i=0;
    while(c0 >0)
    {
        arr[i++]=0;
        c0--;
    }

    while (c1 > 0)
    {
        arr[i++] = 1;
        c1--;
    }

    while (c2 > 0)
    {
        arr[i++] = 2;
        c2--;
    }


}
