/*
find the unique number from an array where 
all the elements are present thrice except the one
which is unique
*/
#include <iostream>
using namespace std;
void getUnique(int arr[], int n);
int SetBit(int n, int pos)
{
    return (n | (1 << pos));
}
bool getBit(int n, int pos)
{
    return ((n & 1 << pos) != 0);
}

int main()
{
    int arr[13] = {1, 2, 3, 1, 2, 3, 9454, 1, 2, 3, 1, 2, 3};
    getUnique(arr, 10);
    return 0;
}

void getUnique(int arr[], int n)
{
    int res = 0;
    int sum = 0;
    //form an array of 64 size or run the loop for 64
    for (int i = 0; i < 64; i++)
    {
        //check what numbers have their bit set to 1 @ith position
        //count their value
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }

        //check if the sum is divisible by 3
        //if not set the bit of ans to 1 there
        if (sum % 3 != 0)
        {
            res = SetBit(res, i);
        }

        //refresh the sum variable
        sum = 0;
    }

    cout << "Number is : " << res;
}


//64 bit size array considering the int is of size N