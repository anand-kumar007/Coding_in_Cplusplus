#include<iostream>
using namespace std;

void RotateArray(int a[], int , int);
int main()
{
    int t,d,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        int a[n];

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        RotateArray(a,n,d);
        cout<<"\n";
    }

    return 0;
}

void RotateArray(int arr[], int N,int d)
{
    int count = d;
    int temp = 0;
    while (count > 0)
    {
        temp = arr[0];
        for (int i = 0; i < N - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[N - 1] = temp;
        count--;
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}