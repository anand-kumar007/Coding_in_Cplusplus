//in an arrya display the frequency of each element in that array
#include<iostream>
using namespace std;

void displayFrequency(int arr[],int );
int main()
{
    int n;
    cout<<"enter size :" ;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    displayFrequency(arr,n);
    
    return 0;
}

void displayFrequency(int arr[], int n)
{
    
}