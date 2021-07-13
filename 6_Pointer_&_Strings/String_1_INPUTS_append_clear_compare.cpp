#include<iostream>
using namespace std;

int main()
{
    //different ways of declaring the string
    string str1(5,'A');
    //AAAAA is the output
    cout<<str1<<endl;

    string str2 = "Anand";
    cout<<str2<<endl;

    string str3;
    cout<<"enter the string : ";
    getline(cin,str3);

    cout<<str3<<endl;

    //accessing the characters
    cout<<str3[2]<<endl; //will give 3rd character

    // cout<<"HI"+"all"<<endl; one of them should be string object

    cout<<str1+" hadhfk "<<endl;


    // different functions in string
    // 1. appending 
    string s1 ="fam";
    string s2 = "ily";

    s1.append(s2);
    cout<<s1<<endl;

    // modify the content
    s1[0] = 'K';
    cout<<s1;

    //to delete or clear the string content
    s1.clear();

    cout<<s1<<endl;

    cout<<"___"<<endl;
    return 0;
}