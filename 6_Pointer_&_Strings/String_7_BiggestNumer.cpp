/*
Given a numeric string task is to find the
biggest number formed out of it.
"52143" --> output
"54321"
*/

#include<iostream>
#include<algorithm>
using namespace std;
void InsertionSort(string s);
int main()
{
    string s;
    cout<<"enter a numeric string : ";
    getline(cin,s);

    //just sort the string
    InsertionSort(s);

    // use the inbuit function sort
    //for sorting in descending order additional parameter needs to be passed
    sort(s.begin(),s.end(),greater<int>());
    cout<<"Biggest Number formed is : "<<s<<endl;
    return 0;
}
void InsertionSort(string s)
{
    char curr;
    for(int i=1; i<s.length(); i++)
    {
        curr = s[i];
        int j = i - 1;
        //for descending order sorting just we have reversed the condition
        while(j>=0 && curr > s[j])
        {
                s[j+1] = s[j];      
                j--;
        }

        s[j+1] = curr;
    }

    cout<<"\n Biggeest Number is : "<<s<<endl;

    return ;
}