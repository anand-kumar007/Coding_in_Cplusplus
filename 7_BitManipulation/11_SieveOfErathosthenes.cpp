/*
sieve of erathesthenos
O(nloglogn) is its time complexity
compared to what is O(n^3/2) in 
brute force method
*/

#include <iostream>
using namespace std;
void SievePrime(int maxm);

int main()
{
    int n = 50;
    SievePrime(n);
    return 0;
}
void SievePrime(int maxm)
{
    int prime[100] = {0};
    // initially let all are prime
    for (int i = 2; i <= maxm; i++)
        prime[i] = 1;

    // mark all multile of smaller 
    // primes and go till maxm
    for (int i = 2; i <= maxm; i++)
    {
        if (prime[i] == 1)
        {
            // all multiple of a prime 
            // will not be prime
            //start from i*i 
            for (int j = i * i; j <= maxm; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    //we have our sieve ready for primes
    for (int i = 2; i <= maxm; i++)
    {
        if (prime[i] == 1)
            cout << i << " ";
    }

    return;
}