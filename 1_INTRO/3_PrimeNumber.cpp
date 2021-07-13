#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int number;
    cout << "Enter the number : ";
    cin >> number;

    bool flag = false;
    //check the conditions

    // for (int i = 2; i < number / 2; i++)
        for (int i = 2; i <= sqrt(number); i++)
        {
            if (number % i == 0)
            {
                flag = true;
                break;
            }
        }

    if (flag)
        cout << "Non Prime";

    else
        cout << "Prime";
    return 0;
}

/*

If a number n is not a prime, it can be factored into two factors a and b:

n = a * b
Now a and b can't be both greater than the square root of n, since then the product a * b would be greater than sqrt(n) * sqrt(n) = n. So in any factorization of n, at least one of the factors must be smaller than the square root of n, and if we can't find any factors less than or equal to the square root, n must be a prime.

*/
/*
n = a*b ; a smaller factor ,b larger factor
1<=a<=b<N;

so two cases:
1. a=b
n = a*b so n = a^2;

2. a<b
n= a*b since b is bigger than a so n>a*a
i,e
n> a^2
and a <= sqrt(n)

/*
smaller factor of n must be <= sqrt(n) 
if it exist its counter larger part will be simply n/a

so just search for the smaller factor of n
which will be in <=sqrt(n)

*/