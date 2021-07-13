/*
enter rows : 4
1
22
333
4444
*/

#include<iostream>
using namespace std;

int main()
{
    int rows;
    cout<<"enter rows : ";
    cin>>rows;

    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=i; j++)
        cout<<i;

        cout<<endl;
    }
    
    return 0;
}