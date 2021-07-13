//sorting the array

/*
Check if a key is present in every segment of size k in an array.
=================================================================
Given an array arr[] and size of array is n and one another key x, 
and give you a segment size k. The task is to find that the key x 
present in every segment of size k in arr[].

=================================================================
*/
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n);
void SelectionSort(int arr[], int n);
void InsertionSort(int arr[], int n);

void printArray(int arr[], int n);

int main()
{
    int n;
    cout << "enter size : ";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }

//    BubbleSort(arr,n);
   SelectionSort(arr, n);
//    InsertionSort(arr, n);

    printArray(arr,n);
  return 0;
}


void printArray(int arr[], int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
      cout<<arr[i]<<" ";
    }
}


//after each pass largest element would reach at the rightmost position(or leftmost position accordingly)

// that's why we do not consider it further n-1-i;


void BubbleSort(int arr[], int n)
{
    //idea is to compare two adjacent elements and after each
    //pass largest/smallest element is placed at its right position.

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        //each time largest element will be at the rightmost side(ascending order sorting)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                // this step ensures the time complexity of best case to be linear
                flag = true;
            }
        }
        //if no swapping is done by the inner loop
        if (flag == false)
            return;
    }
}
//BubbleSort is stable


// ==================================================================================
//pick the minimumindex and keep swapping(placing at the beginniing) if ascending order

//even in best case selection sort takes O(N^2) comparisons 
//that's why not preffered and no swap() in best case

//worst case
//  O(N) swaps and O(N^2) comparisons so overall time complexity is O(N^2)


// average case O(N^2) comparisons and O(N) swaps.

//selection sort is inPlace bcz no extra array is taken.

// not stable (bcz similar elements will get changed in their relative order and hence not stable)

//ex: 5(a),2,3,5(b),1  ==> 1,2,3,5(b),5(a) ==> relative order has been changed btwn 5 so not stable.

//we can make it stable by doing changes to code. but by default it is not stable
void SelectionSort(int arr[],int n)
{
    for(int i=0; i<n-1;i++)
    {
     //considering the Ith element to be minimum;   
     int minIndex=i;
     
     for(int j=i+1; j<n; j++)
     {
         if(arr[j]<arr[minIndex])
         {
             minIndex = j;
         }
     }

     //swap
     if(i != minIndex)
    { 
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    }

    //your array is sorted
}

// like deck of cards arrangement
void InsertionSort(int arr[],int n)
{
    //when first card comes no need of comparison
    //so start with 1 directly

    for(int i=1; i<n; i++)
    {
        int key = arr[i];

        //insert arr[i] into sorted sequence arr[0...j-1]
        int j= i-1;

        while(j>=0 && arr[j]>key)
        {
            //say 40 is at [0] and key(next) is 20;
            //shift them
            arr[j+1] = arr[j];
            j--;
        }
        //now insert key at correct position

        arr[j+1] = key;

    }

    //selection sort gives O(N) timeComplexity in best case. bcz O(n-1) comparisons and O(1) swaps 

    // worst case O(N^2) swaps and same O(N^2) comparison.

    //stable 5(a),2,3,5(b),1 no change would take place
    //==> 2,3,5(a),5(b),1==> etc no change 

    //InPlace no extra array was needed.
}