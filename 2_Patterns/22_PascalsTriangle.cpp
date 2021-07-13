/*
=========================
enter N : 5
    1    
   1 1   
  1 2 1  
 1 3 3 1 
1 4 6 4 1
========================
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        //spaces
        for(int j=1; j<n-i; j++)
        cout<<" ";

        //elements
        int coff=1;
        for(int j=0; j<=i; j++)
        {
            if(j==0 || i==0)
            coff = 1;
            else 
            {
                coff = (coff * (i-j+1))/j ;
            }

            cout<<coff<<" ";
        }
        cout<<endl;
    }
    return 0;
}