/*
 Euclid algorithm for finding gcd
 42,18
 41-24 = 18(rem)
 24 - 18 = 6
 (a=b) (b=rem)
 6 - 6 = 0 (stop)

 return a when b!=0
 a would be the gcd at last
better way would be to use % sign instead of -
 */

#include <iostream>
using namespace std;

int gcd1(int a1, int b1)
{
    int a = max(a1, b1);
    int b = min(a1, b1);
    int rem = 0;

    while (b != 0)
    {
        // rem = a - b;
        rem = a % b;
        a = b;
        b = rem;
    }

    //last remaining greatest num is ans; 
    return a;
}

/*
22 6
22 - 6 =16
16 - 6 = 10
10 - 6 = 4
6 - 4 = 2
4 - 2 = 2
2 - 2 = 0
*/

int main()
{
    int a, b;
    cout << "Enter two numbers : ";
    cin >> a >> b;

    cout << "gcd is : " << gcd1(a, b);
    cout << "gcd is : " << gcd2(a, b);
    return 0;
}

int gcd2(int a1,int b1)
{
    int gcd=1;
    for (int i = 1; i <= a1 && i <= b1; ++i)
    {
        // Checks if i is factor of both integers
        if (a1 % i == 0 && b1 % i == 0)
            gcd = i;
    }

    return gcd;
}

/*===========================================
Time complexity

gcd(a, b) it suffices to call gcd(a, b, 1) = gcd(a, b). 
Greatest common divisor using binary Euclidean algorithm. 
Thus, the time complexity is O(log(a · b)) = O(log a + b) = O(log n). 
And for very large integers, O((log n)2), since each arithmetic operation can be done in O(log n) time.

*/