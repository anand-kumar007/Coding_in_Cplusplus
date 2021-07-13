/*
Given a sorted array find the if there exist 
a pair in array which can form the sum
*/
#include <iostream>
using namespace std;
void PairSum(int arr[], int n, int sum);

int main()
{
    int arr[8] = {2, 4, 7, 11, 14, 16, 20, 21};
    PairSum(arr, 8, 318);
    return 0;
}

void PairSum(int arr[], int n, int sum)
{
    //using the two pointer algorithm
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int curr = arr[s] + arr[e];
        if (curr == sum)
        {
            cout << arr[s] << " " << arr[e] << endl;
            break;
        }
        else if (curr > sum)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    if (s > e)
        cout << "not found !" << endl;

    return;
}