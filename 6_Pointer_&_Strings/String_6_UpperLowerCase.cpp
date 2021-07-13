/*
you are given a string and task is to convert the string
completely into lower case and uppercase both using two functions
separately both.

Note : 'a'= 65 and 'A'=97
string is alwayas passed as value not as reference

==============
OR
if you don't know the ascii values of 'a' and 'A'
find their differece 'a'-'A' ==32
means small a is 32 ahead than capital

*/

#include<iostream>
#include<algorithm>
using namespace std;

void Upper(string);
void Lower(string);
void ChangeIntoUpper(string);
void ChangeIntoLower(string);
void InBuitIntoUpper(string s1);

int main()
{
    string s1;
    cout<<"enter the string : ";
    getline(cin,s1);
    fflush(stdin);
    // Lower(s1);
    // Upper(s1);
    // ChangeIntoUpper(s1);
    // ChangeIntoLower(s1);
    InBuitIntoUpper(s1);

    cout<< "\n------\n"<< s1;
    return 0;
}

void Lower(string s1)
{
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] = s1[i] - 65 + 'a';
        }
    }
    cout << "In Lowercase : " << s1;

    return;
}

void Upper(string s1)
{
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]>='a' && s1[i]<='z')
        {
            s1[i] = s1[i] - 97 +'A'; 
        }
    }
    cout<<"In uppercase : "<<s1;

    return ;
}


void ChangeIntoUpper(string s1)
{
    // we now 'a'-'A'==32
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]>='a' && s1[i]<='z')
        {
            //move it back by 32
            s1[i] = s1[i] - 32;
        }
    }
    cout<<"In Uppercase : "<<s1<<endl;

    return ;
}

void ChangeIntoLower(string s1)
{
    // we now 'a'-'A'==32
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            //move it forward by 32
            s1[i] = s1[i] + 32;
        }
    }
    cout << "In Lowercase : " << s1 << endl;

    return;
}

void InBuitIntoUpper(string s1)
{
    transform(s1.begin(),s1.end(),s1.begin(), ::toupper);

    // pass full string begin to end then convert it from begin end into upppercase
    cout<<s1<<endl;
}