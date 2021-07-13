/*
check given word is palindorome or not
NITIN
ANNA
ABBA
RACECAR
*/
#include<iostream>
using namespace std;

int main()
{
    // int n;
    char ch[100];
    cout<<"enter the word : ";
    cin>>ch;
    
    int size =0;
    while(ch[size] !='\0')
    { 
        size++;
    }

 

    //check if the word is palindrom or not
    bool check=true;

    for(int i=0; i<size/2; i++)
    {
        if(ch[i] != ch[size-1-i])
        {
            check = false;
            break;
        }
    }

    if(check) cout<<"Palindrome";
    else
    cout<<"Not a Palindrome";
    return 0;
}