#include <iostream>
#include <climits>
using namespace std;
int LinearSearch(int arr[], int n, int key);

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout<<"enter key to search : ";
    cin>>key;

    int index = LinearSearch(arr,n,key);

    if(index >=0 && index <n)
    cout<<"element found at index : "<<index;
    else 
    cout<<"Element is not present in array ";
    
    return 0;
}

int LinearSearch(int arr[],int n,int key )
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {

            return i;
        }
    }

    return -99;
}