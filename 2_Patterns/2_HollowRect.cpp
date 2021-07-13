/*
=================================
enter rows and cols : 5 6
enter symbol : $
$$$$$$
$    $
$    $
$    $
$$$$$$

==================================
*/

#include<iostream>
using namespace std;

int main()
{
    int rows, cols;
    char symbol;

    cout<<"enter rows and cols : ";
    cin>>rows>>cols;

    cout<<"enter symbol : ";
    cin>>symbol;

    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=cols; j++)
        {
            if(i==1 || i==rows || j==1 || j==cols)
            {
                cout<<symbol;
            }
            else 
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}