//program to cyclic rotate an array

#include<bits/stdc++.h>
using namespace std ;

void rotate(int arr[],int);
void rotateByK(int arr[], int, int);

int main()
{
    int n;
    cout<<"size : "; cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter K : ";
    cin>>k;

    //k>0 is considered
    if(k==1)
    rotate(arr,n);
    else
    rotateByK(arr,n,k);
     
    if(k==1) 
    {
    cout<<"rotated array by one is : "<<endl;
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    }

    else {
    cout << "rotated array by K is : " << endl;
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    }

    return 0;
}

void rotate(int arr[], int n)
{
    //for cyclic rotation by one
    int temp =arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[0] = temp;

    //-- 1,2,3,4,5 ===> 5,1,2,3,4
}

//-- 10,20,30,40,50 ===>30,40,50,10,20
void rotateByK(int arr[], int n, int k)
{
    //for cyclic rotation by k
    while(k>0)
    {
        //code for one rotation
        int temp = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[0] = temp;
        k--;
    }
}

/*  ANOTHER APPROACH :

We can use two pointers, say i and j which point to first and last element of array respectively. As we know in cyclic rotation we will bring last element to first and shift rest in forward direction, so start swaping arr[i] and arr[j] and keep j fixed and i moving towards j.  Repeat till i is not equal to j.

j being pointing to the n-1th element.
*/


// rotate by one element 
void rotateUsing2Pointers(int arr[],int n)
{
    int i=0, j=n-1;

    while(i!=j)
    {
        swap(arr[i],arr[j]);
        i++;
    }

    // 1,2,3,4,5 ===> 5,2,3,4,1 ===> 5,1,3,4,2 ===>5,1,2,4,3 ===> 5,1,2,3,4(answer)
}
