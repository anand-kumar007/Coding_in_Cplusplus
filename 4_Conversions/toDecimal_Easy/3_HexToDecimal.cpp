/*
Enter Hex Number : 1a3
419
Enter Hex Number : ab3
2739

*/
#include <iostream>
#include <cmath>
using namespace std;

int HexadecimalToDecimal(string s);

//second way
int HexToDecimal(string s);
int getDigit(char ch) ;

int main()
{
    string HexNum;
    cout << "Enter Hex Number : ";
    cin >> HexNum;

    // cout << HexToDecimal(HexNum) << endl;
    cout << HexadecimalToDecimal(HexNum) << endl;
    return 0;
}

int HexadecimalToDecimal(string s)
{
    int size = s.size();
    int x=1;
    int ans=0;

    // s[i]-'A' + 10 bcz A~= 10 and so on;
    // from character to digit conversion

    for(int i= size-1; i>=0; i--)
    {
        if(s[i]>='0' && s[i]<='9')
        ans = ans + x*(s[i]-'0');
        
        else if(s[i]>='a'&&s[i]<='f')
        ans = ans + x*(s[i]-'a'+10);
        
        else if(s[i]>='A' && s[i]<='F')
        ans = ans + x*(s[i]-'A'+10);

        x = x*16;
    }


    return ans;
}






// =============================================
// second way

int HexToDecimal(string s)
{
    int ans=0,digit=0;
    char ch;
    int i=0;
    while (s.length() > 0)
    {
         ch = s[s.length()-1];
         digit = getDigit(ch);

         ans = ans + digit*pow(16,i);
         i++;

         //for resizing the string   
         s.resize(s.length()-1);
    }

    return ans;
}

int getDigit(char ch)
{
    int digit=0;
    switch(ch)
    {
        case '1': 
            digit = 1;
            break;
        case '2':
            digit = 2;
            break;
        case '3':
            digit = 3;
            break;
        case '4':
            digit = 4;
            break;
        case '5':
            digit = 5;
            break;
        case '6':
            digit = 6;
            break;
        case '7':
            digit = 7;
            break;
        case '8':
            digit = 8;
            break;
        case '9':
            digit = 9;
            break;
        case 'a':
        case 'A':
            digit = 10;
            break;
        case 'b':
        case 'B':
            digit = 11;
            break;
        case 'c':
        case 'C':
            digit = 12;
            break;
        case 'd':
        case 'D':
            digit = 13;
            break;
        case 'e':
        case 'E':
            digit = 14;
            break;
        case 'f':
        case 'F':
            digit = 15;
            break;
    }

    return digit;
}

