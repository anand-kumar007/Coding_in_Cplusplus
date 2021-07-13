/*
===================
Enter Num : 7632
1DD0

Enter Num : 763
2FB
===================
*/
#include<iostream>
using namespace std;
string DecimalToHex (int);
void RecursiveDtoH (int);

int main()
{
    int Num;
    cout<<"Enter Num : ";
    cin>>Num;

    // RecursiveDtoH(Num) ;
    cout << DecimalToHex(Num) << endl;
    return 0;
}

string DecimalToHex(int num)
{
    string ans="";
    int x=1; //base
    while(x <= num)
    {
        x *= 16;
    }  
    x /= 16;

    while(x>0)
    {
        int quotient = num/x;
        num = num - quotient*x;
        x /=16;

        //appending to the end
        if(quotient <= 9)
          ans = ans + to_string(quotient);
        else 
        {
            char ch = quotient - 10 + 'A';
            ans.push_back(ch);
        }  
    }

    return ans;

}

void RecursiveDtoH(int num)
{
    if (num <= 0)
        return;
    RecursiveDtoH(num/16);

    int digit = num %16;
    if(digit >=0 && digit<=9 )
    cout << digit;
    else 
    cout<<char(digit-10+'A');
}