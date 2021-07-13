//return the kth largest element in an array

//expected time complexity is O(nlogn)
//use heap or merge or quicksort


#include<bits/stdc++.h>
using namespace std;

void findKthLargest(int arr[], int k, int n);

int main()
{
    int size;
    cout<<"enter size of array : "; cin>>size;
    int arr[size];
    cout<<"enter the "<<size<<" elements : ";
    for(int i=0; i<size; i++)
    cin>>arr[i];

    sort(arr,arr+size);  //time complexity is O(nlogn)
    // sort(arr,arr+size,greater<int>()); //for sorting in descending order

    int k;
    cout<<"enter the kth value : ";
    cin>>k;
    findKthLargest(arr,k,size);

    return 0;
}

void findKthLargest(int arr[],int k, int n)
{
    cout<<k<<"th largest elements is : "<<arr[k-1];
}


void BubbleSort(int arr[], int n)
{
    //idea is to compare two adjacent elements and after each
    //pass largest/smallest element is placed at its right position.

    bool flag=false;
    for(int i=0; i<n; i++)
    {
        //each time largest element will be at the rightmost side
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j+1]< arr[j])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                // this step ensures the time complexity of best case to be linear
                flag = true;
            }
        }
        //if no swapping is done by the inner loop
        if(flag==false)
        return;
    }
}
//BubbleSort is stable.


//======================================================================
// sorting the deck of playing cards firstone will require no comparison.

//40,20,60,.....initial condition of the array let's say
void InsertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i]; //key here is next coming card
        int j= i-1;   //arr[j] is our previously sorted card 

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
    
}

//it is stable and best time complexity is also linear.

// ======================================================

//like selecting the minimum element and placing it at the right position

//40,20,30,-10,12,...................
void SelectionSort(int arr[], int n)
{   
     //j is going from i+1 
     for(int i=0; i<n-1; i++)
     {
         int minIndex = i;

         for(int j=i+1; j<n; j++)
         {
             if(arr[j]<arr[minIndex])
             {
                 minIndex = j;
             }
         }

        //ie soted element was there
        if(i != minIndex)
        {
         //swap the minium element with the arr[i]
         int temp = arr[i];
         arr[minIndex] = arr[i];
         arr[i] = temp;
        }
     }
}

// It is not stable and best time complexity is also O(N^2)  