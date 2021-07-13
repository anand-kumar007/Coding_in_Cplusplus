/*
search for the element in a more effective manner.
elements of the matrix are sorted L-R ascending
and T-B ascending order as well.
*/

/*
1. start from top right corner
2. compare if equal
    else
    if element>target
        //mover left
    else
    //move down 
*/

#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"enter rows and cols : ";
    cin>>n>>m;
    int A[n][m];

    for(int i=0; i<n; i++)
    {
    for(int j=0; j<m;j++)
    cin>>A[i][j];
    }
    int target;
    cout<<"enter the target element : ";
    cin>>target;
    bool flag = false;

    //apply the optimized search method
    int r = 0;
    int c = m-1;
    while(r<n && c>=0)
    {
        if(A[r][c] == target)
        {
            cout<<"found @ "<<"A["<<r<<"]"<<"["<<c<<"]"<<endl;
            flag = true;
            break;
        }
        else if(A[r][c] > target)
        {
            //move left
            c--;
        }
        else 
        {
            //move down
            r++;
        }
    }

    if(!flag) cout<<"No such element !";

    return 0;

}


//similar you can start from right-bottom as well
// and move accordingly

//above solution gives O(N) time complexity

