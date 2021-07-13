#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"enter row and cols : ";
    cin>>n>>m;
    int arr[n][m];

    for(int i=0; i<n; i++)
    {
    for(int j=0; j<m;j++)
    {
    cin>>arr[i][j];
    }
    }

    cout<<"matrix is : "<<endl;

    for(int i=0; i<n; i++)
    {
    for(int j=0; j<m;j++)
    {
    cout<<arr[i][j]<<' ';
    }
    cout<<endl;
    }
    return 0;
}