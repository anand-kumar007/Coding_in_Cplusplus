/*
==============================
a = 1110
b = 1011
----------
   11001  -->answer
==============================*/

#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        ans = ans * 10 + lastDigit;
        n /= 10;
    }
    return ans;
}
int addBinaryNumbers(int, int);

int main()
{
    int a, b;
    cout << "enter two binary numbers : ";
    cin >> a >> b;

    cout << addBinaryNumbers(a, b);

    return 0;
}

int addBinaryNumbers(int a, int b)
{
    int prevCarry = 0;
    int ans = 0;
    //while there is digits in any of a and b
    while (a > 0 && b > 0)
    {
        //three conditions one by one
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {
            if (prevCarry == 0)
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
            else
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
        }
        else
        {
            //third case 1 1

            ans = ans * 10 + prevCarry;
            prevCarry = 1;
        }

        //update the a and b
        a /= 10;
        b /= 10;
    }

    //check for a is remaining or b is remaing
    while (a > 0)
    {
        if (prevCarry == 1)
        {
            if (a % 2 == 0)
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
            else
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
        }
        else
        {
            //if preVcarr == 0
            ans = ans * 10 + (a % 10); //the last digit
        }

        a /= 10;
    }

    //for the b
    while (b > 0)
    {
        if (prevCarry == 1)
        {
            if (b % 2 == 0)
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
            else
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
        }
        else
        {
            //if preVcarr == 0
            ans = ans * 10 + (b % 10); //the last digit
        }

        b /= 10;
    }
    //if length were equal and we are left with carry only
    if (prevCarry == 1)
    {
        ans = ans * 10 + 1;
    }

    //reverse it
    ans = reverse(ans);

    //finally return the answer
    return ans;
}

// three cases 00,10,01 accordingly carry is generated and
// added based on carry which is previously set
