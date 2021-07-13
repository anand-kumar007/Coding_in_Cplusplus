//Factorial of 100 has 158 digits. It is not possible to store 
// these many digits even if we use long long int.

/*
Following is a simple solution where we use an array to 
store individual digits of the result. 
The idea is to use basic mathematics for multiplication.

Note: Factorials of n > 20 can't be stored even in a 64 - bit long variable. 
Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. 
can handle big integers, but we need to write additional code in C/C++ to handle huge values.
*/

#include<iostream>
using namespace std;

void factorial(int);
void BigFactorial(int);
int multiply(int arr[], int res_size, int x);
int main()
{
    int n;
    cout<<"number : "; cin>>n;
    
    cout<<n<<"! = ";
    // factorial(n);

    BigFactorial(n);

    return 0;
}

void BigFactorial(int n)
{
    int res_arr[300];
    res_arr[0]= 1;
    int res_size = 1;

    int x=2;
    while(x <= n)
    {
        res_size = multiply(res_arr,res_size,x);
        x++;

    }

    //print the factorial

    for(int i= res_size-1; i>=0; i--)
    {
        cout<<res_arr[i];
    }

}

int multiply(int arr[], int res_size, int x)
{
    int carry =0;

    for(int i=0; i<res_size; i++)
    {
        int product = arr[i]*x + carry;

        //update arr[i] and carry
        arr[i] = product%10;
        
        carry = product/10;

    }

    //store the remaining digits of carry into the arr
    while(carry>0)
    {
        arr[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }

    return res_size;
}
/*
void factorial(int num)
{
    long long int temp = 1;
    for(int i=num; i>0; i--)
    {
        temp = temp*i;
    }

    cout<<temp;
}
*/

/*
The following is a detailed algorithm for finding factorial.
factorial(n) 
1) Create an array ‘res[]’ of MAX size where MAX is number of maximum digits in output. 
2) Initialize value stored in ‘res[]’ as 1 and initialize ‘res_size’ (size of ‘res[]’) as 1. 
3) Do following for all numbers from x = 2 to n. 
……a) Multiply x with res[] and update res[] and res_size to store the multiplication result.
How to multiply a number ‘x’ with the number stored in res[]? 
The idea is to use simple school mathematics. We one by one multiply x with every digit of res[]. The important point to note here is digits are multiplied from rightmost digit to leftmost digit. If we store digits in same order in res[], then it becomes difficult to update res[] without extra space. That is why res[] is maintained in reverse way, i.e., digits from right to left are stored.
multiply(res[], x) 
1) Initialize carry as 0. 
2) Do following for i = 0 to res_size – 1 
….a) Find value of res[i] * x + carry. Let this value be prod. 
….b) Update res[i] by storing last digit of prod in it. 
….c) Update carry by storing remaining digits in carry. 
3) Put all digits of carry in res[] and increase res_size by number of digits in carry.
*/