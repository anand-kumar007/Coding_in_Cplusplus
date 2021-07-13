#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    char symbol;

    cout<<"Enter total rows and columns : ";
    cin>>rows>>cols;
    cout<<"Enter symbol : ";
    cin>>symbol;

    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=cols; j++)
        cout<<symbol<<" ";

        cout<<endl;
    }

    
    return 0;
}