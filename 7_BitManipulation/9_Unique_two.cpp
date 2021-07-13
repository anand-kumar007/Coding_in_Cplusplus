/*
find two unique numbers in array which contains all other
elements repeating twice except those two unique numbers.
*/

#include<iostream>
using namespace std;

int GetBit(int n, int pos)
{
    if ((n & (1 << pos)) ==0)
        return 0;
    else 
        return 1;
}

void Unique2(int arr[], int n)
{
    int xorsum = 0;
    for(int i=0; i<n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    //now xorsum have xor of two unique numbers in it
    //find the rightmost position where bit is 1
    //by taking and of number with 1
    int oldxorsum = xorsum;
    int getbit =0;
    int pos=0;
    while(getbit !=1)
    {
        getbit = xorsum & 1;
        pos++;
        //like decreasing the last bit everytime
        xorsum = xorsum >>1;
    }

    //cz this would have become one more than our required position
    pos = pos -1; 

    //find xorsum of only those numbers which have bit 1 @ this pos only
    //this will give one of the unique numbers as other unique numbers
    // doesn't have its bit set to 1 at that position
    int newxorsum = 0;

    for(int i=0; i<n; i++)
    {
        if(GetBit(arr[i],pos)==1)
        {
            newxorsum = newxorsum ^ arr[i];
        }
    }

    //newxorsum have one of the unique numbers now
    // to find the other one xor it with old xorsum

    oldxorsum = oldxorsum ^ newxorsum;

    cout<<"\nTwo unique numbers in array are : "<<newxorsum<<' '<<oldxorsum<<endl;

    return ;
}

int main()
{
    int arr[] = {1,2,3,4,5,4,72,3,2,1};
    Unique2(arr,10);
    return 0;
}
