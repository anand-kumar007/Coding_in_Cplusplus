#include<iostream>
using namespace std;

int countOccurance(int arr[], int, int);
int BinarySearch(int arr[], int ,int,int,int);

int main()
{
    int n;
    cout<<"enter size : "; cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements :";

    for(int i=0;i<n; i++)
    cin>>arr[i];
    int key;
    cout<<"enter the element to search : ";
    cin>>key;

    
    // cout<<"index is :"<<BinarySearch(arr,n,0,n-1,key);

    cout << "occurance of element is : " << countOccurance(arr, key, n);
    return 0;
}

//binary search algorithm

int BinarySearch(int arr[], int n, int start, int last, int key)
{
   
   if(last < start)
   return -1;

    int mid = (start + last)/2;

    if(arr[mid]==key)
     return mid;

    else if(arr[mid]<key)
      return BinarySearch(arr,n,mid+1,last,key); 
    else 
    return BinarySearch(arr,n,start,mid-1,key);
}

int countOccurance(int arr[], int key, int n)
{
    int index = BinarySearch(arr,n,0,n-1,key);

    if(index== -1)
    return -1;

    int count = 1;
    //count elements on left side
    int left = index -1;
    while(left>=0 && arr[left]==key)
    {
        count++;
        left--;
    }

    //count elements on right side
    int right = index +1;
    while(right<n && arr[right]==key)
    {
        count++;
        right++;
    }

    return count;
}

//this algo gives time complexity of O(logn+ count) where count is number of occurance

//this is for sorted array
//for unsorted simply the linear search algorithm would work with O(n) time complexity.