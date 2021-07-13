#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int N;
    cout<<"Enter last Number :";
    cin>>N;

    int i=2;
    //apply logic
    while(i <= N)
    {
        int flag = false;
        // an indicator 
        for(int j=2; j<=sqrt(i); j++)
        {
            if(i%j ==0)
            {
                flag = true;
                break;
            }
        }

        if(flag == false)
        cout<<i<<" ";

        i++;
    }

    return 0;
}