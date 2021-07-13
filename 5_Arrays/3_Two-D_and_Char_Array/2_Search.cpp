//search for x in matrix

#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"enter row and cols : ";
    cin>>n>>m;

    int arr[n][m];
    int x;
    cout<<"enter "<<n*m<<" elements : "<<endl;

    for(int i=0; i<n; i++)
    {
    for(int j=0; j<m;j++)
    {
    cin>>arr[i][j];
    }
    }

    cout<<"enter x to be searched : ";
    cin>>x;

    // search in the array
    for(int i=0; i<n; i++)
    {
    for(int j=0; j<m;j++)
    {   
        if(arr[i][j]==x)
        {cout<<"found at index arr["<<i<<"]["<<j<<"]"<<endl;
        return 0;}
    }
    }

    cout<<"not found";
    return 0;
}