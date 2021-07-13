#include<iostream>
#include<cmath>
using namespace std;
bool checkPrime(int );

int main()
{
    int r1,r2;
    cout<<"enter range (r1-r2) : ";
    cin>>r1>>r2;
   
    cout<<"Prime Numbers in range "
        <<r1<<"-"<<r2<<"are : "<<endl;
    
    for(int i=r1; i<=r2; i++)
    {
        if (checkPrime(i))
            cout << i << " ";
    }

    return 0;
}

bool checkPrime(int num)
{
    for(int i=2; i<=sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }

    // loop executes successfully
    return true;
}