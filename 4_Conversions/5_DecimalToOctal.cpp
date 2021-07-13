/*

Decimal Number is : 87
Enter Octal Number : 127

Decimal Number is : 482
Enter Octal Number : 742

*/
#include <iostream>
#include <cmath>
using namespace std;
void RecursiveDtoOct(int num);
int DecimalToOctal(int );
int DecimalToOctalForAll(int num);

int main()
{
    int DecNum;
    cout << "Enter Decimal Number : ";
    cin >> DecNum;

   
    // cout<<DecimalToOctal(DecNum);
    // RecursiveDtoOct(DecNum);
    cout << DecimalToOctalForAll(DecNum);

    return 0;
}

void RecursiveDtoOct(int num)
{
    if (num <= 0)
        return;
    RecursiveDtoOct(num / 8);
    cout<<num%8;
}

// generic soln
int DecimalToOctalForAll(int num)
{
    int ans = 0;
    int x = 1; //base
    while (x <= num)
    {
        x *= 8;
    }
    x /= 8;

    while (x > 0)
    {
        int quotient = num / x;
        num = num - quotient * x;
        x /= 8;

        //appending to end
        ans = ans * 10 + quotient;
    }

    return ans;
}

// brute force way but will work
int DecimalToOctal(int num)
{
    int OctNum = 0;
    int rem = 0;
    while (num > 0)
    {
        rem = num % 8;
        OctNum = OctNum * 10 + rem;
        num /= 8;
    }

    //here the OctNum we've got is reversed of desired so let's reverse it.

    int digit = 0;
    int revOct = 0;
    while (OctNum > 0)
    {
        digit = OctNum % 10;
        revOct = revOct * 10 + digit;
        OctNum /= 10;
    }
    cout << "Ocatal Number is : ";

    return revOct;
}


