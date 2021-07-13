// {1,2,3,5,6,8,7}  ===> 4 is missing from 1-8 
//find the missing number


//approach is find sum of first n natural number 
// and subtract sum of the array from that to get number


#include<bits/stdc++.h>
using namespace std;
int findMissing (int arr[], int);
int main()
{
    int n;
    cout<<"size : "; cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" numbers : ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    cout<<"missing is : "<<findMissing(arr,n)<<endl;

    return 0;

}

int findMissing(int arr[], int n)
{
    // int sumOfNaturalNumbers = ((n+1)*(n+2))/2 ;

    // int total= 0;

    // for(int i=0; i<n; i++)
    // total += arr[i];

    // return sumOfNaturalNumbers - total;


    // avoiding integer overflow
    int i, total = 1;

    for (i = 2; i <= (n + 1); i++)
    {
        total += i;
        total -= arr[i - 2];
    }
    return total;
}