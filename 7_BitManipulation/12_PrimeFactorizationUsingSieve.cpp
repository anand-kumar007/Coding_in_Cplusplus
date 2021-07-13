

#include <iostream>
using namespace std;

void SievePrimeFactor(int maxm);
int main()
{
    int n = 10;
    SievePrimeFactor(n);
    return 0;
}


void SievePrimeFactor(int num)
{
    int spf[100] = {0};
    for (int i = 2; i <= num; i++)
        spf[i] = i;

    for (int i = 2; i <= num; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= num; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    //recursively print the spf

    while (num != 1)
    {
        cout << spf[num] << " ";
        //divide the num by its spf and print that spf
        num /= spf[num];
    }
    return;
}