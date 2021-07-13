/*
a,n,a,n,d,\0 --> last character will be null character
Enter the sentence : Hi I am Ram
Hi
---
H i
*/
#include<iostream>
using namespace std;
void checkNULL();
void TakeInput();

int main()
{

    // checkNULL();
    TakeInput();


    char ch[30];
    cout<<"Enter the sentence : ";
    cin>>ch;

    cout<<ch; //would just print the first word
    
    for(int i=0; ch[i] !='\0'; i++) 
    cout<<ch[i]<<' ';
    
    return 0;
}

void checkNULL()
{
    char ch[100]="apple";
    int count;
    int i=0;
    while(ch[i] !='\0')
    {
        cout<<ch[i]<<endl;
        i++;

    }

    cout<<"ar ch["<<i<<"]"<<" NULL value encountered !!"<<endl;

    return ;
}

void TakeInput()
{
    int n;
    cout<<"enter size of word : ";
    cin>>n;

    char ch[n+1];
    cout<<"enter the word : ";
    fflush(stdin);
    cin.getline(ch,n);  //just pass the n only
    
    fflush(stdin);

    cout<<"your word is : ";
    for(int i=0; i<=n; i++)
    cout<<ch[i]<<" ";
    
    cout<<endl;
    return ;
}