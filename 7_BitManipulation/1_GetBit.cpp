/*
Get the bit at it index 

we know 1<<i 
left shift the index with 1 and then take
its and(&) with the number(n) if that is = 0
then output is zero else the output is 1

ex: n=5 (0101)
    i=2  ==> (left shift 1 by i times 1<<i)
        0001--on left shift by 2
        0100

        take the and of it with n
        0101 & 0100
        ---------
        00101
        since index start from left (0,1,2)
        @ 2 index we have 1 in this case of 
        n=5,i=2
*/

#include<iostream>
using namespace std;
void DecimalToBinary(int n);
void GetBit(int, int);

int main()
{
    int n,pos;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<"full binary form of number is : "<<endl;
    DecimalToBinary(n);
   
    cout<<"enter the ith index which you want : ";
    cin>>pos;


    GetBit(n,pos);
    return 0;
}

void GetBit(int n, int pos)
{
    //shift the 1 by i times and take and of that with the number
    //if that comes 0 means bit is zero else it is 1
    if ((n & (1 << pos)) == 0)
    {
        cout << "Bit is 0" << endl;
    }
    else
        cout << "Bit is 1" << endl;
        
        
    return ;     
}

void DecimalToBinary(int n)
{
  //simple procedure of
  //get the highest power of 2 and quotient num/x x denotes highest power
  //keep decreasing the x=x/2 and num -= quotient*x; etc

//   since 22 = 10110 can be written as 16X1 + 8X0 + 4X1 + 2X1 + 1(2^0)x0 ==> 10110

  unsigned long long int ans=0;
  int x=2; //base in this case
  
  while(x<n)
  {
      x *=2;
  }
  x = x/2;

  int quotient=0;
  while(x>0)
  {
      quotient = n/x;
      n -= quotient*x;
      ans = ans*10 + quotient;

      x= x/2;
      
  }

  cout<<"Binary form is : "<<ans<<endl;

  return ;
}